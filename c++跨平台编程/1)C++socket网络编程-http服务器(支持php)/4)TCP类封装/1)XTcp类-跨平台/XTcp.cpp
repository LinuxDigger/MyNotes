// Ҫ��סһ��: ͷ�ļ�������Ҫ��������.cpp����!
// ΪʲôҪ����.cpp���ж�������.h������? 
// .h�ļ�����Ǳ�����������,�Ǿ��漰����ʲô?
// ���ڵ�������˵,��ֻҪ֪��.h������.�費��Ҫ֪��.cpp?����Ҫ!
// ����.cpp���ǿ��԰�����ɶ�̬���ӿ�,��.h�ļ�������Ҫ������
// �����.h���б���windows.h,�Ǿ��п��ܸ���������ɳ�ͻӰ��!
// Ϊʲô����������ɳ�ͻӰ����?
// ��: ����std::bind()�����ռ亯����windows.h�е�::bind()�������ó�ͻ


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "XTcp.h"

#ifdef WIN32
#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#define socklen_t int
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#define closesocket close
#endif // Windows

//#include <thread>
using namespace std;


XTcp::XTcp()
{
#ifdef WIN32
	static bool first = true;
	if (first)
	{
		first = false;
		WSADATA ws;
		WSAStartup(MAKEWORD(2, 2), &ws);
	}
#endif // Windows
}

int XTcp::CreateSocket()
{
	// Linux ��sock�ļ��������������� 1024 , �鿴�ļ������������: ulimit -n , �޸��ļ�����������������: ulimit -n 3000
	sock = socket(AF_INET, SOCK_STREAM, 0); // TCP
	if (-1 == sock)
	{
		printf("create socket failed!\n");   // ��windows���м�������ʧ��, ����ϵͳ��Դռ�ù���ľ��˲Ż�
		                                     // ��Linux�� ��Ϊϵͳ�涨�Ľ��̾���������޵�(���������ֵ1024), �糬����1024�ͺ�ʧ��
	}
	return sock;
}

bool XTcp::Bind(unsigned short port)
{
	if (sock <= 0) CreateSocket();

	sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(port); // �����ֽ��� ת �����ֽ��� (���)
	saddr.sin_addr.s_addr = htonl(0);

	if (0 != ::bind(sock, (sockaddr*)&saddr, sizeof(saddr)))
	{
		printf("bind port %d failed!\n", port);
		return false;
	}
	printf("bind port %d success!\n", port);
	listen(sock, 10);
	return true;
}

XTcp XTcp::Accept()
{
	XTcp tcp;
	sockaddr_in caddr;
	socklen_t len = sizeof(caddr);
	int client = accept(sock, (sockaddr*)&caddr, &len); // ��ȡ�ͻ���socket, ������
	if (client <= 0) return tcp;
	printf("accept client %d \n", client);
	tcp.ip = inet_ntoa(caddr.sin_addr);
	tcp.port = ntohs(caddr.sin_port);
	tcp.sock = client;
	printf("client ip is %s, port is %d\n", tcp.ip.c_str(), tcp.port);
	return tcp;
}

void XTcp::Close()
{
	if (sock <= 0) return;
	closesocket(sock);
}

int XTcp::Recv(char* buf, int bufsize)
{
	return recv(sock, buf, bufsize, 0);
}

int XTcp::Send(const char* buf, int bufsize)
{
	int sendedSize = 0;
	while (sendedSize != bufsize)
	{
		int len = send(sock, buf + sendedSize, bufsize - sendedSize, 0);
		if (len <= 0) break;
		sendedSize += len;
	}
	return sendedSize;
}


XTcp::~XTcp()
{
}

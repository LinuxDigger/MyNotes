// Windows���벽��:
// ��Ŀ����>>������>>����>>����������>> "ws2_32.lib;..."
// C/C++>>Ԥ������>>Ԥ����������>> "WIN32;..."

// Linux���벽��:
// make main

#ifdef WIN32
#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#define closesocket close
#endif // Windows

#include <stdio.h>

int main(int argc, char** argv)
{
#ifdef WIN32
	WSADATA ws;
	WSAStartup(MAKEWORD(2, 2), &ws);
#endif // Windows

	// Linux ��sock�ļ��������������� 1024 , �鿴�ļ������������: ulimit -n , �޸��ļ�����������������: ulimit -n 3000
	int sock = socket(AF_INET, SOCK_STREAM, 0); // TCP
	if (-1 == sock)
	{
		printf("create socket failed!\n");   // ��windows���м�������ʧ��, ����ϵͳ��Դռ�ù���ľ��˲Ż�
		return -1;                           // ��Linux�� ��Ϊϵͳ�涨�Ľ��̾���������޵�(���������ֵ1024), �糬����1024�ͺ�ʧ��
	}
	
	unsigned short port = 8080;
	if (argc > 1) port = atoi(argv[1]);

	sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(port); // �����ֽ��� ת �����ֽ��� (���)
	saddr.sin_addr.s_addr = htonl(0);
	
	if (0 != bind(sock, (sockaddr*)&saddr, sizeof(saddr)))
	{
		printf("bind port %d failed!\n", port);
		return -2;
	}
	printf("bind port %d success!\n", port);
	listen(sock, 10);

	sockaddr_in caddr;
	socklen_t len = sizeof(caddr);
	int client = accept(sock, (sockaddr*)&caddr, &len); // ��ȡ�ͻ���socket, ������
	printf("accept client %d \n", client);
	const char* ip = inet_ntoa(caddr.sin_addr);
	unsigned short cport = ntohs(caddr.sin_port);
	printf("client ip is %s, port is %d\n", ip, cport);

	char buf[1024] = {0};
	int recvlen = recv(client, buf, sizeof(buf) - 1, 0);
	printf("recv %s \n", buf);
	closesocket(client);

	// �ͻ��˲���: telnet 192.168.163.131 8080
	
	//closesocket(sock);
	getchar();
	return 0;
}
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
	
	closesocket(sock);
	getchar();
	return 0;
}
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
#define closesocket close
#endif // Windows

#include<iostream>
#include<stdlib.h>
using namespace std;

int main(int argc, char** argv)
{
#ifdef WIN32
	WSADATA ws;
	WSAStartup(MAKEWORD(2, 2), &ws);
#endif // Windows

	// Linux ��sock�ļ��������������� 1024 , �鿴�ļ������������: ulimit -n , �޸��ļ�����������������: ulimit -n 3000
	for (int i = 0; i<2000; i++)
	{
		int sock = socket(AF_INET, SOCK_STREAM, 0); // TCP
		if (-1 == sock)
		{
			cout << "create socket failed!\n";   // ��windows���м�������ʧ��, ����ϵͳ��Դռ�ù���ľ��˲Ż�
			return -1;                           // ��Linux�� ��Ϊϵͳ�涨�Ľ��̾���������޵�(���������ֵ1024), �糬����1024�ͺ�ʧ��
		}
		cout << "["<<sock<<"]";
		closesocket(sock);
	}




	system("pause");
	return 0;
}
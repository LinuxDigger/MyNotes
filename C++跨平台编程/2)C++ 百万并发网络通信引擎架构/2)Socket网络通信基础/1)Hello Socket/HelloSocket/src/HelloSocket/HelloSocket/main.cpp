#include <iostream>

#ifdef _MBCS
	#define _CRT_SECURE_NO_WARNINGS
	#define WIN32_LEAN_AND_MEAN  // ���#include <WinSock2.h> �������ض��������
	
	#include <Windows.h>
	#include <WinSock2.h>
	
	#pragma comment(lib, "ws2_32.lib")
#endif

using namespace std;

int main()
{
	WORD ver = MAKEWORD(2,2);
	WSADATA dat;
	WSAStartup(ver, &dat);
	// -start


	// -end
	WSACleanup();

	system("pause");
	return 0;
}
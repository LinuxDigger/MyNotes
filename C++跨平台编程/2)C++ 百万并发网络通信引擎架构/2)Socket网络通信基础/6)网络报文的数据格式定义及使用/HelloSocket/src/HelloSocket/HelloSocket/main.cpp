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
	//--------------
	//-- ��Socket API�������׵�TCP�ͻ���
	// 1 ����һ��socket
	// 2 ���ӷ����� connect
	// 3 ���շ�������Ϣ recv
	// 4 �ر��׽��� closesocket
	//-- ��Socket API��������TCP������
	// 1 ����һ��socket
	// 2 bind �����ڽ��ܿͻ������ӵ�����˿�
	// 3 listen ��������˿�
	// 4 accept �ȴ����ܿͻ�������
	// 5 send ��ͻ��˷���һ������
	// 6 �ر��׽���closesocket
	//--------------
	WSACleanup();

	system("pause");
	return 0;
}
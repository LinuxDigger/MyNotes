#include <iostream>
#include <stdexcept>

#ifdef _MBCS
#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN  // ���#include <WinSock2.h> �������ض��������
#define _WINSOCK_DEPRECATED_NO_WARNINGS // inet_ntoa()��ʱ����

#include <Windows.h>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")
#endif

using namespace std;

enum CMD
{
	CMD_LOGIN,
	CMD_LOGOUT,
	CMD_ERROR
};
struct DataHeader
{
	short dataLength;  // ���ݳ���
	short cmd;
};
struct Login
{
	char username[32];
	char password[32];
};
struct Logout
{
	char username[32];
};
struct LoginResult
{
	char result[32];
};
struct LogoutResult
{
	char result[32];
};


int main()
{
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	WSAStartup(ver, &dat);

	try {
		//--------------
		//-- ��Socket API��������TCP������
		// 1 ����һ��socket �׽���
		SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		
		// 2 bind �����ڽ��ܿͻ������ӵ�����˿�
		sockaddr_in _sin;
		_sin.sin_family = AF_INET;
		_sin.sin_port = htons(9000); // host to net unsigned short
		_sin.sin_addr.s_addr = INADDR_ANY;// inet_addr("0.0.0.0");
		if (SOCKET_ERROR == bind(sock, (sockaddr*)&_sin, sizeof(_sin)))
		{
			throw runtime_error("ERROR:bind(),�󶨶˿�ʧ��!!\n");
		}
		
		// 3 listen ��������˿�
		if (SOCKET_ERROR == listen(sock, 5))
		{
			throw runtime_error("ERROR:listen(),��������˿�ʧ��!!\n");
		}

		// 4 accept �ȴ����ܿͻ�������
		sockaddr_in clienAddr;
		int addrlen = sizeof(clienAddr);
		SOCKET _cSock = INVALID_SOCKET;

		_cSock = accept(sock, (sockaddr*)&clienAddr, &addrlen);
		if (INVALID_SOCKET == _cSock)
		{
			throw runtime_error("ERROR:accept(),���յ���Ч�Ŀͻ���SOCKET!!\n");
		}
		cout << "�����ӿͻ���IP:" << inet_ntoa(clienAddr.sin_addr)
			 << " �˿�:" << clienAddr.sin_port << endl;
		char recvBuf[128] = {0};
		while(true)
		{ 
			DataHeader header = {};
			// 5 ���շ�����������
			int recvlen = recv(_cSock, (char*)&header, sizeof(DataHeader), 0);
			if (recvlen <= 0)
			{
				cout << "�ͻ������˳�, �������!" << endl;
				break;
			}
			cout << "�յ�����:" << header.cmd << " ���ݳ���:" << header.dataLength << endl;
			switch (header.cmd)
			{
				case CMD_LOGIN: {
					Login login;
					recv(_cSock, (char*)&login, sizeof(Login), 0);
					// �����ж��û������Ƿ���ȷ�Ĺ���
					LoginResult res = {"��½�ɹ�!"};
					send(_cSock, (const char*)&header, sizeof(DataHeader), 0);
					send(_cSock, (const char*)&res, sizeof(LoginResult), 0);
					break;
				}
				case CMD_LOGOUT: {
					Logout logout;
					recv(_cSock, (char*)&logout, sizeof(Logout), 0);
					LogoutResult res = {"�˳��ɹ�!"};
					send(_cSock, (const char*)&header, sizeof(DataHeader), 0);
					send(_cSock, (const char*)&res, sizeof(LogoutResult), 0);
					break;
				}
				default:
				{
					header.cmd = CMD_ERROR;
					header.dataLength = 0;
					send(_cSock, (const char*)&header, sizeof(DataHeader), 0);
					break;
				}
			}
		}

		// 8 �ر��׽���closesocket
		closesocket(sock);

		//--------------
	}
	catch (const exception &e)
	{
		cerr << "Get exception : " << e.what() << endl;
	}
	
	WSACleanup();
	system("pause");
	return 0;
}
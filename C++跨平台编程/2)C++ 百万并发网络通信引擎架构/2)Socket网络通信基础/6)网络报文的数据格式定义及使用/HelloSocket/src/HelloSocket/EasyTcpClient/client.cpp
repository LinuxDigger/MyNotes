#include <iostream>
#include <stdexcept>

#ifdef _MBCS
#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN  // ���#include <WinSock2.h> �������ض��������
#define _WINSOCK_DEPRECATED_NO_WARNINGS // inet_ntoa()��inet_addr()��ʱ����

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
		//-- ��Socket API�������׵�TCP�ͻ���
		// 1 ����һ��socket
		SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
		if (INVALID_SOCKET == sock)
		{
			throw runtime_error("ERROR:socket(),����SOCKETʧ��!!\n");
		}

		// 2 ���ӷ����� connect
		sockaddr_in _sin;
		_sin.sin_family = AF_INET;
		_sin.sin_port = htons(9000);
		_sin.sin_addr.s_addr = inet_addr("127.0.0.1");
		if (SOCKET_ERROR == connect(sock, (sockaddr*)&_sin, sizeof(_sin)))
		{
			throw runtime_error("ERROR:connect(),���ӷ�����ʧ��!!\n");
		}

		while (true)
		{
			// 3 ������������
			char cmdBuf[128] = { 0 };
			cin >> cmdBuf;
			// 4 ������������
			if (0 == strcmp(cmdBuf, "exit"))
			{
				break;
			}
			else if (0 == strcmp(cmdBuf, "login"))
			{
				DataHeader header = {sizeof(Login), CMD_LOGIN};
				Login login = {"Dejan","123456"};
				send(sock, (const char*)&header, sizeof(DataHeader), 0);
				send(sock, (const char*)&login, sizeof(Login), 0);
				// ���շ��������ص�����
				DataHeader recvHead;
				LoginResult ret;
				int recvHeadLen = recv(sock, (char*)&recvHead, sizeof(DataHeader), 0);
				int recvResLen = recv(sock, (char*)&ret, sizeof(LoginResult), 0);
				if (recvHeadLen > 0 && recvResLen > 0)
				{
					cout << "LoginResult:" << ret.result << endl;
				}
			}
			else if (0 == strcmp(cmdBuf, "logout"))
			{
				DataHeader header = { sizeof(Logout), CMD_LOGOUT };
				Logout logout = { "Dejan"};
				send(sock, (const char*)&header, sizeof(DataHeader), 0);
				send(sock, (const char*)&logout, sizeof(Logout), 0);
				// ���շ��������ص�����
				DataHeader recvHead;
				LogoutResult ret;
				int recvHeadLen = recv(sock, (char*)&recvHead, sizeof(DataHeader), 0);
				int recvResLen = recv(sock, (char*)&ret, sizeof(LogoutResult), 0);
				if (recvHeadLen > 0 && recvResLen > 0)
				{
					cout << "LogoutResult:" << ret.result << endl;
				}
			}
			else 
			{
				cout << "��֧�ָ�����, ����������!" << endl;
				continue;
			}

		}

		// 7 �ر��׽��� closesocket
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
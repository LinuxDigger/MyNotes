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
	CMD_LOGIN_RESULT,
	CMD_LOGOUT,
	CMD_LOGOUT_RESULT,
	CMD_ERROR
};
struct DataHeader
{
	short dataLength;  // ���ݳ���
	short cmd;
};
struct Login :public DataHeader
{
	Login()
	{
		dataLength = sizeof(Login);
		cmd = CMD_LOGIN;
	}
	char username[32] = { 0 };
	char password[32] = { 0 };
};
struct Logout :public DataHeader
{
	Logout()
	{
		dataLength = sizeof(Logout);
		cmd = CMD_LOGOUT;
	}
	char username[32] = { 0 };
};
struct LoginResult :public DataHeader
{
	LoginResult()
	{
		dataLength = sizeof(LoginResult);
		cmd = CMD_LOGIN_RESULT;
	}
	char result[32] = "��½�ɹ�!";
};
struct LogoutResult :public DataHeader
{
	LogoutResult()
	{
		dataLength = sizeof(LogoutResult);
		cmd = CMD_LOGOUT_RESULT;
	}
	char result[32] = "�˳��ɹ�!";
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
				Login login;
				strcpy(login.username, "Dejan");
				strcpy(login.password, "123456");
				send(sock, (const char*)&login, sizeof(Login), 0);
				// ���շ��������ص�����
				LoginResult ret;
				int recvResLen = recv(sock, (char*)&ret, sizeof(LoginResult), 0);
				if (recvResLen > 0)
				{
					cout << "LoginResult:" << ret.result << endl;
				}
			}
			else if (0 == strcmp(cmdBuf, "logout"))
			{
				Logout logout;
				strcpy(logout.username, "Dejan");
				send(sock, (const char*)&logout, sizeof(Logout), 0);
				// ���շ��������ص�����
				LogoutResult ret;
				int recvResLen = recv(sock, (char*)&ret, sizeof(LogoutResult), 0);
				if (recvResLen > 0)
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
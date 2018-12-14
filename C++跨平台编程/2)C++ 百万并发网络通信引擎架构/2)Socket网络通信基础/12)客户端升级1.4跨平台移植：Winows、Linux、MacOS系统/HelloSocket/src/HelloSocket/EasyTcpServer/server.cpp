#include <iostream>
#include <stdexcept>
#include <vector>

#ifdef _MSC_VER
	#define _CRT_SECURE_NO_WARNINGS
	#define WIN32_LEAN_AND_MEAN  // ���#include <WinSock2.h> �������ض��������
	#define _WINSOCK_DEPRECATED_NO_WARNINGS // inet_ntoa()��ʱ����

	#include <Windows.h>
	#include <WinSock2.h>

	#pragma comment(lib, "ws2_32.lib")

#elif __GNUC__
	#include <sys/types.h>
	#include <sys/socket.h>
	
	#define SOCKET int
#endif

using namespace std;

enum CMD
{
	CMD_LOGIN,
	CMD_LOGIN_RESULT,
	CMD_LOGOUT,
	CMD_LOGOUT_RESULT,
	CMD_NEW_USER_JOIN,
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
struct NewUserJoin :public DataHeader
{
	NewUserJoin()
	{
		dataLength = sizeof(NewUserJoin);
		cmd = CMD_NEW_USER_JOIN;
		sock = 0;
	}
	char sock;
};

vector<SOCKET> g_clients;

int processor(SOCKET _cSock)
{
	// ������
	char szRecv[4096] = { 0 };
	// 5 ���շ�����������
	int recvlen = recv(_cSock, szRecv, sizeof(DataHeader), 0);
	DataHeader *header = (DataHeader*)szRecv;
	if (recvlen <= 0)
	{
		cout << "�ͻ���<Socket:"<< _cSock <<">���˳�, �������!" << endl;
		return -1;
	}
	//if (recvlen >= sizeof(DataHeader))

	cout << "�յ�����:" << header->cmd << " ���ݳ���:" << header->dataLength << endl;

	switch (header->cmd)
	{
		case CMD_LOGIN: {
			recv(_cSock, szRecv + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);
			Login* login = (Login*)szRecv;
			cout << "�յ�����:" << login->cmd << " ���ݳ���:" << login->dataLength << " -- ";
			cout << "��½�û�:" << login->username << " ����:" << login->password << endl;
			// �����ж��û������Ƿ���ȷ�Ĺ���
			LoginResult res;
			send(_cSock, (const char*)&res, sizeof(LoginResult), 0);
			break;
		}
		case CMD_LOGOUT: {
			recv(_cSock, szRecv + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);
			Logout* logout = (Logout*)szRecv;
			cout << "�յ�����:" << logout->cmd << " ���ݳ���:" << logout->dataLength << " -- ";
			cout << "�˳��û�:" << logout->username << endl;
			LogoutResult res;
			send(_cSock, (const char*)&res, sizeof(LogoutResult), 0);
			break;
		}
		default:
		{
			DataHeader header = { 0, CMD_ERROR };
			send(_cSock, (const char*)&header, sizeof(DataHeader), 0);
			break;
		}
	}
}

int main()
{
#ifdef _MSC_VER
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	WSAStartup(ver, &dat);
#endif

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

		
		while(true)
		{ 
			// ������ BSD socket
			fd_set fdRead; // ������(socket) ����
			fd_set fdWrite;
			fd_set fdExp;
			// ����
			FD_ZERO(&fdRead);
			FD_ZERO(&fdWrite);
			FD_ZERO(&fdExp);
			// ��������(socket)���뼯��
			FD_SET(sock, &fdRead);
			FD_SET(sock, &fdWrite);
			FD_SET(sock, &fdExp);

			for (int n = g_clients.size()-1; n >= 0; n--)
			{
				FD_SET(g_clients[n], &fdRead);
			}
			// nfds ��һ������ֵ, ��ָfd_set����������������(socket)�ķ�Χ, ����������
			// ���������ļ����������ֵ+1, ��Windows�������������д0
			timeval t = {1, 0}; // ���� select ������, NULL �� ������
			int ret = select(sock + 1, &fdRead, &fdWrite, &fdExp, &t);
			if (ret < 0)
			{
				cout << "ERROR:select(),�������!\n" << endl;
				break;
			}
			if (FD_ISSET(sock, &fdRead))
			{
				FD_CLR(sock, &fdRead); // ����
				// 4 accept �ȴ����ܿͻ�������
				sockaddr_in clienAddr;
				int addrlen = sizeof(clienAddr);
				SOCKET _cSock = INVALID_SOCKET;

				_cSock = accept(sock, (sockaddr*)&clienAddr, &addrlen);
				if (INVALID_SOCKET == _cSock)
				{
					cout<< "ERROR:accept(),���յ���Ч�Ŀͻ���SOCKET!!"<<endl;
				}
				else 
				{
					for (int n = g_clients.size() - 1; n >= 0; n--)
					{
						NewUserJoin userJoin;
						userJoin.sock = _cSock;
						send(g_clients[n], (const char*)&userJoin, sizeof(NewUserJoin), 0);
					}
					g_clients.push_back(_cSock);
					cout << "�����ӿͻ���IP:" << inet_ntoa(clienAddr.sin_addr)
						<< " �˿�:" << clienAddr.sin_port << endl;
				}
				
			}
			for (int n = 0; n < fdRead.fd_count; n++)
			{
				if (-1 == processor(fdRead.fd_array[n]))
				{
					auto iter = find(g_clients.begin(), g_clients.end(), fdRead.fd_array[n]);
					if (iter != g_clients.end())
					{
						g_clients.erase(iter);
					}
				}
			}
			cout << "��ǰ��������:"<< g_clients.size() << endl;
		}

		for (int n = g_clients.size() - 1; n >= 0; n--)
		{
			closesocket(g_clients[n]);
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
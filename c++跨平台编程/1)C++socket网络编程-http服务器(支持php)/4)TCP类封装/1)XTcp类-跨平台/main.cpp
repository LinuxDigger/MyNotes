// Windows���벽��:
// ��Ŀ����>>������>>����>>����������>> "ws2_32.lib;..."
// C/C++>>Ԥ������>>Ԥ����������>> "WIN32;..."

// Linux���벽��:
// make main

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "XTcp.h"
#include <thread>

class TcpThread
{
public:
	void Main()
	{
		char buf[1024] = { 0 };

		while (true)
		{
			int recvlen = client.Recv(buf, sizeof(buf) - 1);
			if (recvlen <= 0) break;
			buf[recvlen] = '\0';
			if (strstr(buf, "quit") != NULL)
			{
				const char *re = "quit success!\n";
				client.Send(re, strlen(re) + 1);
				break;
			}
			int sendlen = client.Send("ok\n", 4); // "ok" 4 => 4���ֽ�

			printf("recv %s \n", buf);
		}
		client.Close();
		delete this;
	}
	XTcp client;
};

int main(int argc, char** argv)
{
	unsigned short port = 8080;
	if (argc > 1) port = atoi(argv[1]);

	XTcp server;
	server.CreateSocket(); // ��һ�����Բ���
	server.Bind(port);
	
	
	while (true)
	{
		XTcp client = server.Accept();

		TcpThread *th = new TcpThread();
		th->client = client;
		std::thread sth(&TcpThread::Main,th);
		sth.detach();
	}
	server.Close();
	
	// �ͻ��˲���: telnet 192.168.163.131 8080
	
	getchar();
	return 0;
}
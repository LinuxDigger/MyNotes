// Windows���벽��:
// ��Ŀ����>>������>>����>>����������>> "ws2_32.lib;..."
// C/C++>>Ԥ������>>Ԥ����������>> "WIN32;..."

// Linux���벽��:
// make main

#include <iostream>
#include <stdlib.h>
#include <string>
#include <XTcp.h>
#include <thread>
using namespace std;

class XHttpThread
{
public:
	void Main()
	{
		char buf[10000] = {0};
		// ����http�ͻ�������
		int recvLen = client.Recv(buf, sizeof(buf)-1);
		if (recvLen <= 0)
		{
			client.Close();
			delete this;
			return;
		}
		printf("=====recv=============\n%s===================\n", buf);

		// ��Ӧhttp GET����
		// ��Ϣͷ
		string rmsg = "";
		rmsg =	"HTTP/1.1 200 OK\r\n"
				"Server: XHttp\r\n"
				"Content-Type: text/html\r\n"
				"Content-Length: 6\r\n"   // ����Ҫע��: ��������ض������ݾ͸�������ĳ�������!
				"\r\n" // ����
				"0123456789";
		int sendSize = client.Send(rmsg.c_str(), rmsg.size());
		printf("sendsize = %d\n", sendSize);
		printf("============send============\n%s\n================\n", rmsg.c_str());

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

		XHttpThread *th = new XHttpThread();
		th->client = client;
		std::thread sth(&XHttpThread::Main, th);
		sth.detach();
	}
	server.Close();

	// �ͻ��˲���: telnet 192.168.163.131 8080

	getchar();
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
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
#include <regex>
using namespace std;

class XHttpThread
{
public:
	void Main()
	{
		char buf[10000] = {0};
		for(;;) // HTTP1.1 ʵ��һ������
		{ 
			// ����http�ͻ�������
			int recvLen = client.Recv(buf, sizeof(buf)-1);
			if (recvLen <= 0)
			{
				Close();
				return;
			}
			buf[recvLen] = '\0';
			printf("=====recv=============\n%s===================\n", buf);

			//	GET /index.html HTTP/1.1
			//	Host: 192.168.163.131
			//	Connection: keep-alive
			//	Cache-Control: max-age=0
			//	Upgrade-Insecure-Requests: 1
			//	User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36
			//	Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8
			//	Accept-Encoding: gzip, deflate
			//	Accept-Language: zh-CN,zh;q=0.9
		
			string src = buf;
			//   /index.html    /ff
			string pattern("^([A-Z]+?) /([^.]*([.].*)?) HTTP/1");
			regex reg(pattern);
			smatch mas;
			regex_search(src, mas, reg);
			if (mas.size() == 0)
			{
				printf("%s failed!\n", pattern.c_str());
				Close();
				return;
			}
			string type = mas[1]; // GET
			string path = "/"; // /index.html
			path += mas[2];
			string filetype = mas[3];
			if (filetype.size() > 0)
			{
				// ȥ��ǰ׺ǰ��ĵ�'.'
				filetype = filetype.substr(1, filetype.size()-1);
			}
			printf("type:[%s]\npath:[%s]\nfiletype:[%s]", 
				type.c_str(),
				path.c_str(),
				filetype.c_str()
			);
			if (type != "GET") // ���type������GETֱ�Ӳ�����
			{
				printf("Not GET!!\n");
				Close();
				return;
			}
			

			if (path == "/")
			{
				path = "/index.html";
			}
			
			string filepath = "../www" + path;

			if (filetype == "php")
			{
				string cmd = "php-cgi ";
				cmd += filepath;
				cmd += " > ";
				filepath += ".html";
				cmd += filepath;
				//php-cgi ../www/index.php > ../www/index.php.html
				printf("%s\n", cmd.c_str());
				system(cmd.c_str());
			}

			
			FILE *fp = fopen(filepath.c_str(), "rb");
			if (fp == NULL)
			{
				printf("open file %s failed!\n", filepath.c_str());
				Close();
				return;
			}
			// ��ȡ�ļ���С
			fseek(fp, 0, SEEK_END);
			int filesize = ftell(fp);
			fseek(fp, 0, 0);
			printf("file size is %d\n", filesize);

			if (filetype == "php")
			{
				char c = 0;
				//\r\n\r\n
				int headsize = 0;
				while (fread(&c, 1, 1, fp) > 0)
				{
					headsize++;
					if (c == '\r')
					{
						fseek(fp, 3, SEEK_CUR);
						headsize += 3;
						break;
					}
				}
				filesize = filesize - headsize;
			}
			
			char bsize[128] = {0};
			sprintf(bsize, "%d", filesize);

			// ��Ӧhttp GET����
			// ��Ϣͷ
			string rmsg = "";
			rmsg =	"HTTP/1.1 200 OK\r\n"
					"Server: XHttp\r\n"
					"Content-Type: text/html\r\n"
					"Content-Length: " + string(bsize) + "\r\n"   // ����Ҫע��: ��������ض������ݾ͸�������ĳ�������!
					"\r\n"; // ����
					//"0123456789"; // ����
			int sendSize = client.Send(rmsg.c_str(), rmsg.size());
			printf("sendsize = %d\n", sendSize);
			printf("============send============\n%s\n================\n", rmsg.c_str());

			// ��������
			for(;;)
			{
				int len = fread(buf, 1,sizeof(buf), fp);
				if (len <= 0) break;
				int re = client.Send(buf, len);
				if (re <= 0) break;
			}
		}
		Close();
	}

	void Close()
	{
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
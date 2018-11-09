#include "XHttpResponse.h"
#include <string>
#include <regex>
using namespace std;

bool XHttpResponse::SetRequest(std::string request)
{
	string src = request;
	//   /index.html    /ff
	string pattern("^([A-Z]+?) /([^.]*(\\.[a-z]*)?)[?]?(.*?) HTTP/1");
	regex reg(pattern);
	smatch mas;
	regex_search(src, mas, reg);
	if (mas.size() == 0)
	{
		printf("%s failed!\n", pattern.c_str());
		return false;
	}
	string type = mas[1]; // GET
	string path = "/"; // /index.html
	path += mas[2];
	string filetype = mas[3];
	string param = mas[4];

	if (type != "GET") // ���type������GETֱ�Ӳ�����
	{
		printf("Not GET!!\n");
		return false;
	}


	if (path == "/")
	{
		path = "/index.html";
	}

	string filepath = "../www" + path;

	//php-cgi ../www/index.php id=1 name=dejan > ../www/index.php.html
	if (filetype == "php")
	{
		string cmd = "php-cgi ";
		cmd += filepath;
		cmd += " ";
		// param id=1&name=dejan  ת id=1 name=dejan
		for (int i = 0; i < param.size(); i++)
		{
			if (param[i] == '&') param[i] = ' ';
		}
		cmd += param;

		cmd += " > ";
		filepath += ".html";
		cmd += filepath;

		printf("%s\n", cmd.c_str());
		system(cmd.c_str());
	}


	fp = fopen(filepath.c_str(), "rb");
	if (fp == NULL)
	{
		printf("open file %s failed!\n", filepath.c_str());
		return false;
	}
	// ��ȡ�ļ���С
	fseek(fp, 0, SEEK_END);
	filesize = ftell(fp);
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

	return true;
}

std::string XHttpResponse::GetHead()
{
	char bsize[128] = { 0 };
	sprintf(bsize, "%d", filesize);
	// ��Ӧhttp GET����
	// ��Ϣͷ
	string rmsg = "";
	rmsg = "HTTP/1.1 200 OK\r\n"
		"Server: XHttp\r\n"
		"Content-Type: text/html\r\n"
		"Content-Length: " + string(bsize) + "\r\n"   // ����Ҫע��: ��������ض������ݾ͸�������ĳ�������!
		"\r\n"; // ����
	return rmsg;
}

int XHttpResponse::Read(char* buf, int bufsize)
{
	// ��������
	return fread(buf, 1, bufsize, fp);
}

XHttpResponse::XHttpResponse()
{
}


XHttpResponse::~XHttpResponse()
{
}

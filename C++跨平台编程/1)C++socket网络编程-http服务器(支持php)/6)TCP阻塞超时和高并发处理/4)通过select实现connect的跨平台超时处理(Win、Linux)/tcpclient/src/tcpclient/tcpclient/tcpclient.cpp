#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <XTcp.h>

int main()
{
	XTcp client;
	client.CreateSocket();
	client.SetBlock(false);
	client.Connect("192.168.0.99",8080,5000); // IP是错误的, 测试连接超时最大值5秒效果
	client.Send("client", 6);
	char buf[1024] = {0};
	client.Recv(buf, sizeof(buf));
	printf("%s\n", buf);
	
	getchar();
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<openssl/md5.h>
#include<string>
using namespace std;

// ��ʽ1:
char* md5(const char *src, char *dst)
{
	MD5_CTX ctx;
	// ��ʼ��
	MD5_Init(&ctx);
	// �������
	MD5_Update(&ctx, src, MD5_DIGEST_LENGTH * 2 + 1);
	// ������
	unsigned char md[MD5_DIGEST_LENGTH] = { 0 };
	MD5_Final(md, &ctx);
	for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
	{
		sprintf(&dst[i * 2], "%02x", md[i]);
	}
	return dst;
}

// ��ʽ2:
char* md5_2(const char *src, char *dst)
{
	unsigned char md[MD5_DIGEST_LENGTH] = { 0 };
	MD5((unsigned char*)src, MD5_DIGEST_LENGTH * 2 + 1, md);
	for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
	{
		sprintf(&dst[i * 2], "%02x", md[i]);
	}
	return dst;
}


int main()
{
	char buf[33] = { 0 };
	cout <<"��ʽ1: "<<md5("hello", buf) << endl;
	cout <<"��ʽ2: "<< md5_2("hello", buf) << endl;

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>//�ɱ������ͷ�ļ�



void my_printf01(const char *fmt,...)
{
	const char *tmp = fmt;

	//1.����ɱ��������
	va_list ap;

	//2.��ʼ��
	//�ڶ�������Ҫ...ǰ��Ĳ���
	va_start(ap, fmt);//���߱�������fmt���濪ʼȡ����

	//3.ȡ����
	while (tmp!=NULL)
	{
		printf("tmp=%s\n", tmp);
		tmp = va_arg(ap, const char *);
	}

	//4.����
	va_end(ap);

	
}

void my_printf02(const char *fmt, ...)
{


	//1.����ɱ��������
	va_list ap;

	//2.��ʼ��
	//�ڶ�������Ҫ...ǰ��Ĳ���
	va_start(ap, fmt);//���߱�������fmt���濪ʼȡ����

	//3.ȡ����
	vprintf(fmt, ap);

	//4.����
	va_end(ap);


}

void test02()
{
	int a = 10;
	const char *str = "aaaabbbbb";
	my_printf02("%d,%s\n", a, str);
}


int main()
{

	//printf("hello=%d,%s\n",10,"aaaa");

	my_printf01("aaa","bbb","ccc");
	test02();
	system("pause");
	return EXIT_SUCCESS;
}


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1.����ֵ����ȷ��û��������Ϣ
//2.����ֵ���Ժ���
//3.ֻ�ܷ���һ����Ϣ
int func(int *p)
{
	if (NULL == p)
	{
		return -1;
	}
	return 0;
}

void test()
{
	int *p = NULL;
	func(p);
}

int main()
{
	test();

	system("pause");
	return 0;
}
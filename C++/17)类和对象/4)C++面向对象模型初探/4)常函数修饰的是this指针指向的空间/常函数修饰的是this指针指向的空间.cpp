#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Dejan
{
public:
	Dejan()
	{
		a = 10;
	}

	void func()const
	{
		//const���ε���thisָ��ָ��Ŀռ�
		//������ռ��е�ֵ�����޸�
		//a = 100;
	}
public:
	int a;
};

int main()
{


	system("pause");
	return 0;
}
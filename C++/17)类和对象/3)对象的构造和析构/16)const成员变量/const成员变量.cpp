#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Dejan
{
public:
	Dejan()
	{

	}
public:
	const int a = 10;
	// const���εľ�̬��Ա������������ڳ�ʼ��
	// const static int b=200; // const���εľ�̬��Ա����
	const static int b;
};

const int Dejan::b = 300;

void test()
{
	Dejan d;
	cout << Dejan::b << endl;
}

int main()
{
	test();

	system("pause");
	return 0;
}
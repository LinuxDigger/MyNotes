#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// �Զ�����������
class Dejan
{
public:
	Dejan()
	{
		a = 10;
		c = 30;
	}

	void func()const
	{
		cout << "void func()const" << endl;
	}
	void func2()
	{
		cout << "void func2()" << endl;
	}
public:
	int a;
	const int b = 20;

	mutable int c;
};
// ������ֻ�ܵ��ó�����

void test()
{
	const Dejan dejan; // ������
	dejan.func();
	//dejan.func2();  error

	//const int a = 10;
	//��������Է��ʳ�Ա������const���εĳ�Ա�������������޸�
	cout << dejan.a << endl;
	cout << dejan.b << endl;

	//dejan.a = 100; error
	//dejan.b = 200; error
	//�������mutable���εĳ�Ա���������޸Ŀ��Է���
	dejan.c = 300;
	cout << dejan.c << endl;
}

int main()
{
	test();

	system("pause");
	return 0;
}
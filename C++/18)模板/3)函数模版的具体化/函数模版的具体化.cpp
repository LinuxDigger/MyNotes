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
		b = 20;
	}
public:
	int a;
	int b;
};

// ��������廯
template<class T>
void func(T &a, T &b)
{
	if (a > b)
	{
		cout << "a>b" << endl;
	}
	else
	{
		cout << "a<b" << endl;
	}
}

// ���԰Ѻ���ģ����廯
template<> void func<Dejan>(Dejan &a, Dejan &b)
{
	cout << "���廯" << endl;
	if (a.a < b.a)
	{
		cout << "a.a<b.a" << endl;
	}
	else
	{
		cout << "a.a>b.a" << endl;
	}
}

void test()
{
	Dejan d1;
	Dejan d2;

	func(d1, d2);
}

int main()
{
	test();

	system("pause");
	return 0;
}
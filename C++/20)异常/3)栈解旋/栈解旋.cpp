#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int func1()
{
	throw 1;
}

void test()
{
	try
	{
		func1(); // ����û�н�����ֻ���ж�
		cout << "func1();��������" << endl;
	}
	catch (int)
	{
		cout << "����һ��int���͵��쳣" << endl;
	}
}

class Dejan
{
public:
	Dejan()
	{
		cout << "���캯��" << endl;
	}
	Dejan(const Dejan &d)
	{
		cout << "��������" << endl;
	}
	~Dejan()
	{
		cout << "��������" << endl;
	}
};

void func2()
{
	// ���׳��쳣ʱ���ں���û�н�����ʱ�������������ջ������Ķ��󶼻ᱻ�ͷ�
	Dejan d;

	throw d; // d�´��һ�ݸ��׳��Ķ���,�����׳��Ķ����d2
}

void test02()
{
	try
	{
		func2();
	}
	catch (Dejan d3) // Dejan d3 = d2
	{
		cout << "����һ��Dejan���͵��쳣" << endl;
		//����������������Ķ��������ﱻ�ͷ� d3 d2
	}
}

char func3()
{
	Dejan d; // ������޲ι��캯��

	throw ('a');

	return 'b';
}

void test03()
{
	try
	{
		func3();
	}
	catch (char a1)
	{
		cout << a1 << endl;
	}
}

int main()
{
	test03();

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

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

void func1()
{
	Dejan d;
	throw d;
}

void test01()
{
	try
	{
		func1();
	}
	catch (Dejan d3) // Dejan d3 = d2;
	{
		cout << "����һ��Dejan���͵��쳣" << endl;
		//����������������Ķ��������ﱻ�ͷ� d3 d2
	}
}

void func2()
{
	throw Dejan();
}

void test02()
{
	try
	{
		func2();
	}
	catch (Dejan d)
	{
		cout << "����һ��Dejan���͵��쳣" << endl;
	}
}

void func3()
{
	throw Dejan(); // Ҫcatch���������д���Ž���
}

void test03()
{
	try
	{
		func3();
	}
	catch (Dejan &d)
	{
		cout << "����һ��Dejan���͵��쳣" << endl;
	}
}

void func4()
{
	throw Dejan(); // Ҫcatch���������д���Ž���
}

void test04()
{
	try
	{
		func4();
	}
	catch (Dejan *d) // �������������׳��쳣���ջ�е���������ȡ��ַ����
	{
		cout << "����һ��Dejan���͵��쳣" << endl;
	}
}

void func5()
{
	throw new Dejan; // Ҫcatch���������д���Ž���
}

void test05()
{
	try
	{
		func5();
	}
	catch (Dejan *d) // �������������׳��쳣���ջ�е���������ȡ��ַ����
	{
		cout << "����һ��Dejan���͵��쳣" << endl;
		delete d;
	}
}

// �ܽ᣺���׳�����������catch������������
int main()
{
	test05();

	system("pause");
	return 0;
}
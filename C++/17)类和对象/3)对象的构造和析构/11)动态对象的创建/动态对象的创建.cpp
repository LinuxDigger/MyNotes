#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Dejan
{
public:
	Dejan()
	{
		cout << "���캯��" << endl;
		a = 10;
		b = 20;
	}

	void init()
	{
		a = 20;
		b = 30;
	}

	void printDejan()
	{
		cout << "a=" << a << " b=" << b << endl;
	}

	Dejan(int a)
	{
		cout << "�вι���" << endl;
	}
	~Dejan()
	{
		cout << "��������" << a << endl;
		cout << "b=" << b << endl;
	}
public:
	int a;
	int b;
	static int c;
};

int Dejan::c = 1;

// ��C++��ʹ��malloc��free��������ù������������
void test01()
{
	// Dejan dejan; // ջ��

	Dejan *p = (Dejan*)malloc(sizeof(Dejan));
	if (NULL == p)
	{
		cout << "malloc error" << endl;
	}

	cout << p->a << " " << p->b << endl;

	if (NULL != p)
	{
		free(p);
		p = NULL;
	}
}

void test02()
{
	// �Ӷ���������һ������Ŀռ�
	Dejan *p = new Dejan; // �����޲ι��캯��

	delete p; // ������������
	p = new Dejan(10);
	delete p;
}

class Student
{
public:
	Dejan dejan;
};

void test03()
{
	Student s;
	s.dejan.printDejan();
}

void test04()
{
	Dejan a;
	a.a = 10;
	Dejan b;
	b.a = 20;
}

int main()
{
	test04();

	system("pause");
	return 0;
}
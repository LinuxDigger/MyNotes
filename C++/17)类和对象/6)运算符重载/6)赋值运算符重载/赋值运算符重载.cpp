#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class A
{

};
class Student
{
	// ���죬�������������죬��ֵ��������ֵ��������أ�
public:
	Student(int a)
	{
		this->a = a;
	}
public:
	int a;
};

class Dejan
{
	// ���죬�������������죬��ֵ��������ֵ��������أ�
public:
	Dejan(int a)
	{
		this->a = a;
	}
	// d = d2 ===> m
	Dejan& operator=(Dejan &d2)
	{
		this->a = d2.a;
		return *this;
	}
public:
	int a;
};

void test()
{
	Student s(10);
	Student s2(20);
	cout << "s.a=" << s.a << endl;
	cout << "s2.a=" << s2.a << endl;
	cout << "��ֵ��:" << endl;

	// ���ᱨ��ԭ��: �������ṩ��һ��Ĭ�����ظ�ֵ������ĺ���
	s = s2;
	cout << "s.a=" << s.a << endl;
	cout << "s2.a=" << s2.a << endl;
	// ��ֵ�������˼򵥵ĸ�ֵ����
	// s.a = s2.a;
}

void test02()
{
	int a = 10;
	int b = 20;
	int c = 30;

	c = b = a;
}

void test03()
{
	Dejan d(10);
	Dejan d2(20);
	Dejan d3(30);

	// �������ṩ��һ�����ظ�ֵ������ĺ���
	d3 = d = d2; // ��ֵ����

	cout << &d << endl;
	cout << &(d = d2) << endl;
}

int main()
{
	test03();

	system("pause");
	return 0;
}
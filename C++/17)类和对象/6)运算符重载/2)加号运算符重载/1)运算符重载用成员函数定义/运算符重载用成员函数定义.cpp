#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//��������أ����Ƕ����е���������½��ж���
//������������ô��뿴�������Ӽ��
//��������ز��ܸı����������Ԣ��

class Student
{
public:
	Student(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
public:
	int a;
	int b;
};

class Dejan
{
public:
	//d1+d2  d1��this
	//��������Ӻŵ��ұ�
	Dejan operator+(Dejan &d2)
	{
		Dejan tmp(this->a + d2.a, this->b + d2.b);
		return tmp;
	}
	//d1+s1;
	//��������Ӻŵ��ұ�
	Student operator+(Student &s1)
	{
		Student stu(0, 0);
		stu.a = this->a + s1.a;
		stu.b = this->b + s1.b;
		return stu;
	}
	Dejan(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
public:
	int a;
	int b;
};

void test()
{
	Dejan d1(10, 20);
	Dejan d2(30, 50);

	// ����������������Զ����������Ͷ���ı�����ӣ��ͻ�ȥ��operator�������
	Dejan d3 = d1 + d2;

	cout << "d3.a=" << d3.a << " d3.b=" << d3.b << endl;
	/*
	d1.a + d2.a;
	d1.b + d2.b;
	*/
}

void test2()
{
	Dejan d1(20, 30);
	Student s1(30, 50);

	Student s2 = d1 + s1;

	//Dejan s2 = d1 + s1;

	cout << "s2.a=" << s2.a << " s2.b=" << s2.b << endl;
}

// ��һ����������Ӻŵ���ߣ��ڶ�����������Ӻŵ��ұ�
/*
Dejan operator+(Dejan &d1,Student &s1)
{
	Dejan d(0,0);
	return d;
}
*/

int main()
{
	test2();

	system("pause");
	return 0;
}
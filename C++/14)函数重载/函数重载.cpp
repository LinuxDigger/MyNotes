#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
// ����������Ϊ�˽��ȡ�������ֵ�����
// �������ص�������
// ǰ��:��ͬһ��������
// 1.�����ĸ�����ͬ
// 2.���������Ͳ�ͬ
// 3.������˳��ͬ

// 1.�����ĸ�����ͬ
void add(int a, int b)
{
	cout << "add(int a, int b)" << endl;
}
void add(int a)
{
	cout << "add(int a)" << endl;
}

void test01()
{
	int a = 10;
	int b = 20;
	// add(a,b);
	add('c'); // ������������ʽת��
	// add("liu"); error
}

// 2.���������Ͳ�ͬ
void add1(double a, double b)
{
	cout << "add1(double a, double b)" << endl;
}
void add1(int a, int b)
{
	cout << "add1(int a, int b)" << endl;
}

void test02()
{
	// �����ϸ�����ƥ��
	add1(10.2, 20.2);
	// add1(10, 20.2); error
}

// 3.������˳��ͬ
void add2(int a,double b)
{
	cout << "add2(int a,double b)" << endl;
}
void add2(double a, int b)
{
	cout << "add2(double a, int b)" << endl;
}
void test03()
{
	add2(10,20.2);
	add2(10.10, 20);
}
void add2(int a)
{
	cout << "add2(int a)" << endl;
}

// ע�⣺���������غͺ�����Ĭ�ϲ���һ��ʹ��ʱ����Ҫע�����������
void add2(int a, int b = 0)
{
	cout << "add2(int a, int b = 0)" << endl;
}
void test04()
{
	// add2(10); error: ��������֪��ѡ��
}

int main()
{
	test03();

	system("pause");
	return 0;
}
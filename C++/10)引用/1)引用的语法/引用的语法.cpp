#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*  1.����  */

// ָ��ʵ��1
void func(int *a)
{
	cout << *a << endl;
}
void test()
{
	int a = 10;
	func(&a);
}
// ����ʵ��1
void func2(int &a)
{
	cout << a << endl;  // 1.a ���ü� * 
}
void test2()
{
	int a = 10;
	func2(a); // 2.a ����Ҫ &
}

/*  2.������ȡ���� */
struct Dejan {};
void test3()
{
	// ����Ϸ��Ŀռ�
	int a = 10;

	int &b = a; // ��a���ռ�ȡ����Ϊb
	b = 20;
	cout << "a=" << a << endl;

	int &c = b;
	c = 30;
	cout << "a=" << a << endl;
	cout << "-----------------------------------" << endl;
	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;

	// ��������Ҳһ��
	double d = 20;
	double &p = d;

	Dejan dejan;
	Dejan &dj = dejan;
}

/*  ���õ�ע��:  */
int func3()
{
	int a = 10;
	return a;
}
int* func4()
{
	int a = 10;
	return &a;
}
void test4()
{
	// 1.��������ʱ�������ʼ��
	int a = 10;
	//int &p3 = NULL; error

	int &p = a; // ����ʱ�����ʼ��

	// 2.����һ����ʼ���������޸����õ�ָ��
	int b = 20;
	p = b; // ���Ǹ�ֵ
	// &p = b; error
	cout << "&a=" << &a << endl;
	cout << "&p=" << &p << endl;

	// 3.��������һ��Ϸ����ڴ�ռ�
	//int &p2 = func3(); // error: int &p2 = 10;
	//int &p2 = func4(); // error
}

int main()
{
	test4();

	system("pause");
	return 0;
}
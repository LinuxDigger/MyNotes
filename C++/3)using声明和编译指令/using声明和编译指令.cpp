#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

namespace Dejan
{
	int a = 10;
	int b = 20;
	int c = 30;
}

// using����
void test_1()
{
	cout << Dejan::a << endl;
	using Dejan::b; // ���������ռ��е�b����
	cout << b << endl;

	// ע��:���������������²����ٶ���������ͬ���ֵı���
	// int b = 50;
}

// using����ָ��
void test_2()
{
	using namespace Dejan; // using����ָ��
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	// �����using����ָ��, ��ô�Ͳ������ض�����������
	int a = 20;
	int b = 30;
	int c = 40;
}

int main()
{
	cout << "using����" << endl;
	test_1();
	cout << "using����ָ��" << endl;
	test_2();

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Dejan
{
public:
	/*Dejan()
	{
		cout << "�޲ι��캯��" << endl;
	}
	Dejan(int a)
	{
		cout << "�вι��캯��" << endl;
	}*/
	Dejan(const Dejan &d)
	{
		cout << "�������캯��" << endl;
	}
	~Dejan()
	{
		cout << "��������" << endl;
	}
public:
	int a;
};

void test01()
{
	// Dejan d; // �����޲ι��캯��
	// 1.����û��ṩ���вι��캯������ô�����������ṩ�޲ι��캯��
	// ������û���ṩĬ�ϵ��вι��캯��

	// Dejan d(10);

	// Dejan d2(d); // ���ÿ������캯����
	// 2.����û��Լ�д�˿������캯������ô�����������ṩĬ�ϵĿ������캯��
}

void test02()
{
	// Dejan d;  error
	// 3.����û��Լ�д�˿������캯������ô�����������ṩ�κι��캯��
	// 4.����û�д���вι��죬��ô�����������ṩ�޲ι��죬���ǻ��ṩĬ�ϵĿ������캯��
}

int main()
{
	test02();

	system("pause");
	return 0;
}
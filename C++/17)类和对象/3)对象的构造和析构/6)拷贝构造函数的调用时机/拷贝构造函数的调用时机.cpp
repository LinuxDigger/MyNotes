#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Dejan
{
public:
	Dejan()
	{
		age = 0;
		cout << "�޲ι���" << endl;
	}
	Dejan(int age)
	{
		this->age = age;
		cout << "�вι��캯��" << endl;
	}
	Dejan(const Dejan &dejan)
	{
		cout << "��������" << endl;
	}
public:
	int age;
};

// 2.������ֵ�ķ�ʽ����ʱ����ÿ�������
void func(Dejan dejan) // Dejan dejan = d1
{

}

void test()
{
	Dejan d1; // �����޲ι���

	// 1.�����еĶ���ȥ��ʼ����һ������
	Dejan d2(d1);

	func(d1);
}

// 3.�������ؾֲ�����ʱ��vs debugģʽ�����һ�ο�������
// ��releaseģʽ�£������ÿ������죬���������Ż����Ѻ����ڵľֲ�������
// qt������Ҳһ����������ÿ�������
Dejan func2()
{
	Dejan dejan;
	cout << "dejan:" << &dejan << endl;
	return dejan;
}

void test02() // vs�����л���"Debug"��"Release"ģʽ�۲����仯, �ܽ�: �Զ������ͺ��������з��ظò���ͬ���͵Ķ���,��vs��debugģʽ�±���������п����ٷ��ؿ�����������ֵ,��"Release"ģʽ�±���������б������þ����з��صĶ��󲻻ᱻ�ͷ�ֱ�Ӹ�����ֵָ��
{
	Dejan d2 = func2();
	cout << "d2:" << &d2 << endl;
}

int main()
{
	test02();

	system("pause");
	return 0;
}
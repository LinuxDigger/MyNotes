#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Dejan
{
public:
	Dejan()
	{
		cout << "�޲ι��캯��" << endl;
	}
	Dejan(int a)
	{
		cout << "�вι��캯��" << endl;
	}
	Dejan(const Dejan &d)
	{
		cout << "�������캯��" << endl;
	}
	~Dejan()
	{
		cout << "��������" << endl;
	}
};

// 1.����������������ڽ��ڱ���
void test01()
{
	Dejan(); // ����������ջ������ʱ������
	Dejan(10); // �������󣬵����вι���
	cout << "������������?" << endl;
}

// 2.���������ܵ��ÿ������캯��
void test02()
{
	Dejan dejan;
	//Dejan(dejan); error:�ض���,�������������뿴�� Dejan dejan;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
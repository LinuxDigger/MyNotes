#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Dejan
{
public:
	// ���ղ���������
	// �޲ι��캯��
	Dejan()
	{
		cout << "�޲ι���" << endl;
	}
	// �вι��캯��
	Dejan(int a)
	{
		cout << "�вι���" << endl;
	}

	// ������������
	// ��ͨ����
	// ��������
	Dejan(const Dejan &d) // 1.�������캯���е��β��е�����һ��Ҫ��
	{
		cout << "��������" << endl;
	}
};

void test()
{
	Dejan dejan; // �����޲ι���
	Dejan dejan2(10); // �����вι���
	Dejan dejan3(dejan); // ���ÿ������캯��

	//Dejan dejan4 = dejan; // ���ÿ������캯��
	// �������Ĭ�Ϻ����Ĳ�����Ϊ���ý��������µ���ѭ��
	/*
	Dejan(const Dejan d) // Dejan d = dejan;//���ÿ������캯��
	Dejan(const Dejan d) // Dejan d = dejan;//���ÿ������캯��
	Dejan(const Dejan d) ......
	*/
}

// 2.�����вκͿ������캯��
// �����вι���
void test02()
{
	// 1.���ŷ�
	Dejan dejan(10); // (����)
	// 2.��ʾ�ĵ����вι���
	Dejan dejan2 = Dejan(10);
	// 3.�Ⱥŷ�
	Dejan dejan3 = 10; // �������Ż��ɣ�Dejan dejan3 = Dejan(10);
}

// ���ÿ�������
void test03()
{
	Dejan dejan;
	Dejan dejan2(dejan); // ���ÿ�������(����)
	Dejan dejan3 = Dejan(dejan); // ���ÿ�������
	Dejan dejan4 = dejan; // ���ÿ������� �������Ż�: Dejan dejan4 = Dejan(dejan);
}

int main()
{
	test03();

	system("pause");
	return 0;
}
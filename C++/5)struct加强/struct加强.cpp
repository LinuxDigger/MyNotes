#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// �Զ�����������
struct Dejan_1 {
	// 1.�ṹ���Ĭ��Ȩ��Ϊ����
	char name[64]; // ��Ա���� (��Ա����)
	int age;
	// 2.C++�Ľṹ����Զ��庯�� (����Ҳ�з���)
	void func() // ��Ա���� (��Ա����)
	{
		cout << "func()" << endl;
	}
};

// �Զ����������� (��)
class Dejan_2 {
	// 1.���Ĭ��Ȩ��Ϊ˽��
	char name[64]; // ��Ա���� (��Ա����)
	int age;
	// 2.C++�Ľṹ����Զ��庯��,��Ҳ����
	void func()// ��Ա���� (��Ա����)
	{
		cout << "func()" << endl;
	}
};

int main()
{
	// ������ʵ��������
	// ���Զ����������Ͷ���һ������
	Dejan_2 dj2; // dj2���Ƕ���

	// C++�Զ������ͱ���,����Ҫ��struct�ؼ���
	Dejan_1 dj1;

	system("pause");
	return 0;
}
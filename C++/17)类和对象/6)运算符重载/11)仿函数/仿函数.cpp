#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
//�º�������Щ������Ҫ���õ������ֲ���д��ȫ�ֺ�����������������д�ɳ�Ա������Ȼ������()��
//�����Ϳ��԰Ѷ�����ճɺ���һ��ʹ��
//�º�������Ϊ�㷨�Ĳ���

class Dejan
{
public:
	Dejan() {}
	Dejan(string name)
	{
		this->name = name;
	}
	Dejan(int a, int b)
	{
		cout << "�вι��캯��" << endl;
	}
	int operator()(int a, int b)
	{
		cout << "int operator()(int a, int b)" << endl;
		return a + b;
	}
	void printDejan()
	{
		cout << this->name << "��Ư��" << endl;
	}
private:
	string name;
};

void test()
{
	Dejan func("�仨");
	func.printDejan();

	Dejan func2(10, 20); // ��������вι��캯��

	Dejan func3; // ��������޲ι��캯��
	func3(10, 20); // �������ã������غ���
	cout << func3(10, 20) << endl;

	func3(10, 20);
}

int main()
{
	test();

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Drink
{
public:
	// ��ˮ
	virtual void func1() = 0;
	// ����
	virtual void func2() = 0;
	// ��������
	virtual void func3() = 0;
	// �ӵ㸨��
	virtual void func4() = 0;

	void maker()
	{
		func1();
		func2();
		func3();
		func4();
	}
};

class Coffee :public Drink
{
	// ��ˮ
	virtual void func1()
	{
		cout << "��㿪ˮ" << endl;
	}
	// ����
	virtual void func2()
	{
		cout << "���ݿ���" << endl;
	}
	// ��������
	virtual void func3()
	{
		cout << "���뱭��" << endl;
	}
	// �ӵ㸨��
	virtual void func4()
	{
		cout << "�ӵ��ǻ�ţ��" << endl;
	}

	/*
	void maker()
	{
		func1();
		func2();
		func3();
		func4();
	}
	*/
};

void test()
{
	Drink *drink = NULL;
	drink = new Coffee;
	drink->maker();
	delete drink;
}

int main()
{
	test();

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// ע�����Ի��ʵ�: ����Ĵ�С��һ���ֽ�
class Dj {};


class Dejan
{
public:
	void func() // ��ͨ��Ա����
	{
		a = 20; // ��������ô�ܷ��ʻ��޸�a?
	}
	static void func2() // ��̬��Ա����
	{

	}
public:
	static int b; // ��̬��Ա����

	int a; // ��ͨ��Ա����
	double c;
};

int Dejan::b = 20;

void test()
{
	cout << sizeof(Dejan) << endl;

	// ��Ĵ�С����ͨ��Ա�����Ĵ�С
	// ��Ա�����ͳ�Ա�����Ƿֿ��洢
}

int main()
{
	test();

	system("pause");
	return 0;
}
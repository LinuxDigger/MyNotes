#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class BMW
{
public:
	BMW(int a)
	{
		age = a;
		cout << "BMW�вι���" << endl;
	}
	~BMW()
	{
		cout << "BMW��������" << endl;
	}
public:
	int age;
};

class Buick
{
public:
	Buick(int a)
	{
		cout << "Buick�вι���" << endl;
	}
	Buick(int a, int b)
	{
		cout << "Buick��ι���" << endl;
	}
	~Buick()
	{
		cout << "Buick��������" << endl;
	}
};

// ��ʼ���б���ָ������ĳ�ֹ��캯��
// ��ʼ���б�ֻ��д�ڹ��캯����
class Dejan
{
public:
	Dejan(int a, int b) :bmw(a), buick(b, a)
	{
		cout << "Dejan�вι���" << endl;
	}
	~Dejan()
	{
		cout << "Dejan��������" << endl;
	}
public:
	Buick buick; // ��Ա����
	BMW bmw;
};

void test()
{
	Dejan dejan(30, 60);
	cout << dejan.bmw.age << endl;
}

int main()
{
	test();

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Dejan
{
public:
	Dejan()
	{
		cout << "�޲ι���" << endl;
	}
	Dejan(int a)
	{
		cout << "�вι���" << endl;
	}
	~Dejan()
	{
		cout << "��������" << endl;
	}
};
/*
����׶�
main -->test

test-> new Maker --->���ù��캯��Maker()

Maker *q -> delete q; -> ������������~Maker()

C++����ʶvoid *

*/

void test()
{
	// ��Ҫ��void *���ӴӶ�������Ķ���ռ�
	void *p = new Dejan;

	// ��Ϊdeleteʱ���������������
	delete p;

	Dejan *q = new Dejan;
	delete q;
}

int main()
{
	test();

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

namespace Girl {
	int a = 18;
	int b = 20;
	int c = 23;
	void girl_1()
	{
		cout << "С���1,���165,ƫ�ݡ�" << endl;
	}
	void girl_2()
	{
		cout << "С���2,���175,΢�֡�" << endl;
	}
}

int a = 30;

int main()
{
	cout << "��Уʱ��Ůͬѧ:" << Girl::a << endl;
	cout << "��˾���Ůͬ��:" << a << endl;
	cout << "��ϲ�������͡�" << endl;
	Girl::girl_2();

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Dejan
{
public:
	void func()
	{
		cout << "����Խλ�쳣" << endl;
	}
	void fucn2()
	{
		cout << "ָ��Խλ�쳣" << endl;
	}
};

// 1.����ֵ���Ժ��ԣ����쳣���ܺ��ԣ������쳣�ͱ���
int myfunc(int a, int b)
{
	if (0 == b)
	{
		// 1.�׳��쳣
		//throw 1; // �׳�һ��int���͵��쳣
		//throw 'c'; // �׳�һ��char���͵��쳣
		//throw 20.22; // �׳�һ��double���͵��쳣
		//Dejan d;
		//throw d; // �׳�һ��Dejan���͵��쳣
		throw 20.01f;
	}
	return a / b;
}

void test()
{
	int a = 10;
	int b = 0;
	try
	{
		// 2.�ѿ����׳��쳣�ĺ���д��try��
		myfunc(a, b);
	}
	catch (int) // ����һ��int���͵��쳣
	{
		cout << "����һ��int���͵��쳣" << endl;
	}
	catch (char)
	{
		cout << "����һ��char���͵��쳣" << endl;
	}
	catch (double)
	{
		cout << "����һ��double���͵��쳣" << endl;
	}
	catch (Dejan d)
	{
		cout << "����һ��Dejan���͵��쳣" << endl;
		d.func();
		d.fucn2();
	}
	catch (...)
	{
		throw; // �������׳��쳣
		cout << "���������쳣" << endl;
	}
}

int main()
{
	try
	{
		test();
	}
	catch (float)
	{
		cout << "����һ��float���͵��쳣" << endl;
	}

	system("pause");
	return 0;
}
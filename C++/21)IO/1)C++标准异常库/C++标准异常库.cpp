#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<stdexcept> // �쳣���ͷ�ļ���vs2013����Ҫ
using namespace std;

// 1.ʹ�ñ�׼�쳣��
class Dejan
{
public:
	Dejan(int age)
	{
		if (age < 0 || age >180)
		{
			throw out_of_range("���䳬��������Χ");
		}
		else
		{
			this->age = age;
		}
	}
public:
	int age;
};

void test()
{
	try
	{
		Dejan(200);
	}
	catch (out_of_range &e)
	{
		cout << e.what() << endl;
	}
}

// 2.�Զ����쳣��
class myOut_of_range :public exception
{
public:
	myOut_of_range(const char *str)
	{
		//const char*--->string
		this->err_msg = string(str);
	}
	myOut_of_range(const string str)
	{
		this->err_msg = str;
	}
	virtual const char* what() const
	{
		//string  ->const char*
		return this->err_msg.c_str();
	}
public:
	string err_msg;
};

class Maker
{
public:
	Maker(int age)
	{
		if (age < 0 || age >180)
		{
			throw myOut_of_range("�Լ����쳣��: ���䳬��������Χ");
		}
		else
		{
			this->age = age;
		}
	}
public:
	int age;
};

void test2()
{
	try
	{
		Maker(200);
	}
	catch (myOut_of_range &e)
	{
		cout << e.what() << endl;
	}
}

int main()
{
	test2();

	system("pause");
	return 0;
}
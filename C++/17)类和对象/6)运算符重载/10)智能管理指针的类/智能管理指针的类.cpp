#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Dejan
{
public:
	Dejan() {}
	Dejan(const char *name)
	{
		cout << "Dejan�вι���" << endl;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	void printDejan()
	{
		cout << "printDejan()" << endl;
	}
	~Dejan()
	{
		cout << "Dejan��������" << endl;
		if (NULL != this->name)
		{
			delete[] this->name;
			this->name = NULL;
		}
	}
public:
	char *name;
};

class Dejan2
{
public:
	Dejan2() {}
	Dejan2(const char *name)
	{
		cout << "Dejan2�вι���" << endl;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	void printDejan2()
	{
		cout << "printDejan2()" << endl;
	}
	~Dejan2()
	{
		cout << "Dejan2��������" << endl;
		if (NULL != this->name)
		{
			delete[] this->name;
			this->name = NULL;
		}
	}
public:
	char *name;
};

// ���ܹ���ָ�����
class Student
{
public:
	Student(Dejan *d, Dejan2 *d2)
	{
		cout << "Student�вι���" << endl;
		this->d = d;
		this->d2 = d2;
	}
	Dejan* operator->()
	{
		return this->d;
	}
	Dejan2& operator*()
	{
		return *this->d2; // *this->d2 �Ƕ���
	}
	~Student()
	{
		if (NULL != this->d)
		{
			delete this->d; // �ͷŵ���new Dejan��
			this->d = NULL;
		}
		if (NULL != this->d2)
		{
			delete this->d2;
			this->d2 = NULL;
		}
		cout << "Student��������" << endl;
	}
public:
	Dejan *d;
	Dejan2 *d2;
};

void test()
{
	Dejan *p = new Dejan;
	Dejan2 *p2 = new Dejan2;

	//s�����������ջ������test����������ȥ����Student����������
	//����������������ͷ��˴Ӷ��������Dejan����
	Student s(p, p2);
	//s->Ҫ����Dejan���Ͳ��ܴ�ӡ��printDejan()
	s->printDejan();

	(*s).printDejan2();
}

int main()
{
	test();

	system("pause");
	return 0;
}
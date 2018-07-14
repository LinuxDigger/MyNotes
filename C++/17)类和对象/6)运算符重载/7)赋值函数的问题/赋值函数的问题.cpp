#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Dejan
{
public:
	Dejan(const char *name)
	{
		// �Ӷ�������ռ�
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	// d1 = d2
	Dejan& operator=(const Dejan &dejan)
	{
		// 1.�ͷ�ԭ���Ŀռ�
		if (NULL != this->name)
		{
			delete[] this->name;
			this->name = NULL;
		}
		// 2.�����µĿռ�
		this->name = new char[strlen(dejan.name) + 1];
		// 3.��������
		strcpy(this->name, dejan.name);
		// ���ض�����
		return *this;
	}
	void printDejan()
	{
		cout << this->name << endl;
	}
	~Dejan()
	{
		if (NULL != this->name)
		{
			delete[] this->name;
			this->name = NULL;
		}
	}
public:
	char *name;
};

void test()
{
	Dejan d1("С���");
	Dejan d2("С���");

	d1.printDejan();
	d2.printDejan();

	d1 = d2;

	d1.printDejan();
	d2.printDejan();
}

int main()
{
	test();

	system("pause");
	return 0;
}
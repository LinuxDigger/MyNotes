#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
// Ĭ�ϵĿ������캯������ʲô?���˼򵥵ĸ�ֵ����

class Dejan
{
public:
	Dejan()
	{
		a = 0;
		b = 0;
	}
	Dejan(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
public:
	int a;
	int b;
};

void test()
{
	Dejan dejan(10, 20); // �����вι���
	Dejan dejan2(dejan); // ����Ĭ�Ͽ������캯��
	cout << "dejan.a=" << dejan.a << " dejan.b=" << dejan.b << endl;
	cout << "dejan2.a=" << dejan2.a << " dejan2.b=" << dejan2.b << endl;

	/*
	Ĭ�Ϲ��캯�����˼򵥵ĸ�ֵ����
	dejan2.a = dejan.a;
	dejan2.b = dejan.b;
	*/
}

class Girl
{
public:
	Girl()
	{

	}
	Girl(const char *name, int age) // �вι���
	{
		this->age = age;
		this->name = (char*)malloc(strlen(name) + 1);
		strcpy(this->name, name);
	}

	Girl(const Girl &girl)
	{
		cout << "Ů���Ŀ������캯��" << endl;
		this->name = (char*)malloc(strlen(girl.name) + 1);
		strcpy(this->name, girl.name);
		this->age = girl.age;
	}
	// ��д��ֵ����ʱ

	void printGirl()
	{
		cout << "name:" << name << " age:" << age << endl;
	}
	~Girl() {
		if (NULL != name)
		{
			free(name);
			name = NULL;
		}
	}
public:
	char *name;
	int age;
};

void test02()
{
	Girl girl("С���", 16);
	girl.printGirl();

	Girl girl2(girl); // ����Ĭ�ϵĿ������캯��
	cout << girl2.name << " " << girl2.age << endl;
}

int main()
{
	test02();

	system("pause");
	return 0;
}
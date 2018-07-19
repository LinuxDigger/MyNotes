#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

// ��ģ��
template<class NameType, class AgeType>
class Dejan
{
public:
	Dejan(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}
	void printDejan()
	{
		cout << "name:" << this->name << " age:" << this->age << endl;
	}
public:
	NameType name;
	AgeType age;
};

void test()
{
	// ��ģ�治���Զ��Ƶ��������ͣ�������ʾ���߱���������������ʲô
	Dejan<string, int> m1("С���", 18);
	m1.printDejan();

	Dejan<int, int> m2(10, 20);
	m2.printDejan();

	//Dejan<> m3(10,0); error
}

// ��ģ�������Ĭ�ϵĲ�������������������(Ĭ�ϲ�������Ĳ������붼��Ĭ�ϲ���)
template<class NameType, class AgeType = int, class T = double>
class Dejan2
{
public:
	Dejan2(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}

	void printDejan2()
	{
		cout << "name:" << this->name << " age:" << this->age << endl;
	}
public:
	NameType name;
	AgeType age;
};

void test02()
{
	Dejan2<string, int, double> m1("С���", 20);
	m1.printDejan2();
	// ����ʹ���û�������������
	Dejan2<string, double, int> m2("С���", 20.38);
	m2.printDejan2();
}

// ��Ĭ�ϲ�������ģ�洫��ע�⣺
void test03()
{
	// �����ģ����Ĭ�ϲ�������ô�����б��п��Բ�ָ����������
	Dejan2<string> d("С���", 18);
	// ����㴫��������ݺ�Ĭ�ϵ������Ͳ�ͬʱ���������᳢��ת����
	// ���ת���ɹ�����OK�����ת�����ɹ��ͱ���
	Dejan2<string> d2("С���", 18.66);
	d2.printDejan2();
	/*Dejan2<string> d3("С���","aaa"); error
	d3.printDejan2();*/
}

// int N �Ƿ����Ͳ���
template<class NameType, class AgeType = int, class T = double, int N = 20>
class Dejan3
{
public:
	Dejan3(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}

	void printDejan3()
	{
		cout << "name:" << this->name << " age:" << this->age << " N:" << N << endl;
	}
public:
	NameType name;
	AgeType age;
};

void test04()
{
	Dejan3<string, int, double, 10> m("С���", 18);
	m.printDejan3();
}

// ������Ϊ��ģ��Ĳ���
class Dejan51
{
public:
	void printDejan51()
	{
		cout << "printDejan51()" << endl;
	}
};

class Dejan52
{
	void printDejan52()
	{
		cout << "printDejan52()" << endl;
	}
};

template<class T>
class myClass
{
public:
	T obj;

	void func1()
	{
		obj.printDejan51();
	}
	void func2()
	{
		obj.printDejan52();
	}
};

void test05()
{
	myClass<Dejan51> m;
	m.func1();
	//m.func2();   error
	/*
	class myClass
	{
	public:
		Dejan51 obj;

		void func1()
		{
			obj.printDejan51();
		}

		void func2()
		{
			obj.printDejan52();
		}
	};
	*/
}

int main()
{
	test05();

	system("pause");
	return 0;
}
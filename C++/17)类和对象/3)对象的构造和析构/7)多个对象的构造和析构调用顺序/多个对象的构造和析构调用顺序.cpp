#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class BMW
{
public:
	BMW()
	{
		cout << "BMW�޲ι���" << endl;
	}
	~BMW()
	{
		cout << "BMW��������" << endl;
	}
};

class Buick
{
public:
	Buick()
	{
		cout << "Buick�޲ι���" << endl;
	}
	~Buick()
	{
		cout << "Buick��������" << endl;
	}
};

class Dejan
{
public:
	Dejan()
	{
		cout << "Dejan�޲ι���" << endl;
	}
	~Dejan()
	{
		cout << "Dejan��������" << endl;
	}
public:
	Buick buick; // ��Ա����
	BMW bmw;
};

// �ܽ᣺�������Ĺ����������������˳����
// �ȵ��ó�Ա����Ĺ��캯������Ա����Ĺ��캯������˳��Ͷ����˳��һ�������ٵ��ñ���Ĺ��캯�������������ĵ���˳��֮

//ע�⣺���뱣֤��Ա����Ĺ���������ܱ�����
void test()
{
	Dejan dejan;
}

int main()
{
	test();

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class FatherA
{
public:
	FatherA()
	{
		CarName = "����";
	}
public:
	string CarName;
};

class FatherB
{
public:
	FatherB()
	{
		CarName = "����";
	}
public:
	string CarName;
};

class Son :public FatherA, public FatherB
{

};
// ��̳���ͬ�����ⲻ�ܽ��

void test()
{
	Son s;
	//s.CarName; error
	cout << s.FatherA::CarName << endl;
	cout << s.FatherB::CarName << endl;
}

int main()
{
	test();

	system("pause");
	return 0;
}
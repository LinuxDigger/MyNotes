#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
//1.����Ա�������βε�����һ��ʱ����thisָ��������
//2.���ض�����

class Girl
{
public:
	Girl(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	Girl& getObj()
	{
		return *this; // ���ص��Ƕ��������������ʱ����
	}
public:
	string name;
	int age;
};

void test()
{
	Girl girl("С���", 18);
	Girl &p = girl.getObj(); // ���صĶ�����girl�������

	cout << &girl << endl;
	cout << &p << endl; // ������ַ��һ��
}

int main()
{
	test();

	system("pause");
	return 0;
}
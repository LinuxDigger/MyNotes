#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

class Dejan
{
public:
	Dejan(int age)
	{
		this->age = age;
	}
	Dejan(const Dejan &m)
	{
		cout << "�������캯��" << endl;
	}
	//1.��֤�����Ŀ������캯���ܱ�����
	//2.ע����ǳ��������

public:
	int age;
};

void test()
{
	vector<Dejan> v;
	//��ʵ���ǰ�Maker(10)�������������������ǿ���һ�ݷ���������
	v.push_back(Dejan(10));
}

int main()
{
	test();

	system("pause");
	return 0;
}
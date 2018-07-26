#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<functional>
#include<numeric>
#include<vector>
#include<string>
using namespace std;
/*
accumulate�㷨 ��������Ԫ���ۼ��ܺ�
@param beg ������ʼ������
@param end ��������������
@param value�ۼ�ֵ

accumulate(iterator beg, iterator end, value)
*/
void test01()
{
	vector<int> v1;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	int ret = accumulate(v1.begin(), v1.end(), 1);//��������������Ԫ���ۼ�֮���
	cout << ret << endl;
}

class Dejan
{
public:
	Dejan(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
public:
	string name;
	int age;
};

struct MyPlus
{
	/*int operator()(int val,Maker &m)
	{
		return val + m.age;

	}*/
	string operator()(string str, Dejan &d)
	{
		return str += d.name;
	}
};

void test02()
{
	vector<Dejan> v;
	v.push_back(Dejan("aaa1", 10));
	v.push_back(Dejan("aaa1", 20));
	v.push_back(Dejan("aaa1", 30));
	/*
	int ret = accumulate(v.begin(), v.end(), 0, MyPlus());
	cout << ret << endl;*/
	string str2 = " ";
	string str = accumulate(v.begin(), v.end(), str2, MyPlus());
	cout << str << endl;
}

/*
fill�㷨 �����������Ԫ��
@param beg ������ʼ������
@param end ��������������
@param value t���Ԫ��

fill(iterator beg, iterator end, value)


*/
void test03()
{
	vector<int> v;
	v.resize(10);
	fill(v.begin(), v.end(), 100);
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
}

int main()
{
	test03();

	system("pause");
	return 0;
}
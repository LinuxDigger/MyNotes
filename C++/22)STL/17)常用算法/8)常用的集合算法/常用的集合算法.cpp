#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<functional>
#include<numeric>
#include<vector>
using namespace std;
/*
set_intersection�㷨 ������set���ϵĽ���
ע��:�������ϱ�������������
@param beg1 ����1��ʼ������
@param end1 ����1����������
@param beg2 ����2��ʼ������
@param end2 ����2����������
@param dest  Ŀ��������ʼ������
@return Ŀ�����������һ��Ԫ�صĵ�������ַ

set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
*/
//����
void test01()
{
	vector<int> v1, v2;
	//1 2 3 4 5 6 7 8 
	for (int i = 0; i < 9; i++)
	{
		v1.push_back(i);
	}
	//5 6 7 8 9 10 11 12 13 14
	for (int i = 5; i < 15; i++)
	{
		v2.push_back(i);
	}

	vector<int> v3;
	v3.resize(min(v1.size(), v2.size()));//ȡ2��������С�������Ĵ�С

	//���ص���Ŀ�����������һ��Ԫ�صĵ�����
	vector<int>::iterator myend = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	for (vector<int>::iterator it = v3.begin(); it != myend; ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

/*
set_union�㷨 ������set���ϵĲ���
ע��:�������ϱ�������������
@param beg1 ����1��ʼ������
@param end1 ����1����������
@param beg2 ����2��ʼ������
@param end2 ����2����������
@param dest  Ŀ��������ʼ������
@return Ŀ�����������һ��Ԫ�صĵ�������ַ

set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
*/
//����
void test02()
{
	vector<int> v1, v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for (int i = 5; i < 15; i++)
	{
		v2.push_back(i);
	}

	vector<int> v3;
	v3.resize(v1.size() + v2.size());

	//���ص���Ŀ�����������һ��Ԫ�صĵ�����
	vector<int>::iterator myend = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	for (vector<int>::iterator it = v3.begin(); it != myend; ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

/*
set_difference�㷨 ������set���ϵĲ
ע��:�������ϱ�������������
@param beg1 ����1��ʼ������
@param end1 ����1����������
@param beg2 ����2��ʼ������
@param end2 ����2����������
@param dest  Ŀ��������ʼ������
@return Ŀ�����������һ��Ԫ�صĵ�������ַ

set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
*/
//�
//���缯��A 1 2 3 4 5��B������2 3 4 5 6��A���ϼ�B���ϵ���1
//
void test03()
{
	vector<int> v1, v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);

	vector<int> v3;
	v3.resize(v1.size() + v2.size());
	//���ص���Ŀ�����������һ��Ԫ�صĵ�����
	vector<int>::iterator myend = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	for (vector<int>::iterator it = v3.begin(); it != myend; ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test03();

	system("pause");
	return 0;
}
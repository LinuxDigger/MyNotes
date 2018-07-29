#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

/*
copy�㷨 ��������ָ����Χ��Ԫ�ؿ�������һ������
@param beg ������ʼ������
@param end ��������������
@param dest Ŀ����������������

copy(iterator beg, iterator end, iterator dest)
*/
void test01()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), [](int val) {cout << val << " "; });
	cout << endl;
}

/*
//�ʱ��㷨
replace�㷨 ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
@param beg ������ʼ������
@param end ��������������
@param oldvalue ��Ԫ��
@param oldvalue ��Ԫ��

replace(iterator beg, iterator end, oldvalue, newvalue)
*/

void test02()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	replace(v1.begin(), v1.end(), 20, 200);
	for_each(v1.begin(), v1.end(), [](int val) {cout << val << " "; });
	cout << endl;
}

/*
swap�㷨 ��������������Ԫ��
@param c1����1
@param c2����2

swap(container c1, container c2)
*/
void test03()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 10);
	}
	for_each(v1.begin(), v1.end(), [](int val) {cout << val << " "; });
	cout << endl;
	for_each(v2.begin(), v2.end(), [](int val) {cout << val << " "; });
	cout << endl;
	cout << "����֮��:" << endl;
	swap(v1, v2);

	for_each(v1.begin(), v1.end(), [](int val) {cout << val << " "; });
	cout << endl;
	for_each(v2.begin(), v2.end(), [](int val) {cout << val << " "; });
	cout << endl;
}

int main()
{
	test03();

	system("pause");
	return 0;
}
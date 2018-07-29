#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<ctime>
using namespace std;
/*
merge�㷨 ����Ԫ�غϲ������洢����һ������
@param beg1 ����1��ʼ������
@param end1 ����1����������
@param beg2 ����2��ʼ������
@param end2 ����2����������
@param dest  Ŀ��������ʼ������

merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
*/
void test01()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 5);
	}

	vector<int> v3;
	v3.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	for_each(v3.begin(), v3.end(), [](int val) {cout << val << " "; });
	cout << "-----------------" << endl;
	//���Ҫ�ı�������ô����Ҫ�������ʹ��greater<int>()
	vector<int> v11;
	vector<int> v22;

	for (int i = 10; i > 0; i--)
	{
		v11.push_back(i);
		v22.push_back(i);
	}

	vector<int> v33;
	v33.resize(v11.size() + v22.size());
	merge(v11.begin(), v11.end(), v22.begin(), v22.end(), v33.begin(), greater<int>());
	for_each(v33.begin(), v33.end(), [](int val) {cout << val << " "; });
}

/*
ϴ��
sort�㷨 ��ָ����Χ�ڵ�Ԫ�������������
@param beg ������ʼ������
@param end ��������������

random_shuffle(iterator beg, iterator end)
*/
void test02()
{
	vector<int> v1;
	for (int i = 5; i > 0; i--)
	{
		v1.push_back(i + 1);
	}
	for_each(v1.begin(), v1.end(), [](int val) {cout << val << " "; });
	cout << "--------------------" << endl;

	//�����������
	srand((unsigned int)time(NULL));
	random_shuffle(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), [](int val) {cout << val << " "; });
}

/*
reverse�㷨 ��תָ����Χ��Ԫ��
@param beg ������ʼ������
@param end ��������������

reverse(iterator beg, iterator end)
*/
void test03()
{
	vector<int> v1;
	for (int i = 5; i > 0; i--)
	{
		v1.push_back(i + 1);
	}
	for_each(v1.begin(), v1.end(), [](int val) {cout << val << " "; });
	cout << "--------------------" << endl;

	reverse(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), [](int val) {cout << val << " "; });
}

int main()
{
	test03();

	system("pause");
	return 0;
}
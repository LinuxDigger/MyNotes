#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
transform�㷨 ��ָ����������Ԫ�ذ��˵���һ������
ע�� : transform �����Ŀ�����������ڴ棬������Ҫ������ǰ������ڴ�
@param beg1 Դ������ʼ������
@param end1 Դ��������������
@param beg2 Ŀ��������ʼ������
@param _cakkback �ص��������ߺ�������
@return ����Ŀ������������

transform(iterator beg1, iterator end1, iterator beg2, _callbakc)
*/
struct Myadd
{
	int operator()(int v1)
	{
		return v1 + 100;
	}
};
void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int> v2;
	//���ٿռ�
	v2.resize(v.size());//���ʼ��
	transform(v.begin(), v.end(), v2.begin(), Myadd());

	for_each(v2.begin(), v2.end(), [](int val) {cout << val << " "; });
}

//�����������е�Ԫ�ؾ���������˵�������������
//ע�⣺���������е�Ԫ�ظ�����Ҫ��ͬ
struct Myadd2
{
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int> v2;
	v2.push_back(100);
	v2.push_back(200);
	v2.push_back(300);
	v2.push_back(400);
	v2.push_back(500);

	vector<int> v3;
	v3.resize(v.size());

	transform(v.begin(), v.end(), v2.begin(), v3.begin(), Myadd2());
	for_each(v3.begin(), v3.end(), [](int val)->void {cout << val << " "; });
}

int main()
{
	test02();

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// �������������
void test()
{
	int arr[] = { 1, 2, 3, 4, 5 };

	// ��һ�ַ���
	typedef int(ARRAY)[5]; // ������������
	ARRAY &ret = arr;
	/*
	int a = 10;
	int &p = a;
	*/
	// �ڶ��ַ���(����)
	int(&ARR_RET)[5] = arr;
	/*
	int a = 10;
	int &p = a;
	*/
	// �����ַ���
	typedef int(&ARRAY2)[5]; // ����������������
	ARRAY2 ret2 = arr;


	for (int i = 0; i < 5; i++)
	{
		ret[i] = 100 + i;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << ret2[i] << " ";
	}
	cout << endl;
}

int main()
{
	test();

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	//int &p = 10; error:���ǺϷ��ռ�

	const int &p = 20;
	//�������Ż���:int tmp = 20;const int &p = tmp;
	cout << p << endl;

	//p = 300; error:p�ǳ������ܸ�ֵ

	int a = 10;
	int &pa = a;
	pa = 200;

	system("pause");
	return 0;
}
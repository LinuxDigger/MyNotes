#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	int a = 10;
	int b = 20;
	(a > b ? a : b) = 100;
	cout << "a:" << a << endl; // 10
	cout << "b:" << b << endl; // 100
	// C++����Ŀ��������ص�����ֵ�����ص��ǿռ�

	system("pause");
	return 0;
}
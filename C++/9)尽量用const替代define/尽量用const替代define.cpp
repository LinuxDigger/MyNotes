#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define NUM 128
//1.�ú궨���û������
//2.����������������ļ�
const short num = 128;

void func(short a)
{
	cout << "func(short a)" << endl;
}

void func(int a) 
{
	cout << "func(int a)" << endl;
}

int main()
{
	func(num);

	system("pause");
	return 0;
}
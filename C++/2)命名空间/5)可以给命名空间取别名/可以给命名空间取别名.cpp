#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//ע��5�����Ը������ռ�ȡ����
namespace A
{
	int a = 10;
	int b = 20;
}

int main()
{
	//B ������    A ������
	namespace B = A;
	cout << B::a << endl;
	cout << B::b << endl;

	system("pause");
	return 0;
}
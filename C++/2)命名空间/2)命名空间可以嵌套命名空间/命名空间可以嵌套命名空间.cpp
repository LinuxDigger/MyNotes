#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//ע��2�������ռ����Ƕ�������ռ�
namespace A
{
	int a = 20;
	namespace B {
		int a = 22;
		int b = 33;
	}
	int b = 50;
}

int main()
{
	cout << A::a << endl;
	cout << A::B::a << endl;

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//ע��4:���������ռ�
namespace {
	int coun = 0;
}

int main()
{
	cout << ::coun << endl;

	system("pause");
	return 0;
}
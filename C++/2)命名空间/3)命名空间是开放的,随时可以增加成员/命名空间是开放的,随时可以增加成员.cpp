#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

namespace A
{
	int a;
	int b;
	int c = 10;
}

//ע��3�������ռ��ǿ��ŵģ���ʱ�������ӳ�Ա
namespace A
{
	int d = 20;
}


int main()
{
	cout << "A::c = " << A::c << endl;
	cout << "A::d = " << A::d << endl;

	system("pause");
	return 0;
}
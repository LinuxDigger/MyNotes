#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int myFunc(int a, int b=0) // �������Ĳ�����ֵ����������Ǻ�����Ĭ�ϲ���
{
	return a + b;
}

void test01() 
{
	// ���û�и�Ĭ�ϲ�����ֵ����ô������ʹ��Ĭ�ϲ�����ֵ
	cout << myFunc(10)<<endl;
	// ����и�Ĭ�ϲ�����ֵ����ô����������ʹ���û������ֵ
	cout << myFunc(20, 10) << endl;
}

// ������Ĭ�ϲ�����ע��:
// 1.��Ĭ�ϲ������ұ߱��붼��Ĭ�ϲ���
void myfunc2(int a, int b = 10, int c = 0, int d = 0)
{

}

// 2.������ʵ��ֻ����һ����Ĭ�ϲ���
void func(int a, int b);
void func(int a, int b = 0)
{

}

// ������ռλ����,��������ص�ʱ������ǰ�üӼӻ��Ǻ��üӼӵ�ʱ������
void func2(int a,int)
{

}
void test02() 
{
	func2(10,10);
}

int main()
{
	test01();

	system("pause");
	return 0;
}
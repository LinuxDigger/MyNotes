#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
// 5.����ģ�����ͨ�������Է�������
int myplus(int a, int b)
{
	cout << "��ͨ����" << endl;
	return a + b;
}

template<class T>
T myplus(T a, T b)
{
	cout << "����ģ��" << endl;
	return a + b;
}

// 6.����ģ��֮��Ҳ��������
template<class T>
T myplus(T a)
{
	cout << "����ģ��" << endl;
	return a + 10;
}

void test01()
{
	int a = 10;
	int b = 20;
	myplus(a, b); // 1.������ģ�����ͨ�������أ����ȵ�����ͨ����

	myplus(20.22, 10.11); // 2.�����㴫��������ͺ���ͨ������ƥ��ʱ�����ú���ģ��

	myplus(a, 'c'); // 3.�ַ����ͻ���ʽת����int����

	// 4.ǿ�Ƶ��ú���ģ��
	myplus<>(a, b); // <>�ղ����б�
}

// ǿ�Ƶ��ú���ģ�����ʽת��
template<class T>
T func(T a, T b)
{
	return a + b;
}

void test02()
{
	// ��ʽ��ת��
	cout << func<int>(3, 3.5) << endl;
}

int main()
{
	test02();

	system("pause");
	return 0;
}
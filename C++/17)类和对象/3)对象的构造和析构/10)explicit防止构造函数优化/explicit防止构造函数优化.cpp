#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Dejan
{
public:
	// ��ֹ��ʽת�� explicitֻ�����ι���
	Dejan(int n)
	{
		cout << "�вι���" << endl;
	}
	// ��ι��캯��
	explicit Dejan(int a, int b = 0, int c = 0)
	{
		cout << "��ι���" << endl;
	}
};

void test()
{
	Dejan dejan = 10; // �������Ż��ɣ�Dejan dejan=Dejan(10);
	Dejan dejan2(10,20); // ע��:��ι���������˵�һ������û��Ĭ��ֵ��������Ĭ��ֵ�����, ���ǰ�涨���˵�һ�������캯�����ᵼ�±������޷�ѡ��
	// explicit Dejan(int n)  // �繹�캯��ǰ���� explicit����,�����ʼ��ʱ���������Ը�ֵ��ʽ���θ����캯��
	// Dejan dejan = 10; error: ��ֹ��ʽת��
}

int main()
{
	test();

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//��������أ����Ƕ����е���������½��ж���
//������������ô��뿴�������Ӽ��
//��������ز��ܸı����������Ԣ��

class Dejan
{
public:
	Dejan(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
public:
	int a;
	int b;
};
//��������ؿ���д��ȫ�ֺ�����Ҳ����д�ɳ�Ա����
//��������صĺ����Ǳ�����ȥ����

//�����������ʵ����һ����ʽ�ĺ�������

//������ֻ��ȥ��operator�������������ܺ��������ʵ�ֺͷ���ֵ
Dejan operator+(Dejan &d1, Dejan &d2)
{
	Dejan tmp(d1.a + d2.a, d1.b + d2.b);
	return tmp;
}

void test()
{
	Dejan d1(10, 20);
	Dejan d2(30, 50);

	Dejan d3 = d1 + d2;
	cout << "d3.a=" << d3.a << " d3.b=" << d3.b << endl;
}

int main()
{
	test();

	system("pause");
	return 0;
}
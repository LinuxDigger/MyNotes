#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Dejan
{
public:
	Dejan(int a)
	{
		this->a = a;
	}
	// ǰ�üӼ�, ���ص�������
	Dejan& operator++()
	{
		++a;
		return *this;
	}
	// ���üӼӣ��ȷ��أ���Ӽ�  ���ص���ֵ
	// ���üӼ�, ���ص����¶���
	Dejan operator++(int) // ռλ����������int
	{
		// d++
		// *this�����a�Ƕ��٣�15
		Dejan tmp(*this); // ������ʲô���캯�����������캯��
		++this->a; // ��Ӽ�,*this��d
		return tmp;
	}
public:
	int a;
};

ostream& operator<<(ostream &out, Dejan &d)
{
	out << d.a;
	return out;
}

//ͬ�������£�����ʹ��ǰ�üӼӣ���Ϊ���üӼ���Ҫʵ����һ����ʱ������������Ҫ�������ο������캯��

// 1.ǰ�üӼӣ��ȼӼ��ٷ���
void test()
{
	Dejan d(10);
	cout << ++d << endl;
}

// 2.���üӼӣ��ȷ��أ���Ӽ�
void test2()
{
	Dejan d(15);
	cout << d++ << endl;
	cout << d << endl;
}

int main()
{
	test2();

	system("pause");
	return 0;
}
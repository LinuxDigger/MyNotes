#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Dejan
{
public:
	Dejan()
	{
		a = 10;
		b = 20;
	}
public:
	static int a; // ��̬��Ա����
	int b;
private:
	static int c;
};
//����
int Dejan::a = 100;
//1.��̬��Ա���������࣬�����ڶ���
//2.��̬��Ա���������������������������ʼ��
//3.��̬��Ա�����������������ʣ�Ҳ�����ö���������
//4.��̬��Ա���������������ڳ��������������������������

void test()
{
	cout << Dejan::a << endl;

	// 1.����ռ䣬2�����ù��캯��
	Dejan d;
	cout << d.a << endl;

	//Dejan *p = new Dejan[10];
}

int main()
{
	test();

	system("pause");
	return 0;
}
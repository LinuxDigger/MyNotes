#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//��̬��Ա�����ǹ���̬��Ա����
//��̬��Ա����ʹ�÷�ʽ�;�̬��Ա����һ��
//��̬��Ա���������޸ĺͷ�����ͨ��Ա���������ǿ��Է����޸ľ�̬��Ա����


class Dejan
{
public:
	static int func() // ��̬��Ա����
	{
		a = 200;

		// b = 20;��̬��Ա�������ǲ����޸���ͨ��Ա����,Ҳ���ܷ�����ͨ��Ա����
		return a;
	}

	void func2()
	{
		cout << a << endl;
	}
private:
	static int a;
	int b;
};
int Dejan::a = 100;

void test()
{
	cout << Dejan::func() << endl;
	Dejan d;
	d.func();
	d.func2();
}

int main()
{
	test();

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
/*  1.const ���εı�����ʱ�пռ�, ��ʱû�пռ�   */
const int a = 10;
const int aa = 20;

// 1) �������, a ��û�пռ�
void test()
{
	//cout << a << endl;  �������Ż���ֱ�Ӵ�ӡ10  �����۵�
	cout << a << endl;

	//int *p = &a;   error: ��Ϊaaû�пռ�,����ȡ��ַ����
}

// 2) constȫ�ֱ��� - �ǲ����Լ���޸ĵĺ�C������һ������Ϊ aa ����ȫ�־�̬������
void test01()
{
	// int *p = &aa;  error: ��Ϊaaû�пռ�,����ȡ��ַ����

	const int *p = &aa; // ��const�󲻱���
	//*p = 200;   error: ���ܼ���޸�
}

// 3) volatile �ؼ���
void test02()
{
	// volatile ��ֹ�������Ż�
	volatile const int a = 10; // ջ
	int *p = (int*)&a; // ������������۵������ǶԱ���ȡ��ַ�ˣ���ô����������пռ�

	*p = 100;
	cout << "a = " << a << endl; // 10  cout << "a = " << 10 << endl;  �����˳����۵�
	cout << "*p = " << *p << endl; // 100

	printf("a�ĵ�ַ: %p\n", &a);
	printf("pָ���ַ: %p\n", p);
}

// 4) ��������ʱ��û��������������ô���!
void test03() 
{
	int a = 10;
	const int b = a; // �������ڱ���׶��ǲ�֪��������ֵ��
	int *p = (int*)&b;
	*p = 100;
	cout << "b=" << b << endl;
	cout << "*p=" << *p << endl;
}

// 5) �����������Ż��Զ����������Ͷ���ı���
struct Dejan
{
	int age;
	Dejan() // ���캯��
	{
		age = 18;
	}
};
void test04()
{
	const Dejan dj;
	cout << "age=" << dj.age << endl;

	Dejan *p = (Dejan*)&dj;
	p->age = 28;
	cout << "jd.age=" << dj.age << endl;
	cout << "p->age=" << p->age << endl;
}

/*  2.const���ε�ȫ�ֱ��������ڲ���������  */
void test05()
{
	extern const int c; // ���Ҫ�����ⲿ����Ҳͬʱ�������ⲿ����ı�����extern����
	cout << c << endl;
}

int main()
{
	test05();

	system("pause");
	return 0;
}
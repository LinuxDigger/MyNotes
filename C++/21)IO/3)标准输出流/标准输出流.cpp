#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
using namespace std;

void test()
{
	cout.put('c');

	cout.put('h').put('e').put('l').put('l').put('o').put('\n');
	cout << "hello" << endl;
}

void test02()
{
	char buf[] = "hello";
	cout.write(buf, strlen(buf));
}

// ��ʽ��������ݣ�ͨ����Ա����
void test03()
{
	int num = 99;
	cout.width(20); // ���ÿ��
	cout.fill('*'); // ����ַ�
	cout.setf(ios::left); // �����ݷŵ����
	cout.unsetf(ios::dec); // ж��ʮ����
	cout.setf(ios::hex); // ��װʮ������
	cout.setf(ios::showbase); // ��ʾ����
	cout.unsetf(ios::hex);
	cout.setf(ios::oct);
	cout << num << endl;
}

// �ÿ��Ʒ���ʽ���������,����ͷ�ļ�iomanip
void test04()
{
	int num = 99;
	cout << setw(20); // ���ÿ��
	cout << setfill('~'); // ����ַ�
	cout << setiosflags(ios::left); // �����ݷŵ����
	cout << setiosflags(ios::showbase); // ��ʾ����
	cout << hex;
	cout << oct;
	cout << dec;
	cout << num << endl;
}

void test05()
{
	double d = 30.33;
	cout << setiosflags(ios::fixed);
	cout << setprecision(10) << d << endl; // 10��ʾ��ӡС�����λ
}

int main()
{
	test05();

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// new ��������,������������
void test01()
{
	// �Ӷ�������ռ�
	int *arr = new int[10];
	// malloc(sizeof(int)* 10);
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 1;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	double *arrd = new double[10];

	// new��ʱ���������ţ���ôdeleteʱ����ҲҪ��[]
	delete[] arr;
	delete[] arrd;
}

// ��,�Զ�����������
class Dejan
{
public:
	Dejan()
	{
		cout << "�޲ι���" << endl;
	}
	Dejan(int a)
	{
		cout << "�вι���" << endl;
	}
	~Dejan()
	{
		cout << "��������" << endl;
	}
};

// ��������
void test02()
{
	Dejan *p = new Dejan[2]; // �Ӷ�������2�������С�Ŀռ�
	delete[] p;

	// Dejan *q = new Dejan[2]{Dejan(10),Dejan(20)}; �󲿷ֱ�������֧��
}

int main()
{
	test02();

	system("pause");
	return 0;
}
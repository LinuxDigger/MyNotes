#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<thread>
#include<atomic> // ԭ��ͷ�����ļ�
using namespace std;

atomic<int> N = 0; // ʹ��atomic���Ա�֤��N������ԭ����

void ThreadFunc()
{
	for ( int i = 0; i < 1000000; ++i )
	{
		++N; // �̲߳������� �Ӳ��� �ص� ����ԭ�Ӳ���, ����п���С�� 2000000
	}
}

int main()
{
	thread t1(ThreadFunc);
	thread t2(ThreadFunc);

	t1.join();
	t2.join();

	cout << N << endl; // Ӧ����2000000

	system("pause");
	return 0;
}
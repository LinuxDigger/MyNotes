#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<future>
#include<thread>
using namespace std;
using namespace this_thread;
using namespace chrono;

// ��ʱ�Ĳ���
int work(int a, int b)
{
	cout << "��ʼ����:" << endl;
	sleep_for(seconds(5)); // ���Ǽ����ʱ5��
	return a + b;
}

int main()
{
	future<int> result = async(work, 123, 456); // move��ֵ����

	result.wait(); // �ȴ�������, �����Ż����ִ��
	cout << "������:" << endl;
	int sum = result.get(); // ��ȡ���
	cout << "���յĽ����:" << sum << endl;

	system("pause");
	return 0;
}
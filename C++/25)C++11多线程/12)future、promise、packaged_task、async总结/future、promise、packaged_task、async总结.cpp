#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<thread>
#include<future>
using namespace std;
using namespace this_thread;
using namespace chrono;

// ��ʱ����
void work_1(promise<int>& prom, int a, int b)
{
	cout << "work_1��ʼ����!" << endl;
	sleep_for(seconds(3));
	prom.set_value( a + b );
}

int work_2(int a, int b)
{
	cout << "work_2��ʼ����!" << endl;
	sleep_for(seconds(2));
	return a + b;
}

int work_3(int a, int b)
{
	cout << "work_3��ʼ����!" << endl;
	sleep_for(seconds(2));
	return a + b;
}

int main()
{
	// 1) promise�ڲ���װ��һ��ֵ
	promise<int> prom;
	future<int> f1 = prom.get_future(); // ʹ��get_future��Ա������ȡfuture
	thread(work_1, ref(prom), 1, 2).detach();
	f1.wait(); // �ȴ�ֵ����
	cout << "������:" << f1.get() << endl; // ��ȡ���


	// 2) packaged_task��װһ������
	packaged_task<int(int, int)> task(work_2);
	future<int> f2 = task.get_future(); // ʹ��get_future��Ա������ȡfuture
	thread(move(task),11,22).detach();
	f2.wait(); // �ȴ����
	cout << "������:" << f2.get() << endl; // ��ȡ���


	// 3) async�ڲ���һ���߳�
	future<int> f3 = async(work_3, 111, 222);
	f3.wait(); // �ȴ����
	cout << "������:" << f3.get() << endl; // ��ȡ���

	system("pause");
	return 0;
}
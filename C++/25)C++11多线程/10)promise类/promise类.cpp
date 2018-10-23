#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<future>
#include<thread>
using namespace std;
using namespace this_thread;
using namespace chrono;

// ��ʱ����
void work_1(promise<int>& prom)
{
	cout << "��ʼ����!" << endl;
	sleep_for(seconds(5));
	// promise���ý��ֵ
	cout << "�������!" << endl;
	prom.set_value(666); // ���ý��, future��get��
}

void work_2(promise<int>& prom)
{
	cout << "��ʼ����!" << endl;
	sleep_for(seconds(5));
	// promise���ý��ֵ
	try
	{
		throw runtime_error("����ʱ����!");
	}
	catch(...)
	{
		prom.set_exception(current_exception());
	}
}

void test_1()
{
	// ����һ��promise
	promise<int> prom;
	// future��promise����ʹ��, ������async
	future<int> result = prom.get_future();

	thread t1(work_1, ref(prom));
	t1.detach();

	int sum = result.get();
	cout << "��ȡ���:" << sum << endl;
}

void test_2()
{
	// ����һ��promise
	promise<int> prom;
	// future��promise����ʹ��, ������async
	future<int> result = prom.get_future();

	thread t1(work_2, ref(prom));
	t1.detach();

	try 
	{
		int sum = result.get();
		cout << "��ȡ���:" << sum << endl;
	}
	catch (exception& e)
	{
		cout << "����쳣" << e.what() << endl;
	}
}



int main()
{
	test_2();

	system("pause");
	return 0;
}
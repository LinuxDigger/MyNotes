#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
using namespace this_thread;
using namespace chrono;

int tickets = 100;

// ����һ���������
mutex m; // �����ظ�����
recursive_mutex m2; // ���Եݹ����
timed_mutex m3; // ����ָ����ס��ʱ��

recursive_timed_mutex m4; // �������ֵ��ۺ�

void SellThread_1(string& str) 
{
	while (tickets > 0)
	{
		m.lock(); // ����
		if (tickets > 0)
		{
			sleep_for(milliseconds(100)); // 100����
			printf("%s ���� %d ��Ʊ\n", str.c_str(), tickets--);
		}
		m.unlock(); // ����
	}
}

void SellThread_2(string& str)
{
	while (tickets > 0)
	{
		m2.lock(); // ����
		m2.lock(); // �ٴμ���
		if (tickets > 0)
		{
			sleep_for(milliseconds(100)); // 100����
			printf("%s ���� %d ��Ʊ\n", str.c_str(), tickets--);
		}
		m2.unlock(); // ����
		m2.unlock(); // ����
	}
}

void SellThread_3(string& str)
{
	while (tickets > 0)
	{
		m3.try_lock_for(seconds(3)); // ����, ��ס3��
		if (tickets > 0)
		{
			sleep_for(milliseconds(100)); // 100����
			printf("%s ���� %d ��Ʊ\n", str.c_str(), tickets--);
		}
		//m3.unlock(); // ����, ��Ϊtry_lock_for 3�����Զ��������Բ���Ҫ����
	}
}

void SellThread_4(string& str)
{
	while (tickets > 0)
	{
		m4.try_lock_for(seconds(3)); // ����, ��ס3��
		m4.try_lock_for(seconds(3)); // ����, ��ס3��
		if (tickets > 0)
		{
			sleep_for(milliseconds(100)); // 100����
			printf("%s ���� %d ��Ʊ\n", str.c_str(), tickets--);
		}
		//m4.unlock(); // ����, ��Ϊtry_lock_for 3�����Զ��������Բ���Ҫ����
	}
}

// mutex
void test_1()
{
	thread t1(SellThread_1, string("��Ʊ����A:"));
	thread t2(SellThread_1, string("��Ʊ����B:"));

	t1.join();
	t2.join();
}

// recursive_mutex
void test_2()
{
	thread t1(SellThread_2, string("��Ʊ����A:"));
	thread t2(SellThread_2, string("��Ʊ����B:"));

	t1.join();
	t2.join();
}

// timed_mutex
void test_3()
{
	thread t1(SellThread_3, string("��Ʊ����A:"));
	thread t2(SellThread_3, string("��Ʊ����B:"));

	t1.join();
	t2.join();
}

// recursive_timed_mutex
void test_4()
{
	thread t1(SellThread_4, string("��Ʊ����A:"));
	thread t2(SellThread_4, string("��Ʊ����B:"));

	t1.join();
	t2.join();
}

int main()
{
	test_3();

	system("pause");
	return 0;
}
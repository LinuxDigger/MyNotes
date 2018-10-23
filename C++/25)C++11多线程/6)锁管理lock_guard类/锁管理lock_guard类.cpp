#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<mutex>
#include<thread>
#include<stdexcept>
using namespace std;
using namespace this_thread;

mutex m;

void ThreadFunc_1()
{
	try {
		for (int i = 0; i < 10; ++i)
		{
			m.lock();
			if (i == 3) throw logic_error("�����쳣!");
			cout << "A��ӡ" << i << endl;
			m.unlock(); // �쳣�׳�ʱ,����û��unlock,ʹ��B�޷���ȡmutex, ����
			sleep_for(chrono::seconds(1));
		}
	}
	catch (logic_error& e)
	{
		cout << "����" << e.what() << endl;
	}
	
}

void ThreadFunc_2()
{
	for (int i = 0; i < 10; ++i)
	{
		m.lock();
		cout << "B��ӡ" << i << endl;
		m.unlock();
		sleep_for(chrono::seconds(1));
	}
}

void ThreadFunc_3()
{
	try {
		for (int i = 0; i < 10; ++i)
		{
			{
				lock_guard<mutex> lk(m);
				if (i == 3) throw logic_error("�����쳣!");
				cout << "A��ӡ" << i << endl;
			}
			sleep_for(chrono::seconds(1));
		}
	}
	catch (logic_error& e)
	{
		cout << "����" << e.what() << endl;
	}

}

void test_1()
{
	thread t1(ThreadFunc_1);
	thread t2(ThreadFunc_2);

	t1.join();
	t2.join();
}

void test_2()
{
	thread t1(ThreadFunc_3);
	thread t2(ThreadFunc_2);

	t1.join();
	t2.join();
}

int main()
{
	test_2();

	system("pause");
	return 0;
}
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
			// unique_lockʹ�ø������, �� lock_guard������� �������� lock()��unlock()
			unique_lock<mutex> lk(m); // unique_lock ���Զ��������Զ�����, ��ȻҲ���� ���� ����&����������������
			if (i == 3) throw logic_error("�����쳣!");
			cout << "A��ӡ" << i << endl;
			lk.unlock();
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



void test()
{
	thread t1(ThreadFunc_1);
	thread t2(ThreadFunc_2);

	t1.join();
	t2.join();
}

int main()
{
	test();

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<thread>
using namespace std;
// �����ռ�this_thread �е��̸߳�������: get_id() yield() sleep_for() sleep_util()
using namespace this_thread;
// �����ռ�chrono ��secondsģ���ࡢmillisecondsģ����
using namespace chrono;

// thread������"��������"����std::this_thread�����ռ���

void ThreadFun(string& str)
{
	cout << "�߳�ID:" << get_id() << endl; // ��ȡ��ǰִ���߳�ID
	while (1) 
	{
		cout << str << endl;
		//sleep_for(seconds(1)); // ���߳�˯��1��

		yield(); // ���߳�˯��һ����С��ʱ��Ƭ, �������߳�ִ��

		sleep_until(system_clock::now() + milliseconds(1000)); // ��ǰʱ��+1��
	}
}

int main()
{
	thread t1(ThreadFun, string("Hello"));
	cout << "�߳�ID:"<<t1.get_id() << endl;

	// �ȴ����߳����
	t1.join();

	system("pause");
	return 0;
}
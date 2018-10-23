#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<mutex>
#include<condition_variable>
using namespace std;
using namespace this_thread;
using namespace chrono;

condition_variable cv; // ��֧��unique_lock<mutex>��Ϊwait()�Ĳ���
condition_variable_any cv2; // �����κ�lockable��Ϊwait()�Ĳ���
mutex m;

void ThreadFunc_1(int id)
{
	unique_lock<mutex> lc(m);
	cv.wait(lc); // �ȴ�������

	cout << "�߳�ID:" << id << "ִ��!" << endl;
}

void ThreadFunc_2(int id)
{
	unique_lock<mutex> lc(m);
	cv2.wait(lc);

	cout << "�߳�ID:" << id << "ִ��!" << endl;
}

void test_1()
{
	thread t1(ThreadFunc_1, 1);
	thread t2(ThreadFunc_1, 2);
	thread t3(ThreadFunc_1, 3);

	cout << "3�����: " << endl;
	sleep_for(seconds(3)); // 3��֮���������߳�

	//cv.notify_all(); // ��������

	cv.notify_one(); // ֻ����һ��
	cv.notify_one();

	t1.join();
	t2.join();
	t3.join();
}

void test_2()
{
	thread t1(ThreadFunc_2, 1);
	thread t2(ThreadFunc_2, 2);
	thread t3(ThreadFunc_2, 3);

	cout << "3�����: " << endl;
	sleep_for(seconds(3)); // 3��֮���������߳�

	cv2.notify_all();

	t1.join();
	t2.join();
	t3.join();
}

int main()
{
	test_2();

	system("pause");
	return 0;
}
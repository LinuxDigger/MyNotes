#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<future>
#include<thread>
using namespace std;
using namespace this_thread;
using namespace chrono;

int work(int a, int b)
{
	cout << "��ʼ����!" << endl;
	sleep_for(seconds(5)); // �����ʱ����
	cout << "��������!" << endl;
	return a + b;
}

int main()
{
	// packaged_task��װ��һ���ɵ��õ�Ŀ��
	packaged_task<int(int, int)> pack(work);

	future<int> result = pack.get_future(); // ��ȡpackaged_task�ڲ���future

	thread t1( move(pack), 123, 456);
	t1.detach();

	int sum = result.get();
	cout << "��ȡ���:" << sum << endl;

	system("pause");
	return 0;
}
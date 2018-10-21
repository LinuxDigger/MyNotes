#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
using namespace std;

mutex _mutex;

// *ע��: ʹ������& ������ list ��task_1(queue<int>& list) ,���������!����ʹ�ô�ַ!
void task_1(queue<int> *list)
{
	for (int i = 0; i<1000; ++i)
	{
		lock_guard<mutex> guard(_mutex);
		list->push(i);
	}
	cout << "task_1 The End!" << endl;
}

void task_2(queue<int> *list)
{
	while (!list->empty())
	{
		{
			lock_guard<mutex> guard(_mutex);
			cout << list->front() << endl;
			list->pop();
		}
	}
	cout << "task_2 The End!" << endl;
}

class Test
{
public:
	void task_2(queue<int> *list)
	{
		while (1)
		{
			if (list->empty())
				continue;
			{
				lock_guard<mutex> guard(_mutex);
				cout << list->front() << endl;
				list->pop();
			}
		}
	}
};

int main()
{
	queue<int> list;
	Test t;

	thread t1(task_1, &list);
	thread t2(task_2, &list); // ����ȫ�ֺ���
	//thread t2(&Test::task_2,t, &list); // ���ó�Ա����
	t1.detach();
	t2.join();

	//getchar();

	//task_1(list);
	//task_2(list);

	system("pause");
	return 0;
}
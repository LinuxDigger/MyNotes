#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<thread>
#include<atomic>
#include<vector>
using namespace std;
using namespace this_thread;

atomic<bool> ready = false; // �Ƿ�����

atomic_flag win = ATOMIC_FLAG_INIT; // �յ���

void Run(int id)
{
	// ǹû��, ������
	while (!ready)
	{
		yield(); // �������߳���ִ��
	}

	// ��ʾ�ܵĹ���
	for (int i = 0; i < 100000; ++i){}

	// ���û�б����ù�, ����false
	if (!win.test_and_set()) // ����һ�κ�, �´ε��÷���true
	{
		cout << id << "��ѡ��Ӯ�õ�һ��!"<<endl;
	}
}

int main()
{
	// 10��ѡ������
	vector<thread> vecPlayers;
	for (int i=0;i<=10;++i)
	{
		vecPlayers.push_back(thread(Run, i));
	}
	cout << "10��ѡ����׼����!" << endl;

	// ׼��������: Ԥ����
	sleep_for(chrono::seconds(3));
	cout << "3��2��1 Ԥ��.. ��!" << endl;

	ready = true;

	// �ȴ�����ѡ������
	for (thread& t:vecPlayers) 
	{
		t.join();
	}

	system("pause");
	return 0;
}
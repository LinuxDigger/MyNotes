#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Dejan
{
	// �����ȫ�ֺ�����ΪDejan����Ԫ����
	friend void func(Dejan &dejan);
public:
	Dejan(string name)
	{
		this->name = name;
	}
private:
	string name;
};

// ȫ�ֺ���
void func(Dejan &dejan)
{
	cout << dejan.name << endl;
}

void test()
{
	Dejan dejan("С���");
	func(dejan);
}

int main()
{
	test();

	system("pause");
	return 0;
}
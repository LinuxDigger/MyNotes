#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<string>
using namespace std;

/*
stack<T> stkT;//stack����ģ����ʵ�֣� stack�����Ĭ�Ϲ�����ʽ��
stack(const stack &stk);//�������캯��

*/
//�Ƚ����

//1.�Ż�����������
void test01()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	while (!s.empty())
	{
		// ���ջ��Ԫ��
		cout << s.top() << endl;
		// ����ջ��Ԫ��
		s.pop();
	}

	cout << "size:" << s.size() << endl;
}

// 2.�洢����
class Dejan
{
public:
	Dejan(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
public:
	string name;
	int age;
};

void test02()
{
	stack<Dejan> s;
	s.push(Dejan("aaa1", 10));
	s.push(Dejan("aaa2", 20));
	s.push(Dejan("aaa3", 30));
	while (!s.empty())
	{
		// ���ջ��Ԫ��
		cout << s.top().name << " " << s.top().age << endl;
		// ����ջ��Ԫ��
		s.pop();
	}

	cout << "size:" << s.size() << endl;
}

int main()
{
	test02();

	system("pause");
	return 0;
}
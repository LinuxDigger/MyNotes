#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Dejan
{
	friend ostream& operator<<(ostream &out, Dejan &d);
public:
	Dejan()
	{
		age = 18;
	}
private:
	int age;
};

// ostream�ѿ������캯��˽�л��ˣ��������ﲻ�ܷ���ֵ������ֵ��Ҫ���ÿ������캯��
ostream& operator<<(ostream &out, Dejan &d)
{
	out << d.age;
	return out;
}

int main()
{
	//basic_ostream
	Dejan d;
	cout << d << endl;

	int a = 10;
	cout << a;

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

// ������
class Girl;
class Student
{
public:
	void func(Girl &girl);
};

class Girl
{
	// ����ĳ�Ա������Ϊ��һ�������Ԫ����
	friend void Student::func(Girl &girl); // Student�ĳ�Ա����
public:
	Girl(string name)
	{
		this->name = name;
	}
private:
	string name;
};

void Student::func(Girl &girl)
{
	cout << girl.name << endl;
}

void test()
{
	Girl girl("С���");

	Student s;
	s.func(girl);
}

int main()
{
	test();

	system("pause");
	return 0;
}
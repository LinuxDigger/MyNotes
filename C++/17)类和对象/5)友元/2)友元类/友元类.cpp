#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Girl
{
	// ��Student���ΪGirl�����Ԫ��
	friend class Student;
public:
	Girl(string name)
	{
		this->name = name;
	}
private:
	string name;
};

// �����Ϊ��һ�����Ԫ��
class Student
{
public:
	void func(Girl &girl)
	{
		cout << girl.name << endl;
	}
};

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
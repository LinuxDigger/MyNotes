#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	// ���������ķ���
	void setName(string Name)
	{
		name = Name;
	}
	// ����id�ķ���
	void setID(int Id)
	{
		id = Id;
	}
	// ��ӡ������id�ķ���
	void printStudent()
	{
		cout << "name:" << name << " id:" << id << endl;
	}
public:
	string name;
	int id;
};

int main()
{
	Student s;
	s.setName("С���");
	s.setID(1);
	s.printStudent();

	cout << s.name << " " << s.id << endl;

	system("pause");
	return 0;
}
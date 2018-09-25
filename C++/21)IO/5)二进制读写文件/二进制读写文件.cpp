#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Maker
{
public:
	Maker()
	{}
	Maker(const char*name, int age)
	{
		strcpy(this->name, name);
		this->age = age;
	}
public:
	//��д����ʱ����Ҫ������дstring���͵ı���
	//string name;
	/*
	ԭ��һ��
	string��������ռ�Ĳ��ԣ�16���ֽ���ջ��������16���ֽ��ڶ�����string�ڲ���һ��ָ�룬ָ������ռ䣩
	�ļ�д
	ԭ�����
	ָ��д���ļ�����Ч
	*/

	char name[64];
	int age;
};

void test01()
{
	Maker m1("���", 18);
	Maker m2("������", 20);

	ofstream ofs;
	ofs.open("test.txt", ios::out | ios::trunc | ios::binary);
	if (!ofs.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
	}

	//д����
	ofs.write((const char *)&m1, sizeof(Maker));
	ofs.write((const char *)&m2, sizeof(Maker));

	ofs.close();
}

void test02()
{
	Maker m1;
	Maker m2;

	ifstream ifs;
	ifs.open("test.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
	}

	//������
	ifs.read((char*)&m1, sizeof(Maker));
	ifs.read((char*)&m2, sizeof(Maker));

	ifs.close();

	cout << "name:" << m1.name << " age" << m1.age << endl;
	cout << "name:" << m2.name << " age" << m2.age << endl;
}

int main()
{
	test02();

	system("pause");
	return EXIT_SUCCESS;
}


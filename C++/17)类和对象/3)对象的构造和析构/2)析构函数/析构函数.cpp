#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Girl
{
public:
	Girl(){}
	Girl(const char *str, int age)
	{
		cout << "�вι��캯��" << endl;
		name = (char*)malloc(strlen(str) + 1);
		strcpy(name, str);
		this->age = age;
	}

	void printGirl()
	{
		cout << "name:" << name << " age:" << age << endl;
	}

	// ��������
	~Girl()
	{
		cout << "��������" << endl;
		if (NULL != name)
		{
			free(name);
			name = NULL;
		}
	}
public:
	char *name;
	int age;
};

void test()
{
	//Girl girl;  // ���û��Զ������вι��캯��, �����������ṩ��Ĭ�ϵĹ��캯��, ����Ҫ�޲ι��캯�����û��ֶ�����
	Girl girl("С���", 18);
	girl.printGirl();
}

int main()
{
	test();

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

/*struct Myfunc
{
	void operator()(int val)
	{
		cout << val << " " << endl;
	}
};*/

//������������
//��ӡ���������ݶ�����10
//���亯������Ĳ���:
//1.�̳�binary_function
//2.Ҫ�Ѳ�����Ϊ2��
//3.Ҫ�����غ�����Ϊ������
struct Myfunc
	:public binary_function<int, int, void>
{
	void operator()(const int v1, const int v2) const
	{
		cout << v1 + v2 << " " << endl;
	}
};

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//for_each(v.begin(),v.end(), Myfunc());

	//4.��������
	//bind2nd 
	for_each(v.begin(), v.end(), bind2nd(Myfunc(), 10));
}

//��ͨ��������
//1.��ȫ�ֺ����Ĳ�����Ϊ2��
void Myprint(int v1, int v2)
{
	cout << v1 + v2 << " " << endl;
}

void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//for_each(v.begin(), v.end(), Myprint);

	//2.����ͨ������Ϊ��������
	//ptr_fun
	//3.��������
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(Myprint), 10));
}

//��Ա��������
//mem_fun��Ӧ����ָ��  mem_fun_ref��Ӧ����
class Dejan
{
public:
	Dejan(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	void PrintDejan()
	{
		cout << "��Ա������ӡ:" << this->name << " " << this->age << endl;
	}
public:
	string name;
	int age;
};

void test03()
{
	vector<Dejan> v;
	v.push_back(Dejan("aaa1", 10));
	v.push_back(Dejan("aaa1", 20));
	v.push_back(Dejan("aaa1", 30));
	v.push_back(Dejan("aaa1", 40));
	v.push_back(Dejan("aaa1", 50));

	for_each(v.begin(), v.end(), mem_fun_ref(&Dejan::PrintDejan));
	cout << "---------------------------" << endl;

	vector<Dejan*> vp;
	vp.push_back(new Dejan("bbb1", 10));
	vp.push_back(new Dejan("bbb2", 20));
	vp.push_back(new Dejan("bbb3", 30));
	vp.push_back(new Dejan("bbb4", 40));
	vp.push_back(new Dejan("bbb5", 50));
	for_each(vp.begin(), vp.end(), mem_fun(&Dejan::PrintDejan));
}

//ȡ������not1(һԪ��������ȡ��) not2(��Ԫ��������ȡ��)
//1.�̳�unary_function
//2.�����غ�����Ϊ������
struct Myfunc2
	:public unary_function<int, bool>
{
	bool operator()(int val) const
	{
		return val >= 40;
	}
};
void test04()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//find_if()
	//3.��������
	vector<int>::iterator it = find_if(v.begin(), v.end(), not1(Myfunc2()));
	if (it == v.end())
	{
		cout << "����ʧ��" << endl;
	}
	else
	{
		cout << "���ҳɹ�" << *it << endl;//10
	}
}

int main()
{
	test04();

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

//���Ҫ���㺯�������õĴ���
int a = 0;//����Ҫ����ʹ��ȫ�ֱ��������̣߳�ȫ�ֱ������Ϊ������Դ
void func()
{
	a++;
	cout << a << endl;
}
//�º���Ҳ�к�������
struct Myfunc {
public:
	Myfunc()
	{
		age = 0;
	}
	void operator()()
	{
		cout << "hello" << endl;
		age++;
	}
public:
	int age;
};

//1.���ʹ�ú������󣬾Ͳ���ʹ��ȫ�ֱ���
//2.������ĺ�����Ĭ�ϳ�Ϊ��������
//3.ȫ�ֺ���һ�㲻���Ϊ����������������ȡ��ַ�������Ͳ����Ϊ��������

void test01()
{
	Myfunc func;
	for (int i = 0; i < 10; i++)
	{
		//func(); // ȫ�ֺ���
		func(); // ��������
	}
	cout << func.age << endl;

}

//�ڽ��ĺ�������
//���������Ǻ������Ƕ���
void test02()
{
	plus<int> myplus;
	cout << myplus(10, 20) << endl;

	vector<int> v;
	v.push_back(2);
	v.push_back(1);
	v.push_back(9);
	v.push_back(6);
	v.push_back(3);
	//�����������Ҫ��(),��������Ҫ
	sort(v.begin(), v.end(),greater<int>());//Ĭ��������Ҫ��Ϊ����

	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}

int main()
{
	test02();

	system("pause");
	return 0;
}
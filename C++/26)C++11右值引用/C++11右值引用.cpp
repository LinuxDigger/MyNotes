#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyClass
{
public:
	void init(int & intval)
	{
		cout << "use & print" << endl;
	};
	void init(int &&intval)
	{
		cout << "use && print" << endl;
	}
};

int main()
{
	int ae = 10;
	MyClass().init(10);   // use && print
	MyClass().init(ae);   // use & print

	/*
		��ֵ����������֧��ת������ġ�ת��������Խ���Դ ( �ѣ�ϵͳ����� )
		��һ������ת�Ƶ���һ�����������ܹ����ٲ���Ҫ����ʱ����Ĵ����������Լ����٣�
		�ܹ��������� C++ Ӧ�ó�������ܡ�����:��ʱ�����ά�� ( ���������� ) �����������������ĵġ�
	*/

	system("pause");
	return 0;
}
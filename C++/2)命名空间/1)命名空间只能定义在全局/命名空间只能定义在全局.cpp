#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//�����ռ����ö��˵ķ��������Բ�������
//���������ռ䣬namespace�ؼ���
namespace A
{
	void test()
	{
		cout << "A" << endl;
	}
	int b = 30;
}

//�����ռ��ע��:
//ע��1�������ռ�ֻ�ܶ�����ȫ��
void test() 
{
	/*namespace B{
	        error !
	}*/
}

int main()
{
	A::test();
	cout << A::b << endl;

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//��ֻ��ʵ����һ������
//1.���޲ι��캯��˽�л�
//2.����һ����̬��Ա���������ָ�룩
//3.������newһ����������ָ��
//4.Ϊ�˷�ֹ�û�����������ָ���ÿգ���ô�����ָ������Ϊ˽�У�
//���ṩһ����ȡ���ָ��ľ�̬��Ա����
//5.��Ϊ�������캯������ʱҲ�������µĶ�����ʱ�ѿ������캯��Ҳ˽�л�

class Dejan
{
public:
	static Dejan *getObj() // ��̬��Ա����
	{
		return p;
	}
private:
	Dejan() {}
	Dejan(const Dejan &dejan)
	{
		cout << "�������캯��" << endl;
	}
private:
	static Dejan* p; // ����һ����̬��Ա����
};
Dejan* Dejan::p = new Dejan; // ��һ������

void test()
{
	Dejan *myp = Dejan::getObj();
	Dejan *myp2 = Dejan::getObj();
	Dejan *myp3 = Dejan::getObj();
	Dejan *myp4 = Dejan::getObj();

	cout << "myp=" << myp << endl;
	cout << "myp2=" << myp2 << endl;
	cout << "myp3=" << myp3 << endl;
	cout << "myp4=" << myp4 << endl;
}

int main()
{
	test();

	system("pause");
	return 0;
}
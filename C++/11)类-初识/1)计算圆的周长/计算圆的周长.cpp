#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Circle
{ // ���Ĭ��Ȩ����˽��
public: // ����Ȩ��

	// ���ð뾶
	void setR(double r)
	{
		mR = r;
	}

	// ���ܳ�
	double getL()
	{
		return 2 * 3.14 * mR;
	}

	double mR; // �뾶
	// double a = 10; // ���鲻Ҫ������ֱ�Ӹ�ֵ
	string name;
};

int main()
{
	//���Զ�����������Ͷ������
	//����ʵ��������
	Circle c;
	c.setR(100);
	cout << c.getL() << endl;

	system("pause");
	return 0;
}
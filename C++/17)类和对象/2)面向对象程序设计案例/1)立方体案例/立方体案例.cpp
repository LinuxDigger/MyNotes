#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Cube 
{
public:
	void init()
	{
		mL = 0;
		mW = 0;
		mH = 0;
	}
	void setL(int l)
	{
		mL = l;
	}
	int getL()
	{
		return mL;
	}
	void setW(int w)
	{
		mW = w;
	}
	int getW()
	{
		return mW;
	}
	void setH(int h)
	{
		mH = h;
	}
	int getH()
	{
		return mH;
	}

	// ������������
	int caculaS()
	{
		return 2 * mL * mW + 2 * mL * mH + 2 * mW * mH;
	}

	// ������������
	int caculaV()
	{
		return mL*mW*mH;
	}
	// ��Ա�������ж�
	// �ж������������Ƿ���ȣ��������߶���ȣ�����Ϊ������������ȣ�
	bool compareCube(Cube c1)
	{
		if (getH() == c1.getH() && getW() == c1.getW() && getL() == c1.getL())
		{
			return true;
		}
		return false;
	}
private:
	int mL;
	int mW;
	int mH;
};

// ȫ�ֺ����ж�
bool MycompareCube(Cube c1, Cube c2)
{
	if (c2.getH() == c1.getH() && c2.getW() == c1.getW() && c2.getL() == c1.getL())
	{
		return true;
	}
	return false;
}

int main()
{
	// 1.����ռ䣬2.��ʼ������
	Cube m1;
	m1.init();
	Cube m2;
	m2.init();

	m1.setH(10);
	m1.setL(10);
	m1.setW(10);

	m2.setH(10);
	m2.setL(10);
	m2.setW(10);

	bool ret = m1.compareCube(m2);
	if (ret)
	{
		cout << "�������������" << endl;
	}
	else
	{
		cout << "���������岻���" << endl;
	}

	if (MycompareCube(m1,m2))
	{
		cout << "ȫ�ֺ����ж��������������" << endl;
	}
	else
	{
		cout << "ȫ�ֺ����ж����������岻���" << endl;
	}

	system("pause");
	return 0;
}
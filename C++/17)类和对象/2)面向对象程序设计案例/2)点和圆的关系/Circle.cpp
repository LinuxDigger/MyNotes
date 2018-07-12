#include "Circle.h"

void Circle::setR(int r)
{
	mR = r;
}

int Circle::getR()
{
	return mR;
}

void Circle::setHear(Point &hear)
{
	mHear.setX(hear.getX());
	mHear.setY(hear.getY());
}
void Circle::setHear(int x, int y)
{
	mHear.setX(x);
	mHear.setY(y);
}

Point Circle::getHear()
{
	return mHear;
}

// �жϵ��Բ�Ĺ�ϵ
void Circle::isCircleByPoint(Point &point)
{
	// ��ȡ�뾶��ƽ��
	double Tr = pow(mR, 2);
	// ��ȡ�㵽Բ�ľ����ƽ��(x2-x1)^2+(y2-y1)^2
	double distance = pow(point.getX() - mHear.getX(), 2) + pow(point.getY() - mHear.getY(), 2);

	if (distance > Tr)
	{
		cout << "����Բ��" << endl;
	}
	else if (distance == Tr)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}
}

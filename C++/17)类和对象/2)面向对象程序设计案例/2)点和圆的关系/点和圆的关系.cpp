#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"Circle.h"

// ȫ�ֺ����жϵ��Բ�Ĺ�ϵ
void isCircleToPoint(Circle &c, Point &p)
{
	// ��ȡ�뾶��ƽ��
	double Tr = pow(c.getR(), 2);
	// ��ȡ�㵽Բ�ľ����ƽ��(x2-x1)^2+(y2-y1)^2
	double distance = pow(p.getX() - c.getHear().getX(), 2) + pow(p.getY() - c.getHear().getY(), 2);

	if (distance > Tr)
	{
		cout << "ȫ���жϵ���Բ��" << endl;
	}
	else if (distance == Tr)
	{
		cout << "ȫ���жϵ���Բ��" << endl;
	}
	else
	{
		cout << "ȫ���жϵ���Բ��" << endl;
	}
}

int main()
{
	// ʵ����Բ����
	Point point;
	point.setX(30);
	point.setY(10);

	// ʵ����Բ����
	Circle circle;
	circle.setR(10);
	circle.setHear(10, 10);

	circle.isCircleByPoint(point);

	isCircleToPoint(circle, point);

	system("pause");
	return 0;
}
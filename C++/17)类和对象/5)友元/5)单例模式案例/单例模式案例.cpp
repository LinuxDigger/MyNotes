#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Printer
{
public:
	static Printer* getObj()
	{
		return p;
	}

	void PrinterPrint(string name)
	{
		count++;
		cout << name << "��ӡ" << endl;
	}
	int getcount()
	{
		return count;
	}
private:
	Printer()
	{
		count = 0;
	}
	Printer(const Printer &p) {}
private:
	static Printer* p;
	int count; // �����ӡ����
};
Printer* Printer::p = new Printer;

void test()
{
	Printer *p1 = Printer::getObj();
	p1->PrinterPrint("������");
	Printer *p2 = Printer::getObj();
	p1->PrinterPrint("���۲�");
	Printer *p3 = Printer::getObj();
	p1->PrinterPrint("������");
	Printer *p4 = Printer::getObj();
	cout << "count:" << p4->getcount() << endl;
}

int main()
{
	test();

	system("pause");
	return 0;
}
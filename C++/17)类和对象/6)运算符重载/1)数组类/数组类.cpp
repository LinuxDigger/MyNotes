#include "Myarr.h"

void printMyarr(Myarr &arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr.getPosByVal(i) << " ";
	}
	cout << endl;
}

void test()
{
	// 1.����ռ䣬2.���ù��캯��
	Myarr myarr(20, 1);
	printMyarr(myarr);

	for (int i = 0; i < myarr.getSize(); i++)
	{
		myarr.getPosByVal(i) = 100 + i;
	}
	printMyarr(myarr);

	// ͷɾ��, βɾ��
	myarr.PopFront();
	myarr.PopBack();
	printMyarr(myarr);

	// ͷ��, β��
	myarr.PushFront(2);
	myarr.PushBack(10);
	printMyarr(myarr);

	// ָ��λ�ò���Ԫ��
	myarr.PopFront();
	myarr.PopBack();

	myarr.InserArr(3, 666);
	printMyarr(myarr);

	// ָ��λ���޸�Ԫ��
	myarr.setPosByVal(2, 888);
	printMyarr(myarr);
	cout << "------------------------" << endl;
	Myarr myarr2(myarr);
	printMyarr(myarr2);
}

int main()
{
	test();

	system("pause");
	return 0;
}
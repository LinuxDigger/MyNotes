#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// �����
class Animal
{
public:
	Animal()
	{
		age = 80;
	}
public:
	int age;
};

// ��̳�
class Sheep :virtual public Animal
{
	// int age
};

class Camel :virtual public Animal
{
	// int age
};

class SheepCamel :public Sheep, public Camel
{
	//int age  --Sheep
	//int age --Camel
};


// ֤��"��̳�"�����麯������һ��ָ��
void test()
{
	SheepCamel sp;
	cout << *((int*)(*((int*)&sp + 1)) + 1) << endl;
}

int main()
{
	// class a {}; һ������Ĵ�С��1�ֽ�

	test();
	/* ͨ��cl����鿴�̳��еĶ���ģ��  ��Ŀ�������� >> C/C++ >> ������ "/d1 reportSingleClassLayoutSheepCamel"
	1>  class SheepCamel	size(12):
	1>  	+---
	1>   0	| +--- (base class Sheep)
	1>   0	| | {vbptr}
	1>  	| +---
	1>   4	| +--- (base class Camel)
	1>   4	| | {vbptr}
	1>  	| +---
	1>  	+---
	1>  	+--- (virtual base Animal)
	1>   8	| age
	1>  	+---
	1>
	1>  SheepCamel::$vbtable@Sheep@:
	1>   0	| 0
	1>   1	| 8 (SheepCameld(Sheep+0)Animal)
	1>
	1>  SheepCamel::$vbtable@Camel@:
	1>   0	| 0
	1>   1	| 4 (SheepCameld(Camel+0)Animal)
	1>  vbi:	   class  offset o.vbptr  o.vbte fVtorDisp
	1>            Animal       8       0       4 0
	*/

	system("pause");
	return 0;
}
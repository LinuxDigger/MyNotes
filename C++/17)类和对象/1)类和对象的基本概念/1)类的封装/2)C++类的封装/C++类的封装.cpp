#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// ��װ��1.�ѱ��������ԣ��ͺ�������������װ��һ��
// 2.����Щ���ݸ���Ȩ��

// ��
// �Զ�����������
class Dejan
{ // ����
public:
	// ���Ĭ�Ϸ���Ȩ����˽��
	void func()
	{
		illness;
		mFace;
		son;
	}
public: // ����, ˭�����Է���
	int mFace;
private: // ˽��, ֻ�����Լ����Է���
	int illness;
protected: // ����, ֻ�����������Է���
	int son;
};

class Son :public Dejan
{
	void func()
	{
		mFace; // ����
		// illness;
		son; // ����
	}
};

//�ܽ᣺
/*
1.����Ȩ�޵�����˭�����Է���
2.˽��Ȩ��ֻ���Լ�����
3.����Ȩ����������ڿ��Է���
4.������û��Ȩ��֮��
*/

// ��װ���ԣ��������ԣ������������ṩ��ӡ���Եķ���
class MyPc
{
public:
	int cpu;
	int size;
	int RAM;
public:
	void SetCpu(int Cpu)
	{
		cpu = Cpu;
	}
	void SetSize(int Size)
	{
		size = Size;
	}
	void SetRAM(int ram)
	{
		RAM = ram;
	}
	void PrintPc()
	{
		cout << cpu << " " << size << " " << RAM << endl;
	}
};

int main()
{
	Dejan dejan;
	dejan.func();
	dejan.mFace;
	cout << "-------------------------" << endl;
	MyPc pc;
	pc.SetCpu(16);
	pc.SetRAM(32);
	pc.SetSize(15);

	pc.PrintPc();

	system("pause");
	return 0;
}
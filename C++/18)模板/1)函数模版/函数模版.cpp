#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void mySwapInt(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void mySwapDouble(double &a, double &b)
{
	double tmp = a;
	a = b;
	b = tmp;
}

void test()
{
	int a = 10;
	int b = 20;

	double a1 = 10.10;
	double b1 = 20.20;
	mySwapInt(a, b);
	mySwapDouble(a1, b1);
}

// ���߱����������ŵĺ�������T���㲻Ҫ����
template<class T> // T��������������ͣ���һ����T��T1 T2 M
void mySwap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
void func(T &a)
{

}

void test2()
{
	int a = 10;
	int b = 20;

	double a1 = 10.10;
	double b1 = 20.20;
	// ���������Զ��Ƶ���������
	mySwap(a, b);
	/*�ں�������ʱ�����ģ�溯��
	void mySwap(int &a,int &b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	*/
	mySwap(a1, b1);
	/*
	void mySwap(double &a,double &b)
	{
		double tmp = a;
		a = b;
		b = tmp;
	}
	*/
	// ��������Ժ���ģ�����ģ����ж��α���
	cout << "a=" << a << " b=" << b << endl;
	cout << "a1=" << a1 << " b1" << b1 << endl;

	int a2 = 10;
	char c = 'a';
	// ����Ĳ������ͱ���һ��
	// mySwap(a2, c); error

	mySwap<int>(a, b); // <int>�����б�
	//mySwap<int>(a1, b1);//��ʾ�ĸ��߱���������ʲô�������ͣ��ͱ��봫��ʲô��������

	//mySwap<double>();  error
	//mySwap();err

	//�ú���ģ��ʵ�ֶ�char��int���͵����ݽ�������(ѡ�����򣬴Ӵ�С)����ӡ
}

template<class T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i; // ����������ݵ��±�
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			// ���н���
			mySwap(arr[max], arr[i]);
		}
	}
}

template<class T>
void myPrint(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test03()
{
	char str[] = "hello";
	int len = sizeof(str) / sizeof(char);
	myPrint(str, len);
	mySort(str, len);
	myPrint(str, len);
	cout << "---------------------------" << endl;
	int arr[] = { 3,7,2,1 };
	len = sizeof(arr) / sizeof(int);
	myPrint(arr, len);
	mySort(arr, len);
	myPrint(arr, len);
}

// ��������Ժ���ģ�����ģ����ж��α���
template<class T1, class T2>
int func(T1 a, T2 b)
{
	return a + b;
}

void test04()
{
	//func(20, "aaa");
	/*
	int func(int a, const char* b)
	{
		return a + b;
	}
	*/
}

int main()
{
	test04();

	system("pause");
	return 0;
}
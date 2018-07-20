#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
������
cin.get() //һ��ֻ�ܶ�ȡһ���ַ�
cin.get(һ������) //��һ���ַ�
cin.get(��������) //���Զ��ַ���
cin.getline()
cin.ignore()
cin.peek()
cin.putback()

*/

// cin.get() //һ��ֻ�ܶ�ȡһ���ַ�
void test01()
{
	/*
	char a = cin.get(); // һ�ζ�ȡһ���ַ�
	cout << a << endl; // a

	a = cin.get();
	cout << a << endl; // s

	a = cin.get();
	cout << a << endl; // ��ȡ�س�

	a = cin.get();
	cout << a << endl;

	char ch = '0';
	cin.get(ch);
	cout << ch << endl;
	*/
	char a, b, c;
	cin.get(a).get(b).get(c);
	cout << a << b << c << endl;
}

// cin.get��2��������
void test02()
{
	char buf[1024] = { 0 };

	//cin.get(buf,1024);//��ȡ1024���ַ������ǻ��з����ڻ�����
	//char c = cin.get();
	//if (c =='\n')
	//{
	//	cout << "���з����ڻ�����" << endl;
	//}
	//cout << buf << endl;
	//cout << c << endl;

	//cin.getline()//���з�����
	cin.getline(buf, 1024);
	char c = cin.get(); // ���������
	if (c == '\n')
	{
		cout << "���з����ڻ�����" << endl;
	}
	cout << buf << endl;
	cout << c << endl;
}

// cin.ignore() ���� û�в����ͺ���һ���ַ���������N����ʾ����N���ַ�
void test03()
{
	cin.ignore(2);
	char c = cin.get();
	cout << c << endl;
}

// cin.peek() ͵����ֻ��������
void test04()
{
	char c = cin.peek();
	cout << c << endl;

	c = cin.get();
	cout << c << endl;
}

// cin.putback() �Żص�������
void test05()
{
	char c = cin.get();

	cin.putback(c); // �Ż�
	char buf[1024] = { 0 };
	cin.getline(buf, 1024);
	cout << buf << endl;
}

// �ж��û���������ַ�����������
void test06()
{
	cout << "�������ַ���������:" << endl;

	char c = cin.peek();
	if (c >= '0' && c <= '9')
	{
		int num;
		cin >> num;
		cout << "������������ǣ�" << num << endl;
	}
	else if (c >= 'A' && c <= 'Z')
	{
		char buf[1024] = { 0 };
		cin >> buf;

		cout << "�����������ĸ�Ǵ�д���ַ���:" << buf << endl;
	}
	else
	{
		char buf[1024] = { 0 };
		cin >> buf;

		cout << "��������ַ���:" << buf << endl;
	}
}

// ����һ��0��10֮�������ֱ��������ȷΪֹ
void test07()
{
	int num;
	while (1)
	{
		cin >> num; // ����������������ݣ����ﲻ������
		if (num >= 0 && num <= 10)
		{
			cout << "������ȷ" << endl;
			break;
		}

		cout << "����������:" << endl;

		cin.clear();//���ñ�־λ����־λ��Ϊ0
		cin.sync();//��ջ����� qt setbuf(stdin,NULL)

		////��ӡ��־λ
		//cout << cin.fail() << endl;
		//vs2015 ��2017
		/*char buf[1024] = { 0 };
		cin.getline(buf, 1024);*/
	}
}

int main()
{
	test07();

	system("pause");
	return 0;
}
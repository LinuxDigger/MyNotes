#include "MyString.h"



MyString::MyString()
{
	this->p = new char[1];
	this->p[0] = '\0';
	this->mSize = 0;
}


MyString::~MyString()
{
	if (NULL != this->p)
	{
		delete[] this->p;
		this->p = NULL;
	}
}

MyString::MyString(int n, char c) // ���û�����ʼ�����ݣ�n��c�ַ�����ַ���
{
	this->p = new char[n + 1];
	for (int i = 0; i < n; i++)
	{
		this->p[i] = c;
	}
	this->p[n] = '\0';
	this->mSize = n;
}

// ��������
MyString::MyString(const MyString& str)
{
	this->p = new char[strlen(str.p) + 1];
	strcpy(this->p, str.p);
	this->mSize = str.mSize;
}

// ��ֵ����
MyString& MyString::operator=(const MyString& str)
{
	if (NULL != this->p)
	{
		delete[] this->p;
		this->p = NULL;
	}
	this->p = new char[strlen(str.p) + 1];
	strcpy(this->p, str.p);
	this->mSize = str.mSize;
	return *this;
}

// MyString str3=str1+str2;
MyString MyString::operator+(const MyString& str)
{
	// 1.����һ����ʱ����
	MyString tmp; // �����޲ι��캯��
	// 2.�ͷ���������еĶ����ռ�
	if (NULL != tmp.p)
	{
		delete[] tmp.p;
		tmp.p = NULL;
	}

	// 3.����ռ䣬�ռ�Ĵ�С��str1+str2�Ķ����ռ��С
	int newstrlen = this->mSize + str.mSize;
	tmp.p = new char[newstrlen + 1];
	tmp.mSize = newstrlen;

	// �������ݵ��ռ���
	memset(tmp.p, 0, newstrlen + 1);
	strcat(tmp.p, this->p);
	strcat(tmp.p, str.p);

	return tmp;
}

MyString MyString::operator+(const char *s)
{
	/*
	//1.����һ����ʱ����
	MyString tmp;//�����޲ι��캯��
	//2.�ͷ���������еĶ����ռ�
	if (tmp.p != NULL)
	{
	delete[] tmp.p;
	tmp.p = NULL;
	}

	//3.����ռ䣬�ռ�Ĵ�С��str1+str2�Ķ����ռ��С
	int newstrlen = this->mSize + strlen(s) + 1;
	tmp.p = new char[newstrlen];
	memset(tmp.p, 0, newstrlen);

	tmp.mSize = this->mSize + strlen(s);

	//�������ݵ��ռ���
	strcat(tmp.p, this->p);
	strcat(tmp.p, s);

	return tmp;
	*/

	/*MyString str4=str1+"hello";
	MyString str4 = str3 + "hello";
	cout << str4 << endl;*/

	int newstrlen = this->mSize + strlen(s);
	char *tmp = new char[newstrlen + 1];
	memset(tmp, 0, newstrlen + 1);
	strcat(tmp, this->p);
	strcat(tmp, s);

	// �ͷ�ԭ���Ŀռ�
	if (NULL != this->p)
	{
		delete[] this->p;
		this->p = NULL;
	}
	this->p = tmp; // ���µ�ַ��this;
	this->mSize = newstrlen;
	return *this;
}

// str4 += str3;
MyString& MyString::operator+=(const MyString& str)
{
	// 1.��ȡ�����ַ����ĳ���
	int newstrlen = this->mSize + str.mSize;
	// 2.����ռ�
	char *newp = new char[newstrlen + 1];
	// 3.������׷�ӵ��ռ�
	memset(newp, 0, newstrlen + 1);
	strcat(newp, this->p);
	strcat(newp, str.p);
	// 4.�ͷ�str4�Ķ����ռ�
	if (NULL != this->p)
	{
		delete[] this->p;
		this->p = NULL;
	}
	// 5.��������Ķ����ռ��ַ�������е�ָ��
	this->p = newp;
	this->mSize = newstrlen;
	return *this;
}

MyString& MyString::operator+=(const char *s)
{
	// 1.��ȡ�����ַ����ĳ���
	int newstrlen = this->mSize + strlen(s);
	// 2.����ռ�
	char *newp = new char[newstrlen + 1];
	// 3.������׷�ӵ��ռ�
	memset(newp, 0, newstrlen + 1);
	strcat(newp, this->p);
	strcat(newp, s);
	// 4.�ͷ�str4�Ķ����ռ�
	if (NULL != this->p)
	{
		delete[] this->p;
		this->p = NULL;
	}
	// 5.��������Ķ����ռ��ַ�������е�ָ��
	this->p = newp;
	this->mSize = newstrlen;
	return *this;
}

int MyString::Size()
{
	return this->mSize;
}

char& MyString::operator[](int index)
{
	return this->p[index];
}

// cout<<str;
ostream& operator<<(ostream& out, MyString& str)
{
	out << str.p;
	return out;
}

// cin >> str4;
istream& operator >> (istream& in, MyString& str)
{
	// 1.����ռ�
	char tmp[1024] = { 0 };
	// 2.��ȡ�û��������Ϣ
	in >> tmp;
	// 3.�ͷ�ԭ���Ŀռ�  
	if (NULL != str.p)
	{
		delete[] str.p;
		str.p = NULL;
	}
	// 4.�����µĶ����ռ�
	str.p = new char[strlen(tmp) + 1];
	memset(str.p, 0, strlen(tmp) + 1);
	// 5.�����û��������Ϣ�������ռ�
	strcpy(str.p, tmp);
	str.mSize = strlen(tmp);
	return in;
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>//�ļ���д��ͷ�ļ�
using namespace std;

//�������������д�ļ���
void test01()
{
	ofstream ofs;//�ļ�������
	ofs.open("test.txt", ios::out | ios::trunc);
	//�ж��Ƿ�򿪳ɹ�
	if (!ofs.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
	}

	//д�ļ�
	ofs << "����:���" << endl;
	ofs << "���:180cm" << endl;
	ofs << "����:18" << endl;

	//�ر��ļ�
	ofs.close();
}

//���뵽�����������ļ�)
void test02()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
	}

	//���ļ�
	char buf[1024] = { 0 };
	//ÿ�ζ�ȡһ������
	/*while (ifs>>buf)
	{
		cout << buf << endl;
	}*/

	/*while (!ifs.eof())
	{
		ifs.getline(buf, sizeof(buf));
		cout << buf << endl;

	}*/

	char c;
	while ((c=ifs.get())!=EOF)
	{
		cout << c;
	}


	ifs.close();
}

int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}


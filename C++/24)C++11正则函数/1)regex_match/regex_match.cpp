#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <regex>
using namespace std;

// 1) �ַ�������ƥ��
void test01()
{
	if (regex_match("subject", regex("(sub)(.*)")))
	{
		cout << "ƥ�䵽�ַ���!\n";
	}
}

// 2) �ַ�������ƥ��
void test02()
{
	string s("subject");
	regex e("(sub)(.*)");
	if (regex_match(s, e))
	{
		cout << "ƥ�䵽�ַ���!\n";
	}
}

// 3) ��Χƥ��
void test03()
{
	string s("subject");
	regex e("(sub)(.*)");
	if (regex_match(s.begin(), s.end(), e))
	{
		cout << "ƥ�䵽�ַ���!\n";
	}
}

// 4) char*���Ͳ���ƥ��
void test04()
{
	//const char cstr[] = "subject"; ��ͬ��
	const char *cstr = "subject";
	cmatch cm;   // same as std::match_results<const char*> cm;
	regex e("(sub)(.*)");
	regex_match(cstr, cm, e);
	cout << "ƥ�䵽����� " << cm.size() << " ��\n";
}

// 5) string���Ͳ���ƥ��
void test05()
{
	string s("subject");
	smatch sm; // same as std::match_results<string::const_iterator> sm;
	regex e("(sub)(.*)");
	regex_match(s, sm, e);
	cout << "ƥ�䵽����� " << sm.size() << " ��\n";

	regex_match(s.cbegin(), s.cend(), sm, e);
	cout << "ƥ�䵽����� " << sm.size() << " ��\n";
}

// 6) ��� & ��ӡƥ����
void test06()
{
	const char *cstr = "subject";
	cmatch cm;   // same as std::match_results<const char*> cm;
	regex e("(sub)(.*)");

	// ʹ�� ��־ regex_constants::match_default
	regex_match(cstr, cm, e, regex_constants::match_default);

	cout << "ƥ�䵽�Ľ��: ";
	for (unsigned i = 0; i < cm.size(); ++i)
	{
		cout << "[" << cm[i] << "]";
	}
	cout << endl;
}

int main()
{
	test04();
	test06();

	system("pause");
	return 0;
}
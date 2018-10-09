#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <regex>
#include <string>
#include <iterator>
using namespace std;

// 1) ʹ���ַ��������滻�ַ�
void test01()
{
	string s("there is a subsequence in the string\n");
	regex e("\\b(sub)([^ ]*)");  // matches words beginning by "sub" -- ƥ�����ִ�"sub"��ʼ

	// using string/c-string (3) version:
	cout << regex_replace(s, e, "sub-$2");
}

// 2) ʹ�÷�Χ�滻�ַ�
void test02()
{
	string s("there is a subsequence in the string\n");
	regex e("\\b(sub)([^ ]*)");  // matches words beginning by "sub" -- ƥ�����ִ�"sub"��ʼ

	// using range/c-string (6) version:
	string result;
	regex_replace(back_inserter(result), s.begin(), s.end(), e, "$2");
	cout << result << endl;

	// ʹ�� ��־ flags
	// regex_constants::format_no_copy ������滻���,�����п���ԭ�ĸ���
	cout << regex_replace(s, e, "$1 and $2", regex_constants::format_no_copy) << endl;
	cout << regex_replace(s, e, "$1 and $2") << endl;
}

int main()
{
	test02();

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <regex>
using namespace std;

void test01()
{
	string s("this subject has a submarine as a subsequence");
	smatch sm;
	regex e("\\b(sub)([^ ]*)");   // matches words beginning by "sub" -- ƥ�����ִ�"sub"��ʼ

	cout << "ƥ��Ŀ��: " << s << endl;
	cout << "ƥ�����: /\\b(sub)([^ ]*)/" << endl;
	cout << "�ҵ�����ƥ�����ƥ��:" << endl;

	while (regex_search(s, sm, e))
	{
		//for (auto x : sm) cout << x << " "; // ��ͬ�ڡ�
		for(smatch::iterator it = sm.begin(); it != sm.end(); ++it) cout << *it << " ";

		cout << endl;
		s = sm.suffix().str();
	}
}

int main()
{
	test01();

	system("pause");
	return 0;
}
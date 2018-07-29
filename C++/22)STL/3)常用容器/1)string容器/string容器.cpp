#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

void test()
{
	// ���ݽṹ�������ģ�����16���ֽھʹӶ�������ռ�
	// ������
	string::iterator it;
	it++;
	it--;
	it + 2;
	// ˫�����
}

/*
string();//����һ���յ��ַ��� ����: string str;
string(conststring& str);//ʹ��һ��string�����ʼ����һ��string����
string(constchar* s);//ʹ���ַ���s��ʼ��
string(int n, char c);//ʹ��n���ַ�c��ʼ��

*/

void test01()
{
	// ����ģ�棬���ǲ�Ҫ<>������Ϊȡ�˱���
	string s1;
	string s2(10, 'a');

	string s3(s2);
	string s4("hello");
}

/*
string&operator=(const char* s);//char*�����ַ��� ��ֵ����ǰ���ַ���
string&operator=(const string&s);//���ַ���s������ǰ���ַ���
string&operator=(char c);//�ַ���ֵ����ǰ���ַ���
string& assign(constchar *s);//���ַ���s������ǰ���ַ���
string& assign(constchar *s, int n);//���ַ���s��ǰn���ַ�������ǰ���ַ���
string& assign(conststring&s);//���ַ���s������ǰ�ַ���
string& assign(int n, char c);//��n���ַ�c������ǰ�ַ���
string& assign(conststring&s, int start, int n);//��s��start��ʼn���ַ���ֵ���ַ���,��s=hello,��ôn=3,start=1����ô��hel�д�e��ʼ��ֵ3-1���ַ�

*/

void test02()
{
	string s1;
	s1 = "hello";
	cout << s1 << endl;

	string s2;
	s2.assign("world");
	cout << s2 << endl;
}

/*
char&operator[](int n);//ͨ��[]��ʽȡ�ַ�
char& at(int n);//ͨ��at������ȡ�ַ�

*/

void test03()
{
	string s = "hello world";

	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < s.size(); i++)
	{
		cout << s[100] << endl;
		//cout<<s.at()<<" ";
	}
	cout << endl;

	//[]��at������
	//[]����Խ�粻���쳣��ֱ�ӹ�
	//atԽ�����쳣

	try
	{
		cout << s.at(100) << endl;
	}
	catch (out_of_range &ex)
	{
		cout << ex.what() << endl;
		cout << "�����쳣" << endl;
	}
}

/*
string&operator+=(conststring& str);//����+=������
string&operator+=(constchar* str);//����+=������
string&operator+=(constchar c);//����+=������
string& append(constchar *s);//���ַ���s���ӵ���ǰ�ַ�����β
string& append(constchar *s, int n);//���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
string& append(conststring&s);//ͬoperator+=()
string& append(conststring&s, int pos, int n);//���ַ���s�д�pos��ʼ��n���ַ����ӵ���ǰ�ַ�����β
string& append(int n, char c);//�ڵ�ǰ�ַ�����β���n���ַ�c

*/

void test04()
{
	string s1 = "aaa";
	s1 += "bbb";
	s1 += 'c';
	cout << s1 << endl;

	s1.append("dddddd", 3);
	cout << s1 << endl; // aaabbbcddd
}

/*
int find(conststring& str, int pos = 0) const; //����str��һ�γ���λ��,��pos��ʼ����
int find(constchar* s, int pos = 0) const;  //����s��һ�γ���λ��,��pos��ʼ����
int find(constchar* s, int pos, int n) const;  //��posλ�ò���s��ǰn���ַ���һ��λ��
int find(constchar c, int pos = 0) const;  //�����ַ�c��һ�γ���λ��
int rfind(conststring& str, int pos = npos) const;//����str���һ��λ��,��pos��ʼ����
int rfind(constchar* s, int pos = npos) const;//����s���һ�γ���λ��,��pos��ʼ����
int rfind(constchar* s, int pos, int n) const;//��pos����s��ǰn���ַ����һ��λ��
int rfind(constchar c, int pos = 0) const; //�����ַ�c���һ�γ���λ��
string& replace(int pos, int n, conststring& str); //�滻��pos��ʼn���ַ�Ϊ�ַ���str
string& replace(int pos, int n, constchar* s); //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s

*/

void test05()
{
	string s = "abcdefgaafsd";

	cout << s.find('d') << endl; // 3
	cout << s.rfind('d') << endl; // 11,�����Ǵ��ҵ��󣬵��������Ǵ�����

	cout << s.find("kkk") << endl; // ���Ƿ���-1

	s.replace(2, 4, "AAAAB"); // ��2��λ�ã��±��0��ʼ�����滻4���ַ���
	// ���û��4���ַ����滻����ôʣ����ַ��ᱻ����,�������4���ַ���Ҳ����뵽�ַ�����
	cout << s << endl;
}

/*

compare������>ʱ���� 1��<ʱ���� -1��==ʱ���� 0��
�Ƚ����ִ�Сд���Ƚ�ʱ�ο��ֵ�˳����Խǰ���ԽС��
��д��A��Сд��aС��

int compare(conststring&s) const;//���ַ���s�Ƚ�
int compare(constchar *s) const;//���ַ���s�Ƚ�

*/

void test06()
{
	string s1 = "hello";
	string s2 = "hello";

	const char* s = "world";

	if (s1.compare(s2) == 0)
	{
		cout << "s1==s2" << endl;
	}

	if (s1.compare(s) == 0)
	{
		cout << "s1==s" << endl;
	}
}

/*
string substr(int pos = 0, int n = npos) const;//������pos��ʼ��n���ַ���ɵ��ַ���
*/

void test07()
{
	string email = "hello world@itcast.cn";
	int pos = email.find('@');

	string username = email.substr(0, pos);
	cout << username << endl;

	string prex = email.substr(pos + 1);
	cout << prex << endl;
}

/*
string& insert(int pos, constchar* s); //�����ַ���
string& insert(int pos, conststring& str); //�����ַ���
string& insert(int pos, int n, char c);//��ָ��λ�ò���n���ַ�c
string& erase(int pos, int n = npos);//ɾ����Pos��ʼ��n���ַ�

*/
void test08()
{
	string s = "aaaaa";
	s.insert(3, "AAAA"); // ��3��λ�ò����ַ���"AAAA"
	cout << s << endl;

	s.insert(3, 5, 'M'); // ��3��λ�ò���5��M�ַ�
	cout << s << endl;

	s.erase(2, 3);
	cout << s << endl;
}

/*
//string ת char*
string str = "itcast";
constchar* cstr = str.c_str();
//char* ת string
char* s = "itcast";
string sstr(s);

*/
void test09()
{
	const char *str = "hello";

	string s(str);
	cout << s << endl;

	const char *s2 = s.c_str();
	cout << s2 << endl;
}

// []��at���ص������ã����·���ռ䣬���ܻ����
void test10()
{
	string s = "abcde";
	char &a = s[2];
	char &b = s[3];

	a = '1';
	b = '2';

	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << s << endl;
	cout << "�ַ���ԭ���ĵ�ַ:" << (int*)s.c_str() << endl;

	s = "dfasflsafadsfafdafdasfadsfsafsadfsdafasfdsfdaf";

	cout << "�ַ����ĵ�ַ��" << (int*)s.c_str() << endl;

	//�ַ����Ŀռ�ᱻ���·��䣬ԭ�������þͲ�������
	//a = '3';//�ᵵ error
}

void test11()
{
	string s = "hello world";
	for (string::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	// �������
	for (string::reverse_iterator it = s.rbegin(); it != s.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}


int main()
{
	test11();

	system("pause");
	return 0;
}
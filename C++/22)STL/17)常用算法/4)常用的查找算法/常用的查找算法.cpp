#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace std;

bool Myprint(int val)
{
	return val > 30;
}
void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	vector<int>::iterator it = find(v.begin(), v.end(), 20);
	if (it == v.end())
	{
		cout << "����ʧ��" << endl;
	}
	else
	{
		cout << "���ҳɹ�" << *it << endl;
	}

	it = find_if(v.begin(), v.end(), Myprint);
	if (it == v.end())
	{
		cout << "����ʧ��" << endl;
	}
	else
	{
		cout << "���ҳɹ�:" << *it << endl;
	}
}

class Dejan
{
public:
	Dejan(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	bool operator==(const Dejan &dejan)
	{
		return this->name == dejan.name && this->age == dejan.age;
	}
public:
	string name;
	int age;
};
/*
template<class _InIt,class _Ty>
inline _InIt _Find(_InIt _First, _InIt _Last, const _Ty& _Val, false_type)
{
for (; _First != _Last; ++_First)
if (*_First == _Val)//Maker("aaa2",20)==Maker("aaa2",20)
break;
return (_First);
}
*/

//struct MyComapare
//{
//	bool operator()(Maker maker)
//	{
//		return maker.name == "aaa3" && maker.age == 30;
//	}
//};
//Ϊ�˲�������д������ô���ǽ������䣬�����صĺ�����������Ϊ2��

struct MyCompare
	:public binary_function<Dejan, Dejan, bool>
{
	bool operator()(Dejan d1, Dejan d2) const
	{
		return d1.name == d2.name && d1.age == d2.age;
	}
};
void test02()
{
	vector<Dejan> v;
	v.push_back(Dejan("aaa1", 10));
	v.push_back(Dejan("aaa2", 20));
	v.push_back(Dejan("aaa3", 30));
	v.push_back(Dejan("aaa4", 40));
	v.push_back(Dejan("aaa5", 50));

	vector<Dejan>::iterator it = find(v.begin(), v.end(), Dejan("aaa2", 20));
	if (it == v.end())
	{
		cout << "����ʧ��" << endl;
	}
	else
	{
		cout << "���ҳɹ�:" << it->name << " " << it->age << endl;
	}
	cout << "---------------------------" << endl;
	//��д���غ���������ʹ��find_if
	/*
	template<class _InIt,class _Pr>
	inline _InIt _Find_if(_InIt _First, _InIt _Last, _Pr _Pred)
	{
	for (; _First != _Last; ++_First)
	if (_Pred(*_First))
	break;
	return (_First);
	}
	*/
	it = find_if(v.begin(), v.end(), bind2nd(MyCompare(), Dejan("aaa4", 40)));
	if (it == v.end())
	{
		cout << "����ʧ��" << endl;
	}
	else
	{
		cout << "���ҳɹ�:" << it->name << " " << it->age << endl;
	}
}

/*
adjacent_find�㷨 ���������ظ�Ԫ��
@param beg ������ʼ������
@param end ��������������
@param  _callback �ص���������ν��(����bool���͵ĺ�������)
@return ��������Ԫ�صĵ�һ��λ�õĵ�����

adjacent_find(iterator beg, iterator end, _callback);
*/
void test03()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	/*
	template<class _FwdIt>
	inline _FwdIt adjacent_find(_FwdIt _First, _FwdIt _Last)
	{
		return (_STD adjacent_find(_First, _Last, equal_to<>()));
	}
	*/
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
	{
		cout << "����ʧ��" << endl;
	}
	else
	{
		cout << "���ҳɹ�:" << *it << endl;
	}
}

class Student
{
public:
	Student(int age, int score)
	{
		this->age = age;
		this->score = score;
	}
public:
	int age;
	int score;
};
bool Studentfunc(Student &s1, Student &s2)
{
	return s1.age == s2.age && s1.score == s2.score;
}

struct _Studentfunc
{
	bool operator()(Student s1, Student s2) const
	{
		return s1.age == s2.age && s1.score == s2.score;
	}
};
void test04()
{
	vector<Student> vs;
	vs.push_back(Student(10, 1));
	vs.push_back(Student(20, 2));
	vs.push_back(Student(30, 3));
	//vs.push_back(Student(30, 3));
	vs.push_back(Student(40, 4));
	vs.push_back(Student(50, 5));

	//vector<Student>::iterator it = adjacent_find(vs.begin(),vs.end(), _Studentfunc()); // �� ν��ʵ��
	vector<Student>::iterator it = adjacent_find(vs.begin(), vs.end(), _Studentfunc()); // ��ͨ����
	if (it == vs.end())
	{
		cout << "����ʧ��" << endl;
	}
	else
	{
		cout << "���ҳɹ�:" << it->age << endl;
	}
}

/*
binary_search�㷨 ���ֲ��ҷ�
ע��: �����������в�����
@param beg ������ʼ������
@param end ��������������
@param value ���ҵ�Ԫ��
@return bool ���ҷ���true ����false

bool binary_search(iterator beg, iterator end, value);

*/

/*
template<class _FwdIt,
class _Ty> inline
bool binary_search(_FwdIt _First, _FwdIt _Last, const _Ty& _Val)
{	// test if _Val equivalent to some element, using operator<
return (_STD binary_search(_First, _Last, _Val, less<>()));
}

template<class _Ty = void>
struct less
: public binary_function<_Ty, _Ty, bool>
{	// functor for operator<
bool operator()(const _Ty& _Left, const _Ty& _Right) const
{	// apply operator< to operands
return (_Left < _Right);
}
};

template<class _Ty1,
class _Ty2>           10           50
auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
-> decltype(static_cast<_Ty1&&>(_Left)
< static_cast<_Ty2&&>(_Right))
{	// transparently apply operator< to operands
return (static_cast<_Ty1&&>(_Left)
< static_cast<_Ty2&&>(_Right));
}
*/
void test05()
{
	vector<int> v;
	//10 20 80 40 50 60
	v.push_back(10);
	v.push_back(20);
	v.push_back(80);
	v.push_back(100);
	v.push_back(2000);
	v.push_back(60);

	bool ret = binary_search(v.begin(), v.end(), 80);
	if (ret)
	{
		cout << "�ҵ�" << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}
}

/*
count�㷨 ͳ��Ԫ�س��ִ���
@param beg ������ʼ������
@param end ��������������
@param  value�ص���������ν��(����bool���͵ĺ�������)
@return int����Ԫ�ظ���

count(iterator beg, iterator end, value);
*/
void test06()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(80);
	v.push_back(10);
	v.push_back(30);
	v.push_back(60);
	int ret = count(v.begin(), v.end(), 20);
	cout << ret << endl;

	ret = count_if(v.begin(), v.end(), [](int val)->bool {return val > 20; });
	cout << "ret=" << ret << endl;
}

int main()
{
	test06();

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

void test()
{
	vector<int>::iterator it;
	it--;
	it++;
	it + 2;
	//�����Ĵ洢�ռ䣬
	//˫�����
}

/*
vector<T> v; //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
vector(v.begin(), v.end());//��v[begin(), end())�����е�Ԫ�ؿ���������
vector(n, elem);//���캯����n��elem����������
vector(const vector &vec);//�������캯����

//���� ʹ�õڶ������캯�� ���ǿ���...
int arr[] = {2,3,4,1,9};
vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

*/

void printVector(const vector<int> &vec)
{
	for (vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	int arr[] = { 2, 4, 1, 3, 9 };
	vector<int> v(arr, arr + sizeof(arr) / sizeof(int));

	printVector(v);

	vector<int> v2(10, 6);
	printVector(v2);
}

/*
assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem);//��n��elem������ֵ������
vector&operator=(const vector  &vec);//���صȺŲ�����
swap(vec);// ��vec�뱾���Ԫ�ػ�����

*/
void test02()
{
	vector<int> v;
	v.assign(10, 6);

	vector<int> v2;
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(30);

	printVector(v);
	printVector(v2);

	cout << "----------------" << endl;

	v.swap(v2); // ����ָ��

	printVector(v);
	printVector(v2);
}

/*
size();//����������Ԫ�صĸ���
empty();//�ж������Ƿ�Ϊ��
resize(int num);//����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(int num, elem);//����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á����������̣���ĩβ����������>�ȵ�Ԫ�ر�ɾ����
capacity();//����������
reserve(int len);//����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�

*/
void test03()
{
	vector<int> v2;
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(30);

	cout << "v2.size:" << v2.size() << endl;

	v2.resize(5); // ���ٿռ䣬��Ĭ��ֵ��Ĭ��ֵ��0
	cout << "v2.size:" << v2.size() << endl;
	printVector(v2);

	v2.reserve(20);
	v2.push_back(100);

	printVector(v2);
	cout << "v2.size:" << v2.size() << endl;
	cout << v2.capacity() << endl;

	//cout << v2[10] << endl;  error
}

// Ԥ���ռ�
void test04()
{
	vector<int> v;

	v.resize(5); // 5��int�Ŀռ䣬Ĭ�ϸ�ֵ0��

	v.push_back(10);
	cout << "v.capacity() =" << v.capacity() << endl;
	cout << "v.size()=" << v.size() << endl;

	cout << "-----------------" << endl;

	vector<int> v2;

	v2.reserve(5); // ����ʼ��
	v2.push_back(10);
	cout << "v2.capacity() =" << v2.capacity() << endl;
	cout << "v2.size()=" << v2.size() << endl;
}

void test05()
{
	vector<int> v;

	v.reserve(1000000);

	int *p = NULL;
	int num = 0;
	for (int i = 0; i < 1000000; i++)
	{
		v.push_back(i);
		// �ж�����ռ�Ĵ���
		if (p != &v[0]) // ���p�������׵�ַ����ô֤���������¿ռ�
		{
			p = &v[0];
			num++;
		}
	}

	cout << "num=" << num << endl;
}

/*
at(int idx); //��������idx��ָ�����ݣ����idxԽ�磬�׳�out_of_range�쳣��
operator[];//��������idx��ָ�����ݣ�Խ��ʱ������ֱ�ӱ���
front();//���������е�һ������Ԫ��
back();//�������������һ������Ԫ��

*/
void test06()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	cout << v.front() << endl;
	cout << v.back() << endl;

	v.front() = 100;
	v.back() = 200;

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

/*
insert(const_iterator pos, int count,ele);//������ָ��λ��pos����count��Ԫ��ele.
push_back(ele); //β������Ԫ��ele
pop_back();//ɾ�����һ��Ԫ��
erase(const_iterator start, const_iterator end);//ɾ����������start��end֮���Ԫ��
erase(const_iterator pos);//ɾ��������ָ���Ԫ��
clear();//ɾ������������Ԫ��

*/
void test07()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	v.insert(v.begin() + 2, 100);
	printVector(v);

	v.pop_back();
	printVector(v);

	v.erase(v.begin());
	printVector(v);

	v.erase(v.begin(), v.end());
	printVector(v);
}

int main()
{
	test07();

	system("pause");
	return 0;
}
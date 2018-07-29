#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<ctime>
#include<algorithm> // �㷨ͷ�ļ�
using namespace std;

// 5��ѧ����10����ί��ȥ����߷֣���ͷ֣�ȡƽ����

// ����ѧ��
class Student
{
public:
	string name;
	int mscore;
};

// ����ѧ������ѧ���ŵ�vector
void createStudent(vector<Student> &vec)
{
	string Setname = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		// ����ѧ��
		Student s;
		s.name = "ѧ��";
		s.name += Setname[i];
		s.mscore = 0;
		vec.push_back(s); // ��ѧ����������
	}
}

// ��ÿ��ѧ�����д�֣���������deque������
void SetScore(vector<Student> &vec)
{
	// �������
	srand((unsigned int)time(NULL));
	// ����ѧ��
	for (vector<Student>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		// ��������deque
		deque<int> dScore;
		for (int i = 0; i < 10; i++)
		{
			// 10����ί��ѧ�����
			int score = rand() % 70 + 30; // �������
			dScore.push_back(score); // �ѷ�����������
		}
		// ����
		sort(dScore.begin(), dScore.end());

		// ȥ����ߺ���ͷ�
		dScore.pop_back();
		dScore.pop_front();

		// ���ܷ�
		int num = 0;
		for (deque<int>::iterator dit = dScore.begin(); dit != dScore.end(); ++dit)
		{
			num += (*dit);
		}

		// ��ƽ����
		int ageSore = num / dScore.size();

		// ����ƽ����
		it->mscore = ageSore;
	}
}

bool mycompare(Student &s1, Student &s2)
{
	return s1.mscore > s2.mscore;
}

void ShowStudentScore(vector<Student> &vec)
{
	// ����
	sort(vec.begin(), vec.end(), mycompare);
	for (vector<Student>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << "Name:" << it->name << " Score:" << it->mscore << endl;
	}
}

void test()
{
	vector<Student> vstu;
	// 1.����ѧ��
	createStudent(vstu);
	// 2.��ί��ѧ�����
	SetScore(vstu);
	// 3.����ѧ���ɼ�����
	ShowStudentScore(vstu);
}

int main()
{
	test();

	system("pause");
	return 0;
}
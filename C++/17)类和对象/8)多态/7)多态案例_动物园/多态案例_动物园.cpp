#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

// ������
class Animal
{
public:
	virtual void speak() = 0;

	string name;
};

// ����԰
class Zoo
{
public:
	Zoo()
	{
		mCapacity = 1024;
		mSize = 0;
		// �Ӷ��������˺���ָ������
		p = new Animal*[mCapacity];
	}
	// ��Ӷ��ﵽ����԰
	int AddAnimal(Animal *animal) // Animal* animal = new Dog
	{
		if (mSize == mCapacity)
		{
			return -1;
		}
		// ��ֵ���ǵ�ַ
		this->p[mSize] = animal;

		mSize++;
		return 0;
	}
	// �����еĶ��ﶼ��
	void StrstaSpeak()
	{
		for (int i = 0; i < mSize; i++)
		{
			this->p[i]->speak();
		}
	}
	~Zoo()
	{
		for (int i = 0; i < mSize; i++)
		{
			if (NULL != this->p[i])
			{
				delete this->p[i];
				this->p[i] = NULL;
			}
		}

		if (NULL != p)
		{
			delete[] p;
			p = NULL;
		}
	}
private:
	Animal **p;
	int mCapacity; // ����
	int mSize; // ��ǰ�������
};

// ��
class Dog :public Animal
{
public:
	Dog(string name)
	{
		this->name = name;
	}
	virtual void speak()
	{
		cout << "С��" << this->name << "������..." << endl;
	}
private:
	string name;
};

// �ϻ�
class Tiger :public Animal
{
public:
	Tiger(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	virtual void speak()
	{
		cout << this->age << "��" << "�ϻ�" << this->name << "���" << endl;
	}
private:
	//string name;
	int age;
};

void test()
{
	// ��������԰
	Zoo *zoo = new Zoo;
	zoo->AddAnimal(new Dog("С��"));
	zoo->AddAnimal(new Tiger("������", 5));

	zoo->StrstaSpeak();
	delete zoo;
}

int main()
{
	test();

	system("pause");
	return 0;
}
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �Զ�����������
struct Human
{
	char name[64];
	int age;
};

void HumanEatFood(struct Human *h)
{
	printf("%s�ڳ��˷�\n", h->name);
}

struct Animal
{
	char name[64];
	int age;
};

void AnimalEatFood(struct Animal *a)
{
	printf("%s�ڳԶ��ﷹ\n", a->name);
}

int main()
{
	struct Human human = { "����",1000 };
	struct Animal animal = { "����", 5 };

	AnimalEatFood(&human);
	AnimalEatFood(&animal);

	system("pause");
	return 0;
}
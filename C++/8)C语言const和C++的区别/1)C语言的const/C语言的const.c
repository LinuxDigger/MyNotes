#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// 1.C���Ե�const���εı������пռ�
// 2.C���Ե�ȫ��const���εı��������ⲿ��������

const int a = 10; // ��������һ����ʼ���Ͳ��ܸı�

void test()
{
	const int b = 20; // ջ��
	// һ����ʼ������ֱ���޸ģ����ǿ��Լ���޸�

	extern const int c;  // extern ��������˵������/�����ڱ𴦶����,Ҫ�ڴ˴�����
	printf("%d\n", c);
}

int main()
{
	test();

	system("pause");
	return 0;
}
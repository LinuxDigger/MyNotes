#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 10;
	int b = 20;
	printf("%d\n", a > b ? a : b);

	//(a > b ? a : b) = 100; error

	//(a > b ? a : b) = 100;C���Ե���Ŀ��������صĲ�����ֵ�����صĲ��ǿռ䣬���ص���ֵ
	//�Ⱥŵ���߾ͽ���ֵ���Ⱥŵ��ұ߾ͽ���ֵ
	//��ֵ�ǿ����޸ĵģ��пռ��

	//(a > b ? a : b) ���ص�20
	//20 = 100;

	system("pause");
	return 0;
}
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ҹ�
typedef struct guagou {
	struct guagou *next;
}guagou;

// �·�
typedef struct yifu {
	guagou gg; // �·���ʼ��λ�ñ����ǹҹ�
	int size; // �·��Ĵ�С
}yifu;

int main()
{
	yifu y1 = { NULL,10 };
	yifu y2 = { NULL,20 };
	yifu y3 = { NULL,30 };
	yifu y4 = { NULL,40 };
	yifu y5 = { NULL,50 };

	guagou *g1 = (guagou*)&y1;
	guagou *g2 = (guagou*)&y2;
	guagou *g3 = (guagou*)&y3;
	guagou *g4 = (guagou*)&y4;
	guagou *g5 = (guagou*)&y5;


	//printf("g1��ֵ:%p, y1�ĵ�ַ:%p, y1.gg�ĵ�ַ:%p\n",g1,&y1,&y1.gg);
	// ��ӡ���: g1��ֵ:006FFBD8, y1�ĵ�ַ:006FFBD8, y1.gg�ĵ�ַ:006FFBD8

	// �ѹҹ�������(������ϵ)
	g1->next = g2;
	g2->next = g3;
	g3->next = g4;
	g4->next = g5;
	g5->next = NULL;

	guagou *pCur = g1;
	while (NULL != pCur)
	{
		yifu *yy = (yifu*)pCur;
		printf("size:%d\n", yy->size);
		
		pCur = pCur->next;
	}

	system("pause");
	return 0;
}
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "itcast_asn1_der.h"

typedef struct _dejan
{
	char name[32];
	int age;
	char *p;
	int p_len;
}dejan;

// �������ݵ��ļ�
int write_file(unsigned char*, int);
// ���л����� - asn1_serialize()
int asn1_serialize(dejan*, unsigned char**,int*);
// �����л����� - asn1_unserialize()
int asn1_unserialize(unsigned char*, int, dejan**);
// �Զ���ṹ���ڴ��ͷź���
int DejanStructFree(dejan**);

int main()
{
	/*---------------------Serialize Start------------------------*/
	unsigned char *dst_data = NULL;  // asn1���л������
	int dst_data_len = 0; // asn1���л������ĳ���

	// ����һ��dejan��Ľṹ�����
	dejan dj = {
		.name = "�ε½�",
		.age = 18,
		.p = "hello world!",
		.p_len = 12 
	};

	// �ṹ��dejan dj  =>   asn1���л�
	asn1_serialize(&dj, &dst_data, &dst_data_len);
	printf("ASN1����ɹ�!\n");
	printf("dst_data: %s\ndst_data_len: %d\n", dst_data, dst_data_len);
	// ������ļ��鿴
	write_file(dst_data, dst_data_len);
	/*---------------------Serialize End------------------------*/


	/*---------------------Unserialize Start------------------------*/
	dejan *buf = NULL;  //����֮�󴫳�����
	asn1_unserialize(dst_data, dst_data_len, &buf);
	printf("����ɹ�... \n");

	// �ȽϽ��(У������)
	if ((dj.age == buf->age) && strcmp(dj.name, buf->name) == 0)
	{
		printf("�������� OK!\n");
	}
	else 
	{
		printf("���ݲ�����! Failed!!\n");
	}

	printf("name:%s\nage:%d\np:%s\np_len:%d\n", buf->name, buf->age, buf->p, buf->p_len);
	// �ͷ��ڴ�
	DejanStructFree(&buf);

	/*---------------------Unserialize End------------------------*/


	system("pause");
	return 0;
}

/* asn1���л�����
int asn1_serialize([�Զ���ṹ�����ͱ���], [�������], [������ݳ���]);
*/
int asn1_serialize(dejan *dj, unsigned char **dst_data, int *dst_data_len)
{
	ITCAST_ANYBUF *tmp_anybuf = NULL;
	ITCAST_ANYBUF *headNode = NULL;
	ITCAST_ANYBUF *tmp_node = NULL;
	ITCAST_ANYBUF *out_data_node = NULL;


	if (NULL == dj || NULL == dst_data || NULL == dst_data_len)
	{
		printf("��������Ϊ��!");
	}

	// ��ʼ����

	// 1. char name[32] == char*  =>  ANYBUF����
	DER_ITCAST_String_To_AnyBuf(&tmp_anybuf, dj->name, strlen(dj->name)); 
	DER_ItAsn1_WritePrintableString(tmp_anybuf, &headNode); 

	// 2. int age  =>  ASN1����
	tmp_node = headNode;
	DER_ItAsn1_WriteInteger(dj->age, &(tmp_node->next));

	// 3. char *p  =>  ASN1����
	tmp_node = tmp_node->next;
	EncodeChar(dj->p, strlen(dj->p), &(tmp_node->next));

	// 4. int p_len   =>   ASN1����
	tmp_node = tmp_node->next;
	DER_ItAsn1_WriteInteger(dj->p_len, &(tmp_node->next));

	// 5. ����������ṹ��  =>  ASN1����
	DER_ItAsn1_WriteSequence(headNode, &out_data_node);

	// 6. ����
	unsigned char *out_data = NULL;
	int out_data_len = 0;
	out_data = malloc(out_data_node->dataLen);
	if (NULL == out_data)
	{
		perror("lin-97: error >> out_data = malloc(out_data_node->dataLen);");
	}
	memset(out_data, 0, out_data_node->dataLen + 1);
	memcpy(out_data, out_data_node->pData, out_data_node->dataLen);
	out_data_len = out_data_node->dataLen;

	*dst_data = out_data;
	*dst_data_len = out_data_len;

	// 7. �ͷ��ڴ�
	if (NULL != tmp_anybuf) 
	{
		DER_ITCAST_FreeQueue(tmp_anybuf);
	}
	if (NULL != headNode)
	{
		DER_ITCAST_FreeQueue(headNode);
	}
	if (NULL != out_data_node) 
	{
		DER_ITCAST_FreeQueue(out_data_node);
	}

	return 0;
}

/* ��asn1���л�����
int asn1_unserialize([Դ����], [Դ���ݳ���], [Ԥ������Ŀռ��ַ])
*/
int asn1_unserialize(unsigned char *src_data, int src_data_len, dejan **dst_data)
{
	ITCAST_ANYBUF *tmp_anybuf = NULL;
	ITCAST_ANYBUF *headNode = NULL;
	ITCAST_ANYBUF *tmp_node = NULL;
	ITCAST_ANYBUF *out_data_node = NULL;

	dejan *buf = NULL;

	if (NULL == src_data || NULL == src_data_len || NULL == dst_data)
	{
		perror("��������Ϊ��!");
	}

	// 1. �ѽṹ��ASN1����  =>  AnyBuf
	DER_ITCAST_String_To_AnyBuf(&tmp_anybuf, src_data, src_data_len);
	DER_ItAsn1_ReadSequence(tmp_anybuf, &headNode);

	// �� buf����ռ�
	buf = malloc(sizeof(dejan));
	if (NULL == buf)
	{
		perror("buf = malloc(sizeof(dejan));");
	}
	memset(buf, 0, sizeof(dejan));

	// 2. (ASN1)name   =>   (char*)name
	ITCAST_ANYBUF *tmp_name = NULL;
	DER_ItAsn1_ReadPrintableString(headNode, &tmp_name);

	// ��������
	memcpy(buf->name, tmp_name->pData, tmp_name->dataLen);

	// 3. (ASN1)age   =>    int age
	tmp_node = headNode->next;
	DER_ItAsn1_ReadInteger(tmp_node, &buf->age);

	// 4. (ASN1)p     =>     (char*)p
	ITCAST_ANYBUF *tmp_p;
	tmp_node = tmp_node->next;
	DER_ItAsn1_ReadPrintableString(tmp_node, &tmp_p);

	// ����ռ�
	buf->p = malloc(tmp_p->dataLen + 1);
	if (NULL == buf->p)
	{
		perror("buf->p = malloc(tmp_p->dataLen + 1)");
	}
	memset(buf->p, 0, tmp_p->dataLen + 1);

	// ��������
	memcpy(buf->p, tmp_p->pData, tmp_p->dataLen);

	// 5. (ASN1)p_len   =>  (char*)p_len
	tmp_node = tmp_node->next;
	DER_ItAsn1_ReadInteger(tmp_node, &buf->p_len);

	// 6. ����
	*dst_data = buf;

	// 7. �ͷ��ڴ�
	if (NULL != tmp_anybuf)
	{
		DER_ITCAST_FreeQueue(tmp_anybuf);
	}
	if (NULL != headNode)
	{
		DER_ITCAST_FreeQueue(headNode);
	}
	if (NULL != tmp_name)
	{
		DER_ITCAST_FreeQueue(tmp_name);
	}
	if (NULL != tmp_p)
	{
		DER_ITCAST_FreeQueue(tmp_p);
	}
	return 0;
}

/* �������ݵ��ļ�
write_file([����], [���ݳ���])
*/
int write_file(unsigned char *buf, int len)
{
	FILE *fp = NULL;
	fp = fopen("./teacher.ber", "wb");
	if (NULL == fp)
	{
		printf("fopen file error \n");
		return -1;
	}
	fwrite(buf, 1, len, fp);
	fclose(fp);
	return 0;
}

/*�Զ���ṹ���ڴ��ͷź���
int DejanStructFree([�Զ���ṹ��ָ��ĵ�ַ])
*/
int DejanStructFree(dejan **dj)
{
	dejan *buf = NULL;
	if (NULL == dj || NULL == *dj)
	{
		perror("error:int DejanStructFree(dejan **dj)");
	}
	buf = *dj;

	// �ͷ� (*dj)->p ָ��Ŀռ�
	if (NULL != buf->p)
	{
		free(buf->p);
	}
	// �ͷ����ṹ��
	free(buf);
	buf = NULL;
	*dj = NULL;

	return 0;
}
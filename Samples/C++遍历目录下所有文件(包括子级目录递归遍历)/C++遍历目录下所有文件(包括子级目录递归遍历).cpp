#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <io.h>
using namespace std;

int glob(const char* pattern = "./*");

int main()
{
	//glob("F:/VS_Projects/md5sum/md5sum/*");
	glob();
	
	system("pause");
	return 0;
}

int glob(const char* pattern)
{
	const char *ptrEnd = strrchr(pattern,'/');
	const char *suffix_rule = ptrEnd;              // β׺���� /* �� /*.*
	const int cur_path_len = ptrEnd + 1 - pattern; // ȡ���ַ������һ��'/'��λ��, ���� '/'
	char *cur_path = new char[cur_path_len + 1];   // �����ַ��洢�ռ�, ���� \0
	memset(cur_path, 0, cur_path_len + 1);         // ��ʼ���ռ�0, ���� \0
	strncpy(cur_path, pattern, cur_path_len);      // ��������
	//cout << cur_path <<endl;    // ��ǰ����Ŀ¼·��
	//cout << suffix_rule <<endl; // β׺����

	long fh = 0;
	_finddata_t fileInfo;
	string pathName;

	if ((fh = _findfirst(pattern, &fileInfo)) == -1L) return -1;

	do
	{
		if ( (strcmp(fileInfo.name,".")!=0) && (strcmp(fileInfo.name, "..") != 0) )
		{
			if (fileInfo.attrib == _A_SUBDIR)
			{
				//cout << "DIR:" << string(cur_path) + fileInfo.name + suffix_rule << endl;
				glob( (string(cur_path) + fileInfo.name + suffix_rule).c_str() ); // �ݹ�����Ӽ�Ŀ¼
			}
			else
			{
				cout << string(cur_path) + fileInfo.name << endl;
			}
		}
	} while (_findnext(fh, &fileInfo) == 0);

	// ��Դ�ͷ�
	_findclose(fh);
	delete[] cur_path;

	return 0;
}
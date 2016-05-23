// GetProfile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <afx.h>
#include <iostream>
using namespace std;
int Convert(const char* s)
{
	int nMin,nSec;
	CString str = s;
	int P = str.Find(':');
	nMin = atoi(str.Left(P+1));
	nSec = atoi(str.Right(str.GetLength()-P-1));
//	nSec = atoi(str.Mid(str.GetLength()-P));
	return nMin * 60 + nSec;
}
CString LoadProfile(FILE *fp)
{
	CString str;
	char s[20];
	int r;
	while( ( r = fread(s,1,sizeof(s)-1,fp) ) > 0)
	{
		s[r] = '\0';
		str += s;
	}
	fclose(fp);
	return str;
}
DWORD ReturnDefault(char* lpRet, const char* lpDefault)
{
	strcpy(lpRet,lpDefault);
	return strlen(lpRet);
}
DWORD GetMyProfileString(
	const char* lpAppName, //������
	const char* lpKeyName, //������
	const char* lpDefault, //ȱʡֵ
	char *lpReturned,	   //����Ͳ�������ȡ�ı�����ֵ
	unsigned long nSize,   //��������С
	const char* lpFileName //ini���ļ���
)
{
	FILE *fp = fopen(lpFileName,"r");
	if(!fp)
		ReturnDefault(lpReturned, lpDefault);
	CString STR = LoadProfile(fp);		//����.ini�ļ�
	CString str = lpAppName;			//�����������str
	str = "[" + str + "]";				//��str����[str]��ʶ
	int i = STR.Find(str);				//��ȫ������STR���ҵ�������str
	if(i < 0)
		ReturnDefault(lpReturned, lpDefault);

	int j = STR.Find("\n[",i+1);		//��ȫ������STR���ҵ���ǰ�����β��
	if(j < 0)
		str = STR.Mid(i);
	else
		str = STR.Mid(i,j-i+1);			//��ֳ���ǰ�����str
//	cout << (const char*)str << endl;

	CString keyName = lpKeyName;
	keyName += '=';
	i = str.Find(keyName);
	if(i < 0)
		ReturnDefault(lpReturned, lpDefault);
	j = str.Find("\n",i);
	str = str.Mid(i,j-i);
	str.Delete(0,strlen(lpKeyName)+1);
//	cout << endl << (const char*)str << endl;

	return ReturnDefault(lpReturned, str);
}


int main(int argc, char* argv[])
{
	char s[64];
	int i = 0;
	CString sApp;
	while(i < 3)
	{
		sApp.Format("Video%d",i+1);
		cout << (const char*)sApp << ":" << endl;
		::GetMyProfileString(sApp,"FILE","NULL",s,sizeof(s),"./test.ini");
		cout << "�ļ�����" << s << endl;
		::GetMyProfileString(sApp,"NAME","NULL",s,sizeof(s),"./test.ini");
		cout << "��Ƶ����" << s << endl;
		::GetMyProfileString(sApp,"TIME","NULL",s,sizeof(s),"./test.ini");
		cout << "��Ƶ���ȣ�" << Convert(s) << " ��" << endl << endl;
		++i;
	}
	return 0;
}

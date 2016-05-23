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
	const char* lpAppName, //分类名
	const char* lpKeyName, //变量名
	const char* lpDefault, //缺省值
	char *lpReturned,	   //输出型参数：读取的变量数值
	unsigned long nSize,   //缓冲区大小
	const char* lpFileName //ini的文件名
)
{
	FILE *fp = fopen(lpFileName,"r");
	if(!fp)
		ReturnDefault(lpReturned, lpDefault);
	CString STR = LoadProfile(fp);		//加载.ini文件
	CString str = lpAppName;			//传入分类名给str
	str = "[" + str + "]";				//给str加上[str]标识
	int i = STR.Find(str);				//在全部内容STR中找到分类名str
	if(i < 0)
		ReturnDefault(lpReturned, lpDefault);

	int j = STR.Find("\n[",i+1);		//在全部内容STR中找到当前分类结尾符
	if(j < 0)
		str = STR.Mid(i);
	else
		str = STR.Mid(i,j-i+1);			//拆分出当前分类给str
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
		cout << "文件名：" << s << endl;
		::GetMyProfileString(sApp,"NAME","NULL",s,sizeof(s),"./test.ini");
		cout << "视频名：" << s << endl;
		::GetMyProfileString(sApp,"TIME","NULL",s,sizeof(s),"./test.ini");
		cout << "视频长度：" << Convert(s) << " 秒" << endl << endl;
		++i;
	}
	return 0;
}

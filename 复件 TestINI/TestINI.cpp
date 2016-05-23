// TestINI.cpp : Defines the entry point for the console application.
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

void main()
{
	char s[64];
	int i = 0;
	CString sApp;
	while(i < 3)
	{
		sApp.Format("Video%d",i+1);
		cout << (const char*)sApp << ":" << endl;
		::GetPrivateProfileString(sApp,"FILE","NULL",s,sizeof(s),"./test.ini");
		cout << "文件名：" << s << endl;
		::GetPrivateProfileString(sApp,"NAME","NULL",s,sizeof(s),"./test.ini");
		cout << "视频名：" << s << endl;
		::GetPrivateProfileString(sApp,"TIME","NULL",s,sizeof(s),"./test.ini");
		cout << "视频长度：" << Convert(s) << " 秒" << endl << endl;
		++i;
	}
}

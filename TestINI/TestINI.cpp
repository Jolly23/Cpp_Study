// TestINI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <string.h>
#include <iostream>
using namespace std;
//sprintf:´òÓ¡µ½×Ö·û´®ÖÐ(s-printf)
void main()
{
	char s[64];
	int i = 0;
	char sApp[20];
	while(i < 3)
	{
		sprintf(sApp,"Video%d",i+1);
		::GetPrivateProfileString(sApp,"FILE","NULL",s,sizeof(s),"./test.ini");
		cout << sApp << ": " << s << endl;
		::GetPrivateProfileString(sApp,"NAME","NULL",s,sizeof(s),"./test.ini");
		cout << sApp << ": " << s << endl;
		::GetPrivateProfileString(sApp,"TIME","NULL",s,sizeof(s),"./test.ini");
		cout << sApp << ": " << s << endl << endl;
		++i;
	}
}

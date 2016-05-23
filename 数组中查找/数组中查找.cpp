// 数组中查找.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <process.h>

int StringFind(char str[],char c);

void main()
{
	char s[128];
	printf("输入字符串：");
	scanf("%s",s);

	printf("输入要查找的字符：");	
	fflush(stdin);
	char c=getchar();

	int Res=StringFind(s,c);

	if(Res>=0)
		printf("找到了，是第%d个字符\n",Res+1);
	else
		puts("没找到！");

	system("pause");
}


int StringFind(char str[],char c)
{
	char *p = str;
	while(*p != '\0')
	{
		if(*p==c)	return p-str;
		p++;
	}

	return -1;
	
}
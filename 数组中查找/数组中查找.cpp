// �����в���.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <process.h>

int StringFind(char str[],char c);

void main()
{
	char s[128];
	printf("�����ַ�����");
	scanf("%s",s);

	printf("����Ҫ���ҵ��ַ���");	
	fflush(stdin);
	char c=getchar();

	int Res=StringFind(s,c);

	if(Res>=0)
		printf("�ҵ��ˣ��ǵ�%d���ַ�\n",Res+1);
	else
		puts("û�ҵ���");

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
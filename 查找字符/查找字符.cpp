// �����ַ�.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int Serch(char str[],char c)
{
	int i=0;
	while(str[i] != '\0')
	{
		if (str[i]==c)	break;
		i++;
	}
	if(i=='\0')	return -1;
	else return i;
}

int main(int argc, char* argv[])
{
	char ss;
	char c[30];
	printf("����һ���ַ���");
	scanf("%s",c);
	char p=getchar();//���ջس��ַ�
	printf("������Ҫ���ҵ��ַ���");
	scanf("%c",&ss);
	int res=Serch(c,ss);
	if(res == -1)	printf("���޽��!\n");
	else printf("�ҵ��ˣ��ڵ�%dλ\n",res+1);


	return 0;
}

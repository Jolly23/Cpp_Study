// ת��ȫ��д ȫСд���.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <process.h>

void Toupper(char up[]);
void Tolower(char low[]);

int main(int argc, char* argv[])
{
	char str[64];
	printf("����һ���ַ�����");
	scanf("%s",str);
	Toupper(str);
	Tolower(str);
	system("pause");
	return 0;
}


void Toupper(char up[])
{
	int i=0;
	while(up[i] != '\0')
	{
		up[i]=toupper(up[i]);
		i++;
	}
	i=0;
	printf("��д��");
	while(up[i] != '\0')
	{
		printf("%c",up[i]);
		i++;
	}
	printf("\n");
}

void Tolower(char low[])
{
	int i=0;
	while(low[i] != '\0')
	{
		low[i]=tolower(low[i]);
		i++;
	}
	i=0;
	printf("Сд��");
	while(low[i] != '\0')
	{
		printf("%c",low[i]);
		i++;
	}
	printf("\n");
	
}
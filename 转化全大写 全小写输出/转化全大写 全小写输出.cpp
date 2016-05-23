// 转化全大写 全小写输出.cpp : Defines the entry point for the console application.
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
	printf("输入一段字符串：");
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
	printf("大写：");
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
	printf("小写：");
	while(low[i] != '\0')
	{
		printf("%c",low[i]);
		i++;
	}
	printf("\n");
	
}
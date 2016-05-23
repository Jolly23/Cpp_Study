// 查找字符.cpp : Defines the entry point for the console application.
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
	printf("输入一串字符：");
	scanf("%s",c);
	char p=getchar();//吸收回车字符
	printf("输入想要查找的字符：");
	scanf("%c",&ss);
	int res=Serch(c,ss);
	if(res == -1)	printf("查无结果!\n");
	else printf("找到了，在第%d位\n",res+1);


	return 0;
}

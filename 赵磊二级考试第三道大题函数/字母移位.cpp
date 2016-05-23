// 字母移位.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>


void main()
{
	char a[128];
	int s;
	printf("输入字母字符串：");
	scanf("%s",a);
	printf("输入转移开始位数：");
	scanf("%d",&s);
	int search='\0';
	while(search<=128)
	{
		if(a[search] == '\0')	break;
		search++;
	}


	char b[128];

	int func=0;

	while(func<=search)
	{
		b[func]=a[func+s];
		func++;
	}

	func=0;

	while(func<s)
	{
		b[search-s+func]=a[0+func];
		func++;
	}


	int d=0;
	while(d<search)
	{
		printf("%c",b[d]);
		d++;
	}
	printf("\n");
}

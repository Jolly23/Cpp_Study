// malloc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
#include <process.h>
#include <string.h>

int* MallocTest(int n)
{
	int i=0;
	int *p = (int*)malloc(sizeof(int)*n);
	int *l = p;
	while(l-p < n)
	{
		*l = (l-p)*5+1;
		l++;
	}
	int *q = p;
	while(q-p < n)
	{
		printf("p[%2d]=%d\n",q-p+1,*q);
		q++;
	}
	return p;
}

void main()
{
	int n;
	int *p;
	do
	{
		system("cls");
		printf("请输入要申请的空间个数：");
		scanf("%d",&n);
		p = MallocTest(n);
		free(p);
	}while(n);
	
	system("pause");
}

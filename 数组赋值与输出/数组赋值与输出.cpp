// 数组赋值与输出.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>


void main()
{
	char c[30];
	printf("输入多位数：");
	int a;
	scanf("%d",&a);
	sprintf(c,"%d",a);
	int bl;
	printf("要获得第几位数？:");
	scanf("%d",&bl);
	int ss=c[bl];
	printf("%c\n",'ss');
}


/*
int arr[10]={0};
int i=0;
int num;
printf("输入起始数：");
scanf("%d",&num);
while(i<sizeof(arr)/sizeof(arr[0]))
{
arr[i]=num;
num=num*9;

		printf("arr[%d]=%d\n",i,arr[i]);
		i++;
		}
*/
// ���鸳ֵ�����.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>


void main()
{
	char c[30];
	printf("�����λ����");
	int a;
	scanf("%d",&a);
	sprintf(c,"%d",a);
	int bl;
	printf("Ҫ��õڼ�λ����:");
	scanf("%d",&bl);
	int ss=c[bl];
	printf("%c\n",'ss');
}


/*
int arr[10]={0};
int i=0;
int num;
printf("������ʼ����");
scanf("%d",&num);
while(i<sizeof(arr)/sizeof(arr[0]))
{
arr[i]=num;
num=num*9;

		printf("arr[%d]=%d\n",i,arr[i]);
		i++;
		}
*/
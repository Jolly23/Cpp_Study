// ����С��Լ��.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <process.h>

int Dev(int a,int b);

int main(int argc, char* argv[])
{
	int x,y;
	printf("������������������С��Լ��(�ո���)��");
	scanf("%d %d",&x,&y);
	printf("%d��%d����С��Լ����%d\n",x,y,Dev(x,y));
	system("pause");
	return 0;
}



int Dev(int a,int b)
{
	int t;
	t=a<b?a:b;
	while(t)
	{
		if(a%t==0 && b%t==0)	break;
		t--;
	}
	return t;
}
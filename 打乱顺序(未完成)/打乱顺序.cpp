// ����˳��.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


void main()
{
	int package[128];
	int i=0,p=0;
	char useless;
	puts("**************************");
	puts("¼�����֣�������ֹ������x");
	puts("**************************");
	printf("\n");
	while(i<=127)
	{
		printf("�����%d������",i+1);
		scanf("%d",&package[i]);
		if(package[i]==-858993460)	break;
		i++;
		useless=getchar();
	}
	
	int total=i;
	int newstring[128];


	while(p<=i-1)
	{
		printf("%d\n",package[p]);
		p++;
	}
}

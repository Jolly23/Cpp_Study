#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <process.h>

void main()
{
	int a[128];
	char s[256];
	printf("请输入一串数字【空格间隔】：");
	gets(s);
	
	char *p = strtok(s," ");
	
	if(!p)
	{
		printf("\n原则错误！\n\n");
		system("pause");
		return;
	}	

	int n=0,i=0,sum=0;
	while(p)
	{
		a[n]=atoi(p);
		p = strtok(NULL," ");		
		n++;
	}
	while(i<n)
	{
		sum+=a[i];
		++i;
	}
	printf("\n共输入了%d个数字，总和为%d，平均数为%d\n\n",n,sum,sum/n);

	//Sort

	int v=0,u=0,t;

	while(v<n-1)
	{
		u=0;
		while(u<n-1)
		{
			
			if(a[u]>a[u+1])
			{
				t=a[u];
				a[u]=a[u+1];
				a[u+1]=t;
			}
			u++;

		}
		v++;

	}
	int *ptr=a;
	printf("数组从小到大排序结果为：");
	while(ptr-a<n)
		printf("%d ",*ptr++);
	printf("\n\n\n");
	system("pause");	
}


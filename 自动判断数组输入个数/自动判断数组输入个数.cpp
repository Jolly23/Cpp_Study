#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <process.h>

void main()
{
	int a[128];
	char s[256];
	printf("������һ�����֡��ո�������");
	gets(s);
	
	char *p = strtok(s," ");
	
	if(!p)
	{
		printf("\nԭ�����\n\n");
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
	printf("\n��������%d�����֣��ܺ�Ϊ%d��ƽ����Ϊ%d\n\n",n,sum,sum/n);

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
	printf("�����С����������Ϊ��");
	while(ptr-a<n)
		printf("%d ",*ptr++);
	printf("\n\n\n");
	system("pause");	
}


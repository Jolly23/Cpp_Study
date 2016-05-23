#include "stdafx.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	int i=0,j=0;
	int a[10]={27,39,5,12,994,26,51,67,137,512};
	while(i<9)
	{
		j=0;
			while(j<9)
			{
				if(a[j]>a[j+1])
				{
					int t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
				}
				j++;
			}
		i++;
	}
		
	int n=0;
	int *p=a;
	while(p-a<=9)
		printf("%d\n",*p++);
	return 0;
}

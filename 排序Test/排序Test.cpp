// ≈≈–ÚTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <process.h>


void MaopaoSort()
{
	int a[10] = {55,26,99,58,2,26,79,999,10,21};
	int i = 0, j = 0;
	while(i<9)
	{
		j = 0;
		
		while(j<9-i)
		{
			if(a[j] > a[j+1])
			{
				int t = a[j];
				a[j]  = a[j+1];
				a[j+1]= t;
			}
			++j;
		}
		
		++i;
	}
	i = 0;
	while(i<10)
		printf("a[%d] = %d\n",i++,a[i]);
}

void XuanzeSort()
{
	int a[10] = {55,26,99,58,2,26,79,999,10,21};
	int Max = 0,i = 0,j = 0;
	while(i<10)
	{
		j = i+1;
		Max = i;
		while(j<10)
		{
			if(a[j] > a[Max])
				Max = j;
			++j;
		}

		if(a[i] != a[Max])
		{
			int t = a[i];
			a[i] = a[Max];
			a[Max] = t;
		}

		++i;
	}
	i = 0;
	while(i < 10)
		printf("a[%d] = %d\n",i++,a[i]);
}

void  main()
{
	puts("√∞≈›≈≈–Ú∑®");
	MaopaoSort();
	puts("—°‘Ò≈≈–Ú∑®");
	XuanzeSort();
	system("pause");
}

// —°‘Ò≈≈–ÚSelectSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

void main()
{
	int a[]={61,5,55,22,51,26,32,15};
#define COUNT sizeof(a)/sizeof(a[0])

	int i=0,j=0,nMin=0;
	while(i < COUNT)
	{
		j=i+1;
		nMin=i;
		
		while(j < COUNT)
		{
			if(a[j] < a[nMin])
				nMin = j;
			++j;
		}
	
		if(i != nMin)
		{
			int t=a[nMin];
			a[nMin]=a[i];
			a[i]=t;
		}
	
		
		++i;
	}
	i=0;
	while(i<COUNT)
	{
		printf("%d\n",a[i]);
		++i;
	}
}

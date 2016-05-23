// ¶şÎ¬Êı×é²âÊÔ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

void Print(int a[][5],int n)
{
	int i = 0, j = 0;
	while(i < n )	//sizeof(a)/sizeof(a[0])
	{
		j = 0;
		while(j < sizeof(a[0])/sizeof(a[0][0]) )
		{
			printf("%d ",a[i][j]);
			++j;
		}
		printf("\n");
		++i;
	}
}

int main(int argc, char* argv[])
{
	int a[3][5] = {{5,7},{0},{6,8,1}};
	Print(a,sizeof(a)/sizeof(a[0]));
	return 0;
}

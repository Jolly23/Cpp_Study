// cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

void Swap(int *p1, int *p2);
void Print(int i, int j);

int main(int argc, char* argv[])
{
	bool b = true;
	int i = 999;
	int j = 9  ;

	Swap(&i,&j);
	
	Print(i,j);

	return 0;
}

void Swap(int *p1, int *p2)
{
	int t = *p1;
	*p1   = *p2;
	*p2   = t;
}

void Print(int i, int j)
{
	printf("i = %d , j = %d\n",i,j);
}
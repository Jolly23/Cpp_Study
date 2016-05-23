#include "stdafx.h"
#include <stdio.h>
#include <process.h>

int main(int argc, char* argv[])
{
	int i=1,s;
	while(i<=7)
	{
		s=1;
		while(s<=i)
		{
			printf("* ");
			s++;
		}
		printf("\n");
		i++;
	}
	
	while(i>7&&i<=13)
	{
		s=13-i;
		while(s>=0)
		{
			printf("* ");
			s--;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	printf("\n");
	system("pause");
	return 0;
}

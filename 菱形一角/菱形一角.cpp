// ¡‚–Œ“ªΩ«.cpp : Defines the entry point for the console application.
//

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
	printf("\n");
	printf("\n");
	system("pause");
	return 0;
}

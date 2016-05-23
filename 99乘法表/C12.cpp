#include "stdafx.h"
#include <stdio.h>
#include <process.h>

int main(int argc, char* argv[])
{
	int i=1,j=1;
	while(i<10)
	{
		j=1;
		while(j<=i)
		{	
			printf("%d*%d=%d\t",j,i,i*j);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	system("pause");
	return 0;
}

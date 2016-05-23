// C6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	int m,sum;
	printf("请输入售出数量（件）：");
	scanf("%d",&m);

	if(m<=20)
		sum=m*20;
	else
		if(m<=100)
			sum=m*30;
		else
			if(m<=500)
				sum=m*50;
			else
				sum=m*100;
			
	printf("\n\t提成=%d元\n\n\n\n\n\n",sum);



	return 0;
}

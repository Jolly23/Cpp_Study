
#include "stdafx.h"
#include <stdio.h>
#include <process.h>


int main(int argc, char* argv[])
{
	int i=101,s=2,sum=0;
	while(sum<=85)
	{
		s=2;
		while(s<i)
		{
			if(i%s==0) break;
			s++;
			if(i==s) 
			{
				printf("%d是素数\n",i);
				sum++;
			}
		}
		i++;		
	}
	//商标
	printf("\n\t赵磊-天津科技出品\n\n\n");
	system("pause");
	return 0;
}

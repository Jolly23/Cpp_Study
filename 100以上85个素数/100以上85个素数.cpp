
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
				printf("%d������\n",i);
				sum++;
			}
		}
		i++;		
	}
	//�̱�
	printf("\n\t����-���Ƽ���Ʒ\n\n\n");
	system("pause");
	return 0;
}

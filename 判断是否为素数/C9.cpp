#include "stdafx.h"
#include <stdio.h>
#include <process.h>

int main(int argc, char* argv[])
{
	int m;
	printf("检查一个数是否为素数\n请输入一个数字：");
	scanf("%d",&m);

	int c=2;
	while(c<m)
	{
		if(m%c==0)
			break;
		c++;
	}

	if(m==c) printf("%d是素数！\n",m);
	else printf("%d不是素数！\n",m);
	
	system("pause");
	
	return 0;
}

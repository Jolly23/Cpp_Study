#include "stdafx.h"
#include <stdio.h>
#include <process.h>

int main(int argc, char* argv[])
{
	int m;
	printf("���һ�����Ƿ�Ϊ����\n������һ�����֣�");
	scanf("%d",&m);

	int c=2;
	while(c<m)
	{
		if(m%c==0)
			break;
		c++;
	}

	if(m==c) printf("%d��������\n",m);
	else printf("%d����������\n",m);
	
	system("pause");
	
	return 0;
}

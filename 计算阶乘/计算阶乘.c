#include<stdio.h>
#include<process.h>

void main()

{  
	int i=2,n;

	long np=1;	

	printf("����һ����:");
	
	scanf("%d",&n);

	while(i<=n)
		
	{
		np*=i;
		
		i++;
	}
	
	printf("%d!=%ld\n",n,np);
	
	printf("\t\t����-�Ϲ�Ƽ���Ʒ\n");

	system("pause");	
}


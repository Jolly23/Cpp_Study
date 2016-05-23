#include<stdio.h>
#include<process.h>

void main()

{  
	int i=2,n;

	long np=1;	

	printf("输入一个数:");
	
	scanf("%d",&n);

	while(i<=n)
		
	{
		np*=i;
		
		i++;
	}
	
	printf("%d!=%ld\n",n,np);
	
	printf("\t\t赵磊-南光科技出品\n");

	system("pause");	
}


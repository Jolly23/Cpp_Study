#include<stdio.h>


int main(void)
{
	
	int a1,a2,a3,b,n,x,y,z,b1;
	
	int x1,x2,x3;
	
	printf("\n\n\n 请先将窗口最大化！！！");
	
	printf("\n\n\n 请输入一个3-10的数字，然后就将见证奇迹！！！\n\n");
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	
	printf(" made by 赵磊-南光科技\n");
	
	scanf("%d",&z);
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	
	printf("\n\n\n\n\n\n\n\n\n\n\n 送给最亲爱的闫霄宝宝:\n\n");
	
	if (z<6)
	{
		
		printf("\n\n");
		
		for (x1=1;x1<z;x1++)
			
		{
			n=3*z;
			
			
			for (x2=z;x2>x1-3;x2--)
				
				printf(" ");
			
			for (x2=z;x2<2*z+3*x1-3;x2++)
				
				printf("8");
			
			for (x2=0;x2<4*(z-x1)-2;x2++)
				
				printf(" ");
			
			for (x2=z;x2<2*z+3*x1-3;x2++)
				
				printf("8");
			
			printf("\n");
			
		}
		
	}
	
	else
		
	{
		
		for (x1=2;x1<z;x1++)
			
		{
			n=3*z;
			
			for (x2=z;x2>x1-3;x2--)
				
				printf(" ");
			
			for (x2=z;x2<2*z+3*x1-3;x2++)
				
				printf("8");
			
			for (x2=0;x2<4*(z-x1)-2;x2++)
				
				printf(" ");
			
			for (x2=z;x2<2*z+3*x1-3;x2++)
				
				printf("8");
			
			printf("\n");
			
		}
		
	}
	
	for (a1=0;a1<z;a1++)
		
	{
		
		if (a1!=1)
			
		{
			printf(" ");
			
			for (b=0;b<=a1;b++)
				
				printf(" ");
			
			for (x=0;x<2*(4*z-a1)-8;x++)
				
				printf("8");
			
			printf("\n");
			
		}
		
		else 
			
		{
			
			printf(" ");
			
			for (b=0;b<=a1;b++)
				
				printf(" ");
			
			for (b=1;b<4*z-10;b++)
				
				printf("8");
			
			printf(" I love you ");
			
			for (b=1;b<4*z-10;b++)
				
				printf("8");
			
			printf("\n");
			
		}
		
	}
	
	if (z<5)
		
	{
		
		for (a1=z,b1=0;a1<3*z;a1++,b1+=2)
			
		{
			
			printf(" ");
			
			for (b=z;b<=a1;b++)
				
				printf(" ");
			
			for (b=0;b<=a1;b++)
				
				printf(" ");
			
			for (x=2;x<2*(4*z-a1)-8-b1;x++)
				
				printf("8");
			
			printf("\n");
			
		}
		
		printf(" ——来自爱你的赵磊磊\n\n\n");
		
	}
	
	else if (z<7)
		
	{
		
		for (a1=z,b1=0;a1<3*z-5;a1++,b1+=2)
			
		{
			
			printf(" ");
			
			for (b=z;b<=a1;b++)
				
				printf(" ");
			
			for (b=0;b<=a1;b++)
				
				printf(" ");
			
			for (x=2;x<2*(4*z-a1)-8-b1;x++)
				
				printf("8");
			
			printf("\n");
			
		}
		
		printf(" ——来自爱你的赵磊磊\n");
		
	}
	
	else
		
	{
		
		for (a1=z,b1=0;a1<3*z-5;a1++,b1+=2)
			
		{
			
			printf(" ");
			
			for (b=z;b<=a1;b++)
				
				printf(" ");
			
			for (b=0;b<=a1;b++)
				
				printf(" ");
			
			for (x=2;x<2*(4*z-a1)-8-b1;x++)
				
				printf("8");
			
			printf("\n");
			
		}
		
		printf(" ——来自爱你的赵磊磊\n");
		
	}
	
	getchar();
	
	getchar();
	
	return 0;
	
}

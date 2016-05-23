// C3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <conio.h>

int main(int argc, char* argv[])
{
	int a;
	printf(" 输入一个十进制数字：\n");
	scanf("%d",&a);

	printf("此数字对应的二进制数是：");
		printf("%d",a/2/2/2/2/2/2/2%2);
			printf("%d",a/2/2/2/2/2/2%2);
				printf("%d",a/2/2/2/2/2%2);
					printf("%d",a/2/2/2/2%2);
						printf("%d",a/2/2/2%2);
							printf("%d",a/2/2%2);
								printf("%d",a/2%2);
									printf("%d\n",a%2);
										printf("\n\n\n\n\n此二进制数前的0可以省略不写，\n此程序仅可以转换十进制的整数，\n带小数的数字暂未支持。\n");
											printf("\n\n\t\t\t\t\t赵磊-天津科技出品\n");
	
												printf("\n\n\n\t\t亲爱的闫霄小同学，按任意键退出哦~     么\n");

	char b;
	getch();
	return 0;
}

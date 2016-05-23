// 计算器.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <process.h>
#include <windows.h>
#include <conio.h>



void main()
{
	while(1)
	{
		fflush;
		system("cls");
		puts("*******************");
		puts("1.加法");
		puts("2.减法");
		puts("3.乘法");
		puts("4.除法");
		puts("5.Cos");
		puts("6.Sin");
		puts("7.Tan");
		puts("8.指数函数");
		puts("0.退出程序");
		puts("*******************");
		printf("请选择计算模式：");
		
		
		int mode;
		mode=getch();

		if(mode!='1')
			if(mode!='2')
				if(mode!='3')
					if(mode!='4')
						if(mode!='5')
							if(mode!='6')
								if(mode!='7')
									if(mode!='8')
										if(mode!='0')
										{
											puts("输入有误！");	
											printf("\n");
											system("pause");
											continue;
										}

		if(mode=='0')	return;
		
		double a,b;
		puts("\n\n输入两个数（空格间隔）：");
		scanf("%lf %lf",&a,&b);
		
		unsigned long Time=GetTickCount();

		if(mode=='1')
		{
			printf("结果是%lf\n",a+b);
		}
		
		if(mode=='2')
		{
			printf("结果是%lf\n",a-b);
		}
		
		if(mode=='3')
		{
			printf("结果是%lf\n",a*b);
		}
		
		if(mode=='4')
		{
			printf("结果是%lf\n",a/b);
		}
		
		if(mode=='5')
		{
			printf("结果是%lf\n",cos(a));
		}
		
		if(mode=='6')
		{
			printf("结果是%lf\n",sin(a));
		}
		
		if(mode=='7')
		{
			printf("结果是%lf\n",tan(a));
		}
		
		if(mode=='8')
		{
			printf("结果是%lf\n",pow(a,b));
		}	
		puts("****************************");
		printf("本次操作系统运算了%d毫秒\n",GetTickCount()-Time);
		puts("****************************");
										printf("\t\t电子141-赵磊\n");
										system("pause");
										
	}	
}




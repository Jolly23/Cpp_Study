// 输出指定数量的素数.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <stdio.h>
#include <process.h>
#include <windows.h>
#include <conio.h>


int PrimeNums1(int Begin,int Nums)
{
	int Gross=0;
	printf("从%d起，输出%d个素数\n",Begin,Nums);
	while(Gross<Nums)
	{
		int i=2;
		while(i<Begin)
		{
			if(Begin%i==0)	break;
			i++;
			if(Begin==i)
			{
				printf("第%d个素数是%d\n",Gross+1,Begin);
				Gross++;
			}
		}
		Begin++;
	}
	printf("\n******************************\n");
	return 0;
}

int PrimeNums2(int Min,int Max)
{
	int Begin=Min;
	int gross=0;
	while(Min<=Max)
	{
		int i=2;
		while(i<Min)
		{
			if(Min%i==0)	break;
			i++;
			if(Min==i)
			{
				printf("%d是素数\n",Min);
				gross++;
			}
		}
		Min++;
	}
	printf("从%d到%d之间，共有%d个素数\n",Begin,Max,gross);
	return 0;
}






void main()
{
	while(1)
	{
		system("cls");
		fflush;
		
		int mode;
		
		puts("****************************************");
		puts("1.从某数开始输出指定数量的素数");
		puts("2.从某数开始到某数结束输出之间所有素数");
		puts("0.退出程序");
		puts("****************************************");
		puts("请选择模式：");
		
		mode=getch();
		if(mode=='1')
		{
			
			int a,b;
			puts("输入寻找素数的起始数:");
			scanf("%d",&a);
			puts("输入需要输出的素数数量:");
			scanf("%d",&b);
			
			unsigned long Time=GetTickCount();
			
			puts("*****************************\n搜索结果是：");
			PrimeNums1(a,b);
			printf("本次操作系统运算了%d毫秒\n",GetTickCount()-Time);
			puts("******************************\n");
			
			system("pause");
		}
		
		if(mode=='2')
		{
			int a,b;
			puts("输入寻找素数的起始数:");
			scanf("%d",&a);
			puts("输入寻找素数的终止数:");
			scanf("%d",&b);
			unsigned long Time=GetTickCount();
			puts("搜索结果是：");
			PrimeNums2(a,b);
			puts("*********************");
			printf("本次运算用了%d毫秒\n",GetTickCount()-Time);
			puts("*********************");
			system("pause");
		}
		
		if(mode=='0')
		{
			puts("\t\t赵磊-天津科技出品");
			system("pause");
			return;
		}
		
		
		if(mode!='1' && mode!='2')
			if(mode!='0')
			{
				puts("输入有误");
				system("pause");
			}
	}
	
}


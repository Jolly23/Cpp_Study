// ���ָ������������.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <stdio.h>
#include <process.h>
#include <windows.h>
#include <conio.h>


int PrimeNums1(int Begin,int Nums)
{
	int Gross=0;
	printf("��%d�����%d������\n",Begin,Nums);
	while(Gross<Nums)
	{
		int i=2;
		while(i<Begin)
		{
			if(Begin%i==0)	break;
			i++;
			if(Begin==i)
			{
				printf("��%d��������%d\n",Gross+1,Begin);
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
				printf("%d������\n",Min);
				gross++;
			}
		}
		Min++;
	}
	printf("��%d��%d֮�䣬����%d������\n",Begin,Max,gross);
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
		puts("1.��ĳ����ʼ���ָ������������");
		puts("2.��ĳ����ʼ��ĳ���������֮����������");
		puts("0.�˳�����");
		puts("****************************************");
		puts("��ѡ��ģʽ��");
		
		mode=getch();
		if(mode=='1')
		{
			
			int a,b;
			puts("����Ѱ����������ʼ��:");
			scanf("%d",&a);
			puts("������Ҫ�������������:");
			scanf("%d",&b);
			
			unsigned long Time=GetTickCount();
			
			puts("*****************************\n��������ǣ�");
			PrimeNums1(a,b);
			printf("���β���ϵͳ������%d����\n",GetTickCount()-Time);
			puts("******************************\n");
			
			system("pause");
		}
		
		if(mode=='2')
		{
			int a,b;
			puts("����Ѱ����������ʼ��:");
			scanf("%d",&a);
			puts("����Ѱ����������ֹ��:");
			scanf("%d",&b);
			unsigned long Time=GetTickCount();
			puts("��������ǣ�");
			PrimeNums2(a,b);
			puts("*********************");
			printf("������������%d����\n",GetTickCount()-Time);
			puts("*********************");
			system("pause");
		}
		
		if(mode=='0')
		{
			puts("\t\t����-���Ƽ���Ʒ");
			system("pause");
			return;
		}
		
		
		if(mode!='1' && mode!='2')
			if(mode!='0')
			{
				puts("��������");
				system("pause");
			}
	}
	
}


// ������.cpp : Defines the entry point for the console application.
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
		puts("1.�ӷ�");
		puts("2.����");
		puts("3.�˷�");
		puts("4.����");
		puts("5.Cos");
		puts("6.Sin");
		puts("7.Tan");
		puts("8.ָ������");
		puts("0.�˳�����");
		puts("*******************");
		printf("��ѡ�����ģʽ��");
		
		
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
											puts("��������");	
											printf("\n");
											system("pause");
											continue;
										}

		if(mode=='0')	return;
		
		double a,b;
		puts("\n\n�������������ո�������");
		scanf("%lf %lf",&a,&b);
		
		unsigned long Time=GetTickCount();

		if(mode=='1')
		{
			printf("�����%lf\n",a+b);
		}
		
		if(mode=='2')
		{
			printf("�����%lf\n",a-b);
		}
		
		if(mode=='3')
		{
			printf("�����%lf\n",a*b);
		}
		
		if(mode=='4')
		{
			printf("�����%lf\n",a/b);
		}
		
		if(mode=='5')
		{
			printf("�����%lf\n",cos(a));
		}
		
		if(mode=='6')
		{
			printf("�����%lf\n",sin(a));
		}
		
		if(mode=='7')
		{
			printf("�����%lf\n",tan(a));
		}
		
		if(mode=='8')
		{
			printf("�����%lf\n",pow(a,b));
		}	
		puts("****************************");
		printf("���β���ϵͳ������%d����\n",GetTickCount()-Time);
		puts("****************************");
										printf("\t\t����141-����\n");
										system("pause");
										
	}	
}




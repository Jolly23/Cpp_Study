// �������ڼ��.cpp : Defines the entry point for the console application.
//

/*
V1.0: 2015��6��3�շ���������Ϊ���������������ڼ������졣
V1.1������˵�

*/

#include "stdafx.h"
#include <stdio.h>
#include <process.h>
#include <string.h>
#include <conio.h>

struct SDate
{
	int nYear;
	int nMonth;
	int nDay;
};

int Menu()
{
	int mode;
	puts("************************");
	puts("1.����������������");
	puts("2.����ĳ���ǵ���ĵڼ���");
	puts("0.�˳�����");
	printf("\n");
	puts("***���๦�����ڿ�����***");
	puts("************************");
	mode = getch();
	return mode;
}

void main()
{	
	int mode,gross,judge1,judge2;
	int input1,input2,sum=0,mon,yea;
	SDate a1,a2;
	while(1)
	{
		sum=0;
		
		system("cls");
		
		mode = Menu();
		
		system("cls");
		if(mode == '1')
		{
			system("cls");
			printf("������ʼ�����գ�����20140601����");
			scanf("%d",&input1);
			
			a1.nYear  = input1/10000;
			a1.nMonth = input1/100%100;
			a1.nDay   = input1%100;	
			judge1 = input1;
			gross = 0;
			while(judge1)
			{
				judge1/=10;
				gross++;
			}
			if(gross < 5)
			{
				printf("������������\n");
				system("pause");
				return;
			}
			printf("������ֹ�����գ�����20140701����");
			scanf("%d",&input2);
			
			a2.nYear  = input2/10000;
			a2.nMonth = input2/100%100;
			a2.nDay   = input2%100;
			judge2 = input2;
			gross = 0;
			while(judge2)
			{
				judge2/=10;
				gross++;
			}
			if(gross < 5)
			{
				printf("������������\n");
				system("pause");
				return;
			}
			
			if(input1 > input2)//��ʼ���ڱ���ֹ����������
			{
				printf("�����䷴�˰ɣ�\n");
				system("pause");
				return;
			}
			if(a1.nMonth>12 || a2.nMonth>12)
			{
				printf("������������\n");
				system("pause");
				return;
			}
			
			
			if(a1.nYear == a2.nYear)//ͬ��
			{
				if(a1.nMonth == a2.nMonth)//ͬ��
					sum = a2.nDay-a1.nDay;
				
				else //��ͬ��
				{
					mon=a1.nMonth+1;
					while(mon < a2.nMonth)
					{
						if(mon == 2)	
						{
							if(a1.nYear%4==0 && a1.nYear%100!=0 || a1.nYear%400==0)
								sum+=29;
							else
								sum+=28;
						}
						if(mon == 3)	sum+=31;
						if(mon == 4)	sum+=30;
						if(mon == 5)	sum+=31;
						if(mon == 6)	sum+=30;
						if(mon == 7)	sum+=31;
						if(mon == 8)	sum+=31;
						if(mon == 9)	sum+=30;
						if(mon == 10)	sum+=31;
						if(mon == 11)	sum+=30;
						if(mon == 12)	sum+=31;
						
						mon++;
					}
					if(a1.nMonth == 1)	sum=sum+31-a1.nDay;
					if(a1.nMonth == 2)	
					{
						if(a1.nYear%4==0 && a1.nYear%100!=0 || a1.nYear%400==0)
							sum=sum+29-a1.nDay;
						else
							sum=sum+28-a1.nDay;
					}
					if(a1.nMonth == 3)	sum=sum+31-a1.nDay;
					if(a1.nMonth == 4)	sum=sum+30-a1.nDay;
					if(a1.nMonth == 5)	sum=sum+31-a1.nDay;
					if(a1.nMonth == 6)	sum=sum+30-a1.nDay;
					if(a1.nMonth == 7)	sum=sum+31-a1.nDay;
					if(a1.nMonth == 8)	sum=sum+31-a1.nDay;
					if(a1.nMonth == 9)	sum=sum+30-a1.nDay;
					if(a1.nMonth == 10)	sum=sum+31-a1.nDay;
					if(a1.nMonth == 11)	sum=sum+30-a1.nDay;
					if(a1.nMonth == 12)	sum=sum+31-a1.nDay;
					
					sum+=a2.nDay;
					
				}
			}
			
			else //��ͬ��
			{
				yea=a1.nYear+1;
				while(yea < a2.nYear)
				{
					if(yea%4==0 && yea%100!=0 || yea%400==0)
						sum+=366;
					else
						sum+=365;
					yea++;
				}
				mon=a1.nMonth+1;
				while(mon<=12)
				{
					if(mon == 1)	sum+=31;
					if(mon == 2)	
					{
						if(a1.nYear%4==0 && a1.nYear%100!=0 || a1.nYear%400==0)
							sum+=29;
						else
							sum+=28;
					}
					if(mon == 3)	sum+=31;
					if(mon == 4)	sum+=30;
					if(mon == 5)	sum+=31;
					if(mon == 6)	sum+=30;
					if(mon == 7)	sum+=31;
					if(mon == 8)	sum+=31;
					if(mon == 9)	sum+=30;
					if(mon == 10)	sum+=31;
					if(mon == 11)	sum+=30;
					if(mon == 12)	sum+=31;
					
					mon++;
				}
				if(a1.nMonth == 1)	sum=sum+31-a1.nDay;
				if(a1.nMonth == 2)	
				{
					if(a1.nYear%4==0 && a1.nYear%100!=0 || a1.nYear%400==0)
						sum=sum+29-a1.nDay;
					else
						sum=sum+28-a1.nDay;
				}
				if(a1.nMonth == 3)	sum=sum+31-a1.nDay;
				if(a1.nMonth == 4)	sum=sum+30-a1.nDay;
				if(a1.nMonth == 5)	sum=sum+31-a1.nDay;
				if(a1.nMonth == 6)	sum=sum+30-a1.nDay;
				if(a1.nMonth == 7)	sum=sum+31-a1.nDay;
				if(a1.nMonth == 8)	sum=sum+31-a1.nDay;
				if(a1.nMonth == 9)	sum=sum+30-a1.nDay;
				if(a1.nMonth == 10)	sum=sum+31-a1.nDay;
				if(a1.nMonth == 11)	sum=sum+30-a1.nDay;
				if(a1.nMonth == 12)	sum=sum+31-a1.nDay;
				
				mon=1;
				while(mon < a2.nMonth)
				{
					if(mon == 1)	sum+=31;
					if(mon == 2)	
					{
						if(a1.nYear%4==0 && a1.nYear%100!=0 || a1.nYear%400==0)
							sum+=29;
						else
							sum+=28;
					}
					if(mon == 3)	sum+=31;
					if(mon == 4)	sum+=30;
					if(mon == 5)	sum+=31;
					if(mon == 6)	sum+=30;
					if(mon == 7)	sum+=31;
					if(mon == 8)	sum+=31;
					if(mon == 9)	sum+=30;
					if(mon == 10)	sum+=31;
					if(mon == 11)	sum+=30;
					if(mon == 12)	sum+=31;
					
					mon++;
				}
				sum+=a2.nDay;
				
				
			}
			printf("%d��%d��%d����%d��%d��%d�ռ���� %d ��\n\n",a1.nYear,a1.nMonth,a1.nDay,a2.nYear,a2.nMonth,a2.nDay,sum);
			system("pause");
	}
	
	if(mode == '2')
	{
		int input,sum=0;
		SDate a1;
		printf("���������գ�����20140601����");
		scanf("%d",&input);
		a1.nYear  = input/10000;
		a1.nMonth = input/100%100;
		a1.nDay   = input%100;	
		
		switch(a1.nMonth)
		{
		case 1:		sum=a1.nDay;		break;
		case 2:		sum=a1.nDay+31;		break;
		case 3:		sum=a1.nDay+59;		break;
		case 4:		sum=a1.nDay+90;		break;
		case 5:		sum=a1.nDay+120;	break;
		case 6:		sum=a1.nDay+151;	break;
		case 7:		sum=a1.nDay+181;	break;
		case 8:		sum=a1.nDay+212;	break;
		case 9:		sum=a1.nDay+243;	break;
		case 10:	sum=a1.nDay+273;	break;
		case 11:	sum=a1.nDay+304;	break;
		case 12:	sum=a1.nDay+334;	break;
		default:	
			{
				puts("��������");	
				system("pause");
				return;
			}
		}
		if(a1.nMonth>2)
			if(a1.nYear%4==0 && a1.nYear%100!=0 || a1.nYear%400==0)	//�����ж�
				sum++;
			printf("%d��%d��%d���ǵ���ĵ�%d�죡\n",a1.nYear,a1.nMonth,a1.nDay,sum);
			system("pause");
	}
	
	
	if(mode == '0')
	{
		puts("��ѡ�����˳�����");
		puts("\t\t\t����-���Ƽ���Ʒ");
		system("pause");
		return;
	}

	if(mode != '0' && mode != '1' && mode != '2')
	{
		puts("������������������");
		system("pause");
	}
	}
	
}	

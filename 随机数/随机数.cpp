// �����.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void Arve(double Sum,int n);
void Print2(double a[][12],int n);
void Print3(double a[][12],int n);
void Print4(double a[][12],int n);

void Print(double a[][12],int n)
{
	int i = 0, j = 0;
	double Sum = 0;
	while(i < n )
	{
		j = 0;
		while(j < sizeof(a[0]) / sizeof(a[0][0]) )
		{
			printf("%.2lf ",a[i][j]);
			Sum += a[i][j];
			++j;
		}
		puts("");
		++i;
	}
	Arve(Sum,n);
}

void Arve(double Sum,int n)
{
	printf("ƽ��ÿ�»���Ϊ %.2lf Ԫ\n",Sum/(n*12));
}

void main()
{
	double a[4][12] = {0};
	int i = 0, j = 0;
    srand( (unsigned)time( NULL ) );

	while(i < sizeof(a) / sizeof(a[0]) )
	{
		j = 0;
		while(j < sizeof(a[0]) / sizeof(a[0][0]) )
		{
			a[i][j] =  1000+rand()%1000 ;
			a[i][j] += (double)(rand()%100)/100 ;
			++j;
		}
		++i;
	}

	Print(a,sizeof(a) / sizeof(a[0]));
	Print2(a,sizeof(a) / sizeof(a[0]));
	Print3(a,sizeof(a) / sizeof(a[0]));
	Print4(a,sizeof(a) / sizeof(a[0]));	
	
	system("pause");
}

void Print2(double a[][12],int n)
{
	int i = 0, j = 0 ;
	double sum = 0.0;
	while(i < n)
	{
		sum = 0.0;
		j = 0;
		while(j<12)
		{
			sum += a[i][j];
			++j;
		}
		printf("��%d�������� %.2lf Ԫ����ƽ������ %.2lf Ԫ\n",i+1,sum,sum/12);
		++i;
	}
}

void Print3(double a[][12],int n)
{
	int i = 0, j = 0 ;
	double sum = 0.0;
	while(i < 12)
	{
		sum = 0.0;
		j = 0;
		while(j<n)
		{
			sum += a[j][i];
			++j;
		}
		printf(" %2d ��ƽ������ %.2lfԪ\n",i+1,sum/n);
		++i;
	}
}

void Print4(double a[][12],int n)
{
	int i = 0, j = 0 ,q = 0,b = 0;
	double Max = 0.0;
	while(i < n)
	{
		j = 0;
		while(j<12)
		{
			if(Max < a[i][j])
			{
				Max= a[i][j];
				q = i;
				b = j;
			}
			++j;
		}
		++i;
	}

	printf("4���У�������ߵ��ǵ�%d��ĵ�%d�£������� %.2lf Ԫ\n",q,b,Max);

}
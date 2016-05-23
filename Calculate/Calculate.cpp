// Calculate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

double Cal(double lfLeft,double lfRight,char c)
{
	switch(c)
	{
	case '+':
		return lfLeft + lfRight;
		break;
	case '-':
		return lfLeft - lfRight;
		break;
	case '*':
		return lfLeft * lfRight;
		break;
	case '/':
		return lfLeft / lfRight;
		break;
	default:
		puts("������Ų�֧�֣�");
		break;
	}
}

int  Find(char *sArg)
{
	const char *OPT = "+-*/";
	int i = 0;
	while(OPT[i])
	{
		char *p = strchr(sArg,OPT[i]);
		if(p)
			return p-sArg;
		++i;
	}
	
	
	return -1;
}

int main(int argc, char* argv[])
{
	puts("�����֧�� + - * / ���밴�����¸�ʽ����  A + B");
	
	if(argv[1] == NULL)
	{
		puts("��Ч��");
		return -1;
	}
	char *sArg = argv[1];
	char s[200];
	memset(s,0,sizeof(s));
	strcpy(s,argv[1]);
	if(argv[2])
	{
		strcat(s,argv[2]);
		if(argv[3])
			strcat(s,argv[3]);
	}

	int nIndex = Find(s);
	if(nIndex == -1)
	{
		puts("��û��������Ч�ķ��ţ�");
		puts("�����֧�� + - * / ");
		return -1;
	}
	char c = s[nIndex];
	s[nIndex] = 0;
	double lfLeft = atof(s);
	char *p = s + nIndex+1;
	double lfRight = atof(p);
//	printf("%lf %lf\n",lfLeft,lfRight);
	double nRes = Cal(lfLeft,lfRight,c);
	printf("%.2lf %c %.2lf = %.2lf\n",lfLeft,c,lfRight,nRes);

	
	return 0;
}

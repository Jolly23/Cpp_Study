// 学生成绩求平均、最大.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

struct SSTU
{
	int nNumb;
	char sName[20];
	float fMath;
	float fChin;
	float fEngl;
}*pp;

int main(int argc, char* argv[])
{
	SSTU st[10]={
		{9511,"赵磊",95.5f,96,99},
		{2011,"A062",15.6f,99.5f,97},
		{1126,"丽丽",80,68,99.5},
		{2528,"守着",95,88,56},
		{9888,"阿阿",84.5f,65.5f,99},
		{2017,"默默",53.8f,27.4f,85},
		{6054,"包子",68.5f,78,95},
		{5033,"王啊",75.5f,63,58},
		{4096,"YAOMING",69.5f,47,99},
		{5527,"张媛",58,99,99}
				};
	int i=0;

	SSTU t;
	unsigned int o=0,p=0;
	while(o<sizeof(st)/sizeof(st[0]))
	{
		p=0;
		while(p<sizeof(st)/sizeof(st[0])-o)
		{
			if(strcmp(st[p].sName,st[p+1].sName) == 1)
			{
				t=st[p];
				st[p]=st[p+1];
				st[p+1]=t;
			}
				p++;
		}
		o++;
	}
	i=0;
	pp=st;
	puts("按名字顺序排序：");
	while(pp-st<sizeof(st)/sizeof(st[0]))
	{
		printf("%d\t%s\t%.1f\t%.1f\t%.1f\t\t%.1f\n",pp->nNumb,pp->sName,pp->fMath,pp->fChin,pp->fEngl,
			(pp->fMath+pp->fChin+pp->fEngl)/3);
		pp++;
	}
 
	
	printf("\n\n");
	o=0,p=0;
	int Max=0;
	while(o<sizeof(st)/sizeof(st[0]))
	{
		p=0;
		while(p<sizeof(st)/sizeof(st[0])-o)
		{
			if(st[p].nNumb>st[p+1].nNumb)
			{
				t=st[p];
				st[p]=st[p+1];
				st[p+1]=t;
			}
				p++;
		}
		o++;
	}
	i=0;
	pp=st;
	puts("按学号顺序排序：");
	while(i<sizeof(st)/sizeof(st[0]))
	{
		printf("%d\t%s\t%.1f\t%.1f\t%.1f\t\t%.1f\n",st[i].nNumb,st[i].sName,st[i].fMath,st[i].fChin,st[i].fEngl,
			(st[i].fMath+st[i].fChin+st[i].fEngl)/3);
		if(((st[i].fMath+st[i].fChin+st[i].fEngl)/3) > ((st[Max].fMath+st[Max].fChin+st[Max].fEngl)/3))
			Max=i;
		i++;
	}
	puts("成绩最好的同学是：");
	printf("%d\t%s\t%.1f\t%.1f\t%.1f\t\t%.1f\n",st[Max].nNumb,st[Max].sName,st[Max].fMath,st[Max].fChin,st[Max].fEngl,
			(st[Max].fMath+st[Max].fChin+st[Max].fEngl)/3);

	return 0;
}

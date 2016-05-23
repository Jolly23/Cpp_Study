#include "stdsfx.h"
#include <stdio.h>
#include <process.h>


void SortByNumb()
{
	system("cls");
	puts("你选择了：按学号排序");
	int i=0,j=0,nCount=0,n=0;
	SSTU t;
	while(g_stud[nCount].nNumb && nCount < COUNT)
		++nCount;
	int gross = Gross(nCount);
	while(i < nCount-1)
	{
		j=0;
		while(j<nCount-i-1)
		{
			if(g_stud[j].nNumb > g_stud[j+1].nNumb)
			{
				t			=	g_stud[j];
				g_stud[j]	=	g_stud[j+1];
				g_stud[j+1]	=	t;
			}
			++j;
		}
		++i;
	}
	printf("目前共有%d个学生的信息\n",gross);
	puts("学号\t姓名\t数学");
	while(n < nCount)
	{
		if(g_stud[n].nNumb > 0)
			printf("%d\t%s\t%.1f\n",g_stud[n].nNumb,g_stud[n].sName,g_stud[n].fMath);
		++n;
	}
	system("pause");
}
void SortByName()
{
	system("cls");
	puts("你选择了：按姓名排序");
	int i=0,j=0,nCount=0,n=0;
	SSTU t;
	while(g_stud[nCount].nNumb && nCount < COUNT)
		++nCount;
	int gross = Gross(nCount);
	while(i < nCount-1)
	{
		j=0;
		while(j<nCount-i-1)
		{
			if(strcmp(g_stud[j].sName , g_stud[j+1].sName ) == 1)
			{
				t			=	g_stud[j];
				g_stud[j]	=	g_stud[j+1];
				g_stud[j+1]	=	t;
			}
			++j;
		}
		++i;
	}
	printf("目前共有%d个学生的信息\n",gross);
	puts("学号\t姓名\t数学");
	while(n < nCount)
	{
		if(g_stud[n].nNumb > 0)
			printf("%d\t%s\t%.1f\n",g_stud[n].nNumb,g_stud[n].sName,g_stud[n].fMath);
		++n;
	}
	system("pause");
}
void SortByMath()
{
	system("cls");
	puts("你选择了：按数学成绩排序");
	int i=0,j=0,nCount=0,n=0;
	SSTU t;
	while(g_stud[nCount].nNumb && nCount < COUNT)
		++nCount;
	int gross = Gross(nCount);
	while(i < nCount-1)
	{
		j=0;
		while(j<nCount-i-1)
		{
			if(g_stud[j].fMath < g_stud[j+1].fMath)
			{
				t			=	g_stud[j];
				g_stud[j]	=	g_stud[j+1];
				g_stud[j+1]	=	t;
			}
			++j;
		}
		++i;
	}
	printf("目前共有%d个学生的信息\n",gross);
	puts("学号\t姓名\t数学");
	while(n < nCount)
	{
		if(g_stud[n].nNumb > 0)
			printf("%d\t%s\t%.1f\n",g_stud[n].nNumb,g_stud[n].sName,g_stud[n].fMath);
		++n;
	}
	system("pause");
}
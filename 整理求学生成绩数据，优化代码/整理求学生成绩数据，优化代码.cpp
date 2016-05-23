#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <process.h>

struct SSTU
{
	int nNumb;
	char sName[20];
	float fMath;
	float fChin;
	float fEngl;
	float fAver;
};

void Output(SSTU *st,int i);//输出函数声明
void Aver(SSTU *st,int i);//求平均函数声明
int Input(SSTU *st,int nSize);//录入信息函数

void main()
{
	SSTU st[100];

	int i = Input(st,sizeof(st)/sizeof(st[0]));

	Output(st,i);

	system("pause");
}



int Input(SSTU *st,int nSize)//录入信息函数
{	
	SSTU *LS=st;
	printf("最多统计100个学生的信息，停止输入请输入 0 stop\n");
	while(LS-st<nSize)
	{
		printf("输入第%d个学生的学号、姓名【空格间隔】：",LS-st+1);
		scanf("%d %s",&LS->nNumb,&LS->sName);
		if(memcmp(&LS->sName,"stop",sizeof("stop")) == 0)		break;
		printf("输入他的数学、语文、英语成绩【空格间隔】：");
		scanf("%f %f %f",&LS->fMath,&LS->fChin,&LS->fEngl);
		printf("\n");
		LS++;
	}
	system("cls");
	puts("信息录入完成！\n");

	return LS-st;
	
}


void Output(SSTU *st,int i)//多功能输出函数
{
	int mode = 1;

	SSTU *LS=st;

	if(mode == 1)
	{
		puts("你选择的是输出全体同学成绩的平均数");
		Aver(st,i);//调用求平均数函数
		while(LS-st<i)
		{
			printf("%-8s的平均分是 %.1f\n",LS->sName,LS->fAver);
			LS++;
		}
	}

}

void Aver(SSTU *st,int i)//求平均函数
{
	SSTU *LS=st;
	while(LS-st<i)
	{
		LS->fAver = (LS->fChin + LS->fMath + LS->fEngl)/3;
		LS++;
	}
}

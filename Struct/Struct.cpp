// Struct.cpp : Defines the entry point for the console application.
//
//Version bate 0.1    工程师：赵磊

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <process.h>
#include <windows.h>

typedef struct Students STU;//宏定义

struct fScore    //成绩信息
{
	float fChin;//语文成绩
	float fMath;//数学成绩
	float fEngl;//英语成绩
};
struct Students  //学生信息
{
	int nNumb;//学号
	char sName[20];//姓名
	struct fScore Sc;//调取成绩结构体
};
void Input(STU *pSTU)//结构体输入函数
{
	printf("请输入学号和姓名【空格间隔】:");
	scanf("%d %s",&pSTU->nNumb,pSTU->sName);
	printf("请输入语文成绩：");
	scanf("%f",&pSTU->Sc.fChin);
	printf("请输入数学成绩：");
	scanf("%f",&pSTU->Sc.fMath);
	printf("请输入英语成绩：");
	scanf("%f",&pSTU->Sc.fEngl);
}
void Output(STU *pout)//结构体输出函数
{
	puts("学号\t姓名\t语文\t数学\t英语");
	printf("%d\t%s\t%.1f\t%.1f\t%.1f\n",pout->nNumb,pout->sName,pout->Sc.fChin,pout->Sc.fMath,pout->Sc.fEngl);
}

STU D141[100]=
{
	{2000,"LTL",{16,16,16}},
	{2001,"LZG",{93,93,93}}
};

void main()//主函数（功能有待扩展）
{
	STU s1,s2,s3,*ptr;
	memset(&s1,0,sizeof(STU));
	Input(&s1);
	Output(&s1);
	memset(&s1,0,sizeof(STU));

	system("pause");
}

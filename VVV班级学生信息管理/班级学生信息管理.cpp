// 班级学生信息管理.cpp : Defines the entry point for the console application.
//

/*
V1.0 2015年6月5日发布，整合浏览、添加、查找、修改、删除功能
V1.1 2015年6月7日	 ，加入浏览模式选择功能，支持多种方式排序浏览，优化视觉效果，加强用户使用友好度。
V1.2 2015年6月8日	 ，加强用户使用友好度。
V1.3 2015年6月8日	 ，重大更新：加入数据保存函数，软件数据可保存，并多次使用！
V1.4 2015年6月16日	 ，调整主函数运行顺序，程序更加精简。
V1.5 2015年7月17日	 ，增加大量功能，完善删除、修改机制
V1.6 2015年7月17日	 ，紧急修复排序错误
V1.7 2015年7月18日	 ，增加条件筛选浏览功能、修复错误、优化保存数据机制，防止非正常退出程序导致的数据丢失
V1.8 2015年7月18日	 ，增加数据分析功能
V1.9 2015年7月18日	 ，修复已知的BUG
V2.0 2015年7月20日	 ，紧急修复数据 删除、修改后 无法保存的问题，优化数据分析的结果显示
*/

#include "stdafx.h"
#include <stdio.h>
#include <process.h>
#include <conio.h>
#include <string.h>
#include <vector>
#include <algorithm>


struct SSTU
{
	char sName[20];
	int  nNumb;
	float fMath;
}	g_stud[100];

#define COUNT sizeof(g_stud)/sizeof(g_stud[0])

void Version()			;	//显示程序版本号
int  Menu()				;	//主功能菜单
void Browse()			;	//浏览功能菜单
void AutoSort()			;	//特定条件下展示数据前先按学号排序
void SortByName()		;	//按姓名顺序排列数据
void SortByNumb()		;	//按学号顺序排列数据
void SortByMath()		;	//按数学成绩排列数据
void Insert()			;	//添加数据
void Search()			;	//搜索功能菜单
void SearchNumb()		;	//通过学号搜索数据
void SearchName()		;	//通过姓名搜索数据
void Modify()			;	//修改数据功能菜单
void ModifyNumb()		;	//通过学号查找并修改数据
void ModifyName()		;	//通过姓名查找并修改数据
void Delete()			;	//删除功能菜单
void DeleteNumb()		;	//通过学号删除数据
void DeleteName()		;	//通过姓名删除数据
void Print()			;	//输出数据
void Load()				;	//载入数据
void Save()				;	//保存数据
void Condition()		;	//条件筛选浏览
int  AllData()			;	//当前储存的有效数据数量
void DeleteAll();		;	//清空当前全部数据
void DataAnalyse()		;	//数据分析
bool Compare(SSTU& s1, SSTU& s2)	;


void main()
{
	float f=0.0f;
	Load();
	while( Menu() != '0' );
	system("cls");
	Save();			//此处的Save调用为以防万一，防止特殊情况下部分数据未保存造成的数据丢失
	printf("\n\n\t\t\t天津科技出品\n\n\n");
	system("pause");
}

void Load()	
{
	FILE *pf = fopen("./stud.lqm","a+");	//可读可写
	int i=0;
	while(fread(&g_stud[i],1,sizeof(SSTU),pf))		//fread(&g_stud[i],1,sizeof(SSTU),pf) 读取文件，直到尾部
		++i;
}

void Save()	
{
	int i=0;
	FILE *pf = fopen("./stud.lqm","w");
	while(g_stud[i].nNumb && i<COUNT)	
	{
		if(g_stud[i].nNumb > 0)
			fwrite(&g_stud[i],1,sizeof(SSTU),pf);
		++i;
	}
	fclose(pf);
}

void Version()
{
	puts("*************************");
	puts("班级信息管理系统V2.0");
}

int Menu()
{
	system("cls");
	char mode = 0;
	Version();
	puts("1.浏览数据");
	puts("2.分析数据");
	puts("3.添加数据");
	puts("4.查找数据");
	puts("5.修改数据");
	puts("6.删除数据");
	puts("0.退出程序");
	puts("***更多功能正在开发中***");
	puts("*************************");
	mode = getch();
	switch(mode)
	{
	case '1':
		Browse();
		break;
	case '2':
		DataAnalyse();		
		break;
	case '3':
		Insert();		
		break;
	case '4':
		Search();		
		break;
	case '5':
		Modify();		
		break;
	case '6':
		Delete();
		break;
	default:
		break;
	}
	return mode;
}

void Browse()
{
	system("cls");
	char Bmode = 0;
	Version();
	puts("1.按姓名排序");
	puts("2.按学号排序");
	puts("3.按数学成绩排序");
	puts("4.按指定条件筛选数据");
	puts("0.退回主菜单");
	puts("请选择：");
	Bmode = getch();
	switch(Bmode)
	{
	case '1':
		SortByName();
		system("pause");
		break;
	case '2':
		SortByNumb();
		system("pause");
		break;
	case '3':
		SortByMath();
		system("pause");
		break;
	case '4':
		Condition();
		break;
	case '0':
		return;
		break;
	default:	
		puts("输入有误！");
		system("pause");
		return;
	}
}

void DataAnalyse()
{
	//数据最高分、最低分
	//全体数据平均分
	//数据及格率
	//数据 优、良、中、差
	system("cls");
	int i=0,Gross;
	float sum = 0,ok = 0,good=0,well=0,mid=0,bad=0;
	SSTU t;
	Gross = AllData();
	Version();
	puts("*********************************\n");
	printf("目前共有 %d 个学生的数据\n",Gross);
	while(i<COUNT)
	{
		if(g_stud[i].fMath > t.fMath)
			t = g_stud[i];
		++i;
	}
	printf("\n所有数据的最高分是 %s 同学，数学成绩为 %.1f \n\n",t.sName,t.fMath);
	
	i=0;
	while(i<COUNT)
	{
		if(g_stud[i].fMath < t.fMath  && g_stud[i].nNumb >0 )
			t = g_stud[i];
		++i;
	}
	printf("所有数据的最低分是 %s 同学，数学成绩为 %.1f \n\n",t.sName,t.fMath);
	
	i=0;
	while(i < COUNT)
	{
		if( g_stud[i].nNumb >0 )
			sum += g_stud[i].fMath;
		++i;
	}
	printf("所有数据的平均分为%.2f\n\n",sum/Gross);
	
	i=0;
	while(i<COUNT)
	{
		if(g_stud[i].fMath >= 60.0)
			++ok;
		++i;
	}
	printf("所有数据的 及格率 为%.2f%%\n\n",ok/Gross*100);
	
	i=0;
	while(i<COUNT)
	{
		if(g_stud[i].fMath >= 85.0)
			++good;
		++i;
	}
	printf("所有数据的优秀 (大于85分) 率为%.2f%%\n\n",good/Gross*100);
	
	i=0;
	while(i<COUNT)
	{
		if(g_stud[i].fMath >= 75.0  &&  g_stud[i].fMath < 85.0)
			++well;
		++i;
	}
	printf("所有数据的良好 (75~85分) 率为%.2f%%\n\n",well/Gross*100);
	
	i=0;
	while(i<COUNT)
	{
		if(g_stud[i].fMath >= 60.0  &&  g_stud[i].fMath < 75.0)
			++mid;
		++i;
	}
	printf("所有数据的中等 (60~75分) 率为%.2f%%\n\n",mid/Gross*100);
	
	i=0;
	while(i<COUNT)
	{
		if(g_stud[i].fMath < 60.0  && g_stud[i].nNumb > 0)
			++bad;
		++i;
	}
	printf("所有数据的 差 (小于60分) 率为%.2f%%\n\n",bad/Gross*100);
	
	puts("*********************************\n");
	system("pause");
}

void Condition()
{
	Version();
	float a=0.0,b=0.0;
	int i=0,gross=0;
	system("cls");
	puts("****************");
	puts("按分数段筛选数据");
	printf("请输入分数段【空格间隔】:");
	scanf("%f %f",&a,&b);
	if(a>b)
	{
		puts("分数段输入有误！");
		system("pause");
		return;
	}
	AutoSort();
	printf("\n学号\t姓名\t成绩\n");
	while(i<COUNT)
	{
		if(g_stud[i].nNumb >0  &&  g_stud[i].fMath >= a  &&  g_stud[i].fMath <= b)
		{
			printf("%d\t%s\t%.1f\n",g_stud[i].nNumb,g_stud[i].sName,g_stud[i].fMath);
			gross++;
		}
		++i;
	}
	printf("\n分数段筛选：从%.1f分到%.1f分共有%d人\n\n\n",a,b,gross);
	system("pause");
}

void AutoSort()	
{
	int i=0,j=0,nCOUNT=0;
	while(g_stud[nCOUNT].nNumb  &&  nCOUNT < COUNT)
		nCOUNT++;
	while(i<nCOUNT-1)
	{
		j=0;
		while(j<nCOUNT-1-i)
		{
			if( g_stud[j].nNumb  >  g_stud[j+1].nNumb )
			{
				SSTU t	      =      g_stud[j];
				g_stud[j]     =      g_stud[j+1];
				g_stud[j+1]   =      t;
			}
			j++;
		}
		i++;
	}	
}

void SortByName()
{
	int Gross = 0 , j = 0;
	std::vector<SSTU> list;
	while(j < 100)
	{
		if(g_stud[j].nNumb)
			list.push_back(g_stud[j]);
		++j;
	}
	std::sort(list.begin(),list.end(),Compare);
/*	int i=0,j=0,nCOUNT=0;
	while(g_stud[nCOUNT].nNumb  &&  nCOUNT < COUNT)
		nCOUNT++;
	while(i<nCOUNT-1)
	{
		j=0;
		while(j<nCOUNT-1-i)
		{
			if(strcmp(g_stud[j].sName,g_stud[j+1].sName) > 0)
			{
				SSTU t      =    g_stud[j];
				g_stud[j]   =    g_stud[j+1];
				g_stud[j+1] =    t;
			}
			j++;
		}
		i++;
	}*/
	printf("学号\t姓名\t成绩\n");
	for(int i = 0; i < list.size() ;++i)
		printf("%d\t%s\t%.1f\n",list[i].nNumb,list[i].sName,list[i].fMath);
	list.clear();
}

bool Compare(SSTU& s1, SSTU& s2)
{
	return strcmp(s1.sName , s2.sName) < 0;
}

void SortByNumb()
{
	int i=0,j=0,nCOUNT=0;
	while(g_stud[nCOUNT].nNumb  &&  nCOUNT < COUNT)
		nCOUNT++;
	while(i<nCOUNT-1)
	{
		j=0;
		while(j<nCOUNT-1-i)
		{
			if( g_stud[j].nNumb  >  g_stud[j+1].nNumb )
			{
				SSTU t	      =      g_stud[j];
				g_stud[j]     =      g_stud[j+1];
				g_stud[j+1]   =      t;
			}
			j++;
		}
		i++;
	}
	Print();
}


void SortByMath()
{
	int i=0,j=0,nCOUNT=0;
	while(g_stud[nCOUNT].nNumb  &&  nCOUNT < COUNT)
		nCOUNT++;
	while(i<nCOUNT-1)
	{
		j=0;
		while(j<nCOUNT-1-i)
		{
			if( g_stud[j].fMath  <  g_stud[j+1].fMath )
			{
				SSTU t	      =      g_stud[j];
				g_stud[j]     =      g_stud[j+1];
				g_stud[j+1]   =      t;
			}
			j++;
		}
		i++;
	}
	Print();
}


void Print()
{
	system("cls");
	Version();
	int i=0,Gross;
	Gross = AllData();
	printf("目前共有 %d 个学生的数据\n",Gross);
	printf("学号\t姓名\t成绩\n");
	while(i < COUNT)
	{
		if(g_stud[i].nNumb >0)
			printf("%d\t%s\t%.1f\n",g_stud[i].nNumb,g_stud[i].sName,g_stud[i].fMath);
		++i;
	}
}


void Insert()
{
	int i=0,n=0,ls;
	char mode = 0;
	do{
		system("cls");
		Version();
		i=0,n=0;
		while(g_stud[i].nNumb > 0  &&  i<COUNT)
			++i;
		if(i == COUNT)
		{
			printf("\n数据已满，如需扩充请联系管理员！");
			system("pause");
			return;
		}
		printf("\n请 输 入 学 号：");
		scanf("%d",&ls);
		if( ls == 0)
			return;
		while(n<COUNT)
		{
			if(g_stud[n].nNumb == ls)
			{
				puts("此学号已存在！");
				system("pause");
				return;
			}
			++n;
		}
		g_stud[i].nNumb = ls;
		printf("请 输 入 姓 名：");
		scanf("%s",g_stud[i].sName);
		printf("请输入数学成绩：");
		scanf("%f",&g_stud[i].fMath);
		system("cls");
		SortByNumb();
		Save();
		printf("\n\n录入成功，是否继续录入数据？【按Y继续录入】：");
		mode = getch();
	}while( mode == 'y' || mode =='Y' );
}

int  AllData()
{
	int i=0,sum=0;
	while(i < COUNT)
	{
		if( g_stud[i].nNumb > 0 )
			++sum;
		++i;
	}
	return sum;
}


void Search()
{
	system("cls");
	Version();
	char Smode = 0;
	puts("*****************");
	puts("1.输入学号查找");
	puts("2.输入姓名查找");
	puts("0.退回主菜单");
	printf("请选择：");
	Smode = getch();
	switch(Smode)
	{
	case '1':
		SearchNumb();
		break;
	case '2':
		SearchName();
		break;
	case '0':
		return;
	}
}

void SearchNumb()
{
	system("cls");
	Version();
	int i=0,SNumb;
	printf("请输入要查找的同学学号：");
	scanf("%d",&SNumb);
	if( SNumb == 0)
		return;
	while(i<COUNT)
	{
		if(SNumb == g_stud[i].nNumb)
			break;
		++i;
	}
	printf("\n%s同学，学号为%d，数学成绩为%.1f\n",g_stud[i].sName,g_stud[i].nNumb,g_stud[i].fMath);
	system("pause");
}

void SearchName()
{
	system("cls");
	Version();
	int i=0;
	char SName[20];
	printf("请输入要查找的同学姓名：");
	scanf("%s",SName);
	while(i<COUNT)
	{
		if( strcmp(g_stud[i].sName,SName) == 0 )
			break;
		++i;
	}
	printf("\n%s同学，学号为%d，数学成绩为%.1f\n",g_stud[i].sName,g_stud[i].nNumb,g_stud[i].fMath);
	system("pause");
}

void Modify()
{
	system("cls");
	Version();
	char Mmode = 0;
	puts("*****************");
	puts("1.输入学号查找并修改");
	puts("2.输入姓名查找并修改");
	puts("0.退回主菜单");
	printf("请选择：");
	Mmode = getch();
	switch(Mmode)
	{
	case '1':
		ModifyNumb();
		break;
	case '2':
		ModifyName();
		break;
	case '0':
		return;
	}
}

void ModifyNumb()
{
	system("cls");
	Version();
	int i=0,MNumb;
	char Decision,Mmode;
	printf("请输入要修改的同学的原学号：");
	scanf("%d",&MNumb);
	if( MNumb == 0)
		return;
	while(i<COUNT)
	{
		if(MNumb == g_stud[i].nNumb)
			break;
		++i;
	}
	if(i == COUNT)
	{
		puts("未找到这条数据！");
		system("pause");
		return;
	}
	printf("\n%s同学，学号为%d，数学成绩为%.1f\n确定要修改此条数据吗？【按Y开始修改】",g_stud[i].sName,g_stud[i].nNumb,g_stud[i].fMath);
	Decision = getch();
	if(Decision == 'y' || Decision == 'Y')
	{
		puts("\n**************");
		puts("1.学号修改");
		puts("2.姓名修改");
		puts("3.数学成绩修改");
		puts("0.取消修改");
		Mmode = getch();
		switch(Mmode)
		{
		case '1':
			{
				printf("请输入修改后的学号：");
				scanf("%d",&g_stud[i].nNumb);
				Save();
				puts("\n**************");
				printf("\n修改成功！");
				printf("\n修改后：%s同学，学号为%d，数学成绩为%.1f\n",g_stud[i].sName,g_stud[i].nNumb,g_stud[i].fMath);
				system("pause");
				return;
			}
			break;
		case '2':
			{
				printf("请输入修改后的姓名：");
				scanf("%s",g_stud[i].sName);
				Save();
				puts("\n**************");
				printf("\n修改成功！");
				printf("\n修改后：%s同学，学号为%d，数学成绩为%.1f\n",g_stud[i].sName,g_stud[i].nNumb,g_stud[i].fMath);
				system("pause");
				return;
			}
			break;
		case '3':
			{
				printf("请输入修改后的数学成绩：");
				scanf("%f",&g_stud[i].fMath);
				Save();
				puts("\n**************");
				printf("\n修改成功！");
				printf("\n修改后：%s同学，学号为%d，数学成绩为%.1f\n",g_stud[i].sName,g_stud[i].nNumb,g_stud[i].fMath);
				system("pause");
				return;
			}
			break;
		case '0':
			return;
			break;
		default:
			return;
			break;
		}
	}
	system("pause");		
}

void ModifyName()
{
	system("cls");
	Version();
	int i=0;
	char Decision,Mmode,MName[20];
	printf("请输入要修改的同学的原姓名：");
	scanf("%s",&MName);
	while(i<COUNT)
	{
		if(  strcmp(g_stud[i].sName , MName)==0  )
			break;
		++i;
	}
	if(i == COUNT)
	{
		puts("未找到这条数据！");
		system("pause");
		return;
	}
	printf("\n%s同学，学号为%d，数学成绩为%.1f\n确定要修改此条数据吗？【按Y开始修改】",g_stud[i].sName,g_stud[i].nNumb,g_stud[i].fMath);
	Decision = getch();
	if(Decision == 'y' || Decision == 'Y')
	{
		puts("\n**************");
		puts("1.学号修改");
		puts("2.姓名修改");
		puts("3.数学成绩修改");
		puts("0.取消修改");
		Mmode = getch();
		switch(Mmode)
		{
		case '1':
			{
				printf("请输入修改后的学号：");
				scanf("%d",&g_stud[i].nNumb);
				Save();
				puts("\n**************");
				printf("\n修改成功！");
				printf("\n修改后：%s同学，学号为%d，数学成绩为%.1f\n",g_stud[i].sName,g_stud[i].nNumb,g_stud[i].fMath);
				system("pause");
				return;
			}
			break;
		case '2':
			{
				printf("请输入修改后的姓名：");
				scanf("%s",g_stud[i].sName);
				Save();
				puts("\n**************");
				printf("\n修改成功！");
				printf("\n修改后：%s同学，学号为%d，数学成绩为%.1f\n",g_stud[i].sName,g_stud[i].nNumb,g_stud[i].fMath);
				system("pause");
				return;
			}
			break;
		case '3':
			{
				printf("请输入修改后的数学成绩：");
				scanf("%f",&g_stud[i].fMath);
				Save();
				puts("\n**************");
				printf("\n修改成功！");
				printf("\n修改后：%s同学，学号为%d，数学成绩为%.1f\n",g_stud[i].sName,g_stud[i].nNumb,g_stud[i].fMath);
				system("pause");
				return;
			}
			break;
		case '0':
			return;
			break;
		default:
			return;
			break;
		}
	}
	system("pause");	
}

void Delete()
{
	system("cls");
	Version();
	char Dmode = 0;
	puts("*****************");
	puts("1.输入学号删除");
	puts("2.输入姓名删除");
	puts("3.清空全部数据(管理员)");
	puts("0.退回主菜单");
	printf("请选择：");
	Dmode = getch();
	switch(Dmode)
	{
	case '1':
		DeleteNumb();
		break;
	case '2':
		DeleteName();
		break;
	case '3':
		DeleteAll();
		break;
	case '0':
		return;
	}
}
void DeleteNumb()
{
	system("cls");
	Version();
	int i=0,DNumb;
	char Decision;
	printf("请输入要删除的同学学号：");
	scanf("%d",&DNumb);
	if( DNumb == 0)
		return;
	while(i < COUNT)
	{
		if(g_stud[i].nNumb != DNumb)
			++i;
		else
			break;
	}
	if(i == COUNT)
	{
		puts("未找到此学号！");
		system("pause");
		return;
	}
	printf("确定要删除学号为%d，%s的信息？【按Y删除】\n",g_stud[i].nNumb,g_stud[i].sName);
	Decision = getch();
	if(Decision == 'y' || Decision == 'Y')
	{
		g_stud[i].nNumb = -1;
		Save();
		puts("\n删除成功！\n");
		system("pause");
	}
	else
	{
		puts("\n删除取消！\n");
		system("pause");
		return;
	}
}

void DeleteName()
{
	system("cls");
	Version();
	int i=0;
	char DName[20];
	char Decision;
	printf("请输入要删除的同学姓名：");
	scanf("%s",DName);
	while(i < COUNT)
	{
		if(  strcmp(g_stud[i].sName,DName)  )
			++i;
		else
			break;
	}
	if(i == COUNT)
	{
		puts("未找到此姓名！");
		system("pause");
		return;
	}
	printf("确定要删除学号为%d，%s的信息？【按Y删除】\n",g_stud[i].nNumb,g_stud[i].sName);
	Decision = getch();
	if(Decision == 'y' || Decision == 'Y')
	{
		g_stud[i].nNumb = -1;
		Save();
		puts("\n删除成功！\n");
		system("pause");
	}
	else
	{
		puts("\n删除取消！\n");
		system("pause");
		return;
	}
}

void DeleteAll()
{
	system("cls");
	Version();
	puts("\n警告：你选择了清空全部数据，请谨慎使用此功能！");
	char password[32],Decision;
	printf("\n请输入程序密码：");
	scanf("%s",password);
	if( strcmp( password , "Arsenal2" ) == 0 )
	{
		puts("\n确认清空全部数据吗？【按Y确认】");
		Decision = getch();
		if(Decision == 'y'  ||  Decision == 'Y')
		{
			memset(g_stud,0,sizeof(g_stud));
			Save();
			puts("数据已被全部清空！");
			system("pause");
			return;
		}
		else
		{
			puts("取消清空！");
			system("pause");
			return;
		}
	}
	else
	{
		puts("密码错误！");
		system("pause");
		return;
	}
}

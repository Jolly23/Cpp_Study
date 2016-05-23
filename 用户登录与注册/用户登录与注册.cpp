#include "stdafx.h"
#include <iostream>
#include <process.h>
#include <memory.h>
#include <conio.h>
#include <string.h>
using namespace std;

struct DATA
{
	char sName[20];
	char sUserName[32];
	char sPassW[32];
};

struct SNode
{
	DATA User;
	SNode *pNext;
} *g_pHead = NULL;

void Print(DATA *u1);
void Menu();
void LogIn();
void SignIn();
void ClosingAC();
void OP();
void ExitSW();
bool ChackUserName(char *NewUserName);
void Save();
void Load();
void Insert(DATA IN);

void main()
{
	Load();
	do{
		Menu();
	}while(true);
}

void Save()
{
	FILE *fp = fopen("SQL.lqm","w");
	
	SNode *p = g_pHead;
	
	while(p)
	{
		fwrite(&p ->User,1,sizeof(DATA),fp);
		p = p ->pNext;
	}
	
	fclose(fp);
}

void Load()
{
	DATA LoadData;
	FILE *fp = fopen("SQL.lqm","a+");
	
	while(	fread(&LoadData,1,sizeof(DATA),fp) > 0	)
		Insert(LoadData);
	
	fclose(fp);
}

void Insert(DATA IN)
{
	SNode *pNew = new SNode;
	pNew ->User = IN;
	pNew ->pNext = g_pHead;
	g_pHead = NULL;
}

void Menu()
{
	char cSel;
	cout << "******************" <<endl;
	cout << "1. 用户登录" <<endl;
	cout << "2. 用户注册" <<endl;
	cout << "3. 用户销户" <<endl;
	cout << "4.  管理员 " <<endl;
	cout << "5.   退出  " <<endl;
	cout << "******************" <<endl;
	cSel = getch();
	switch(cSel)
	{
	case '1':
		LogIn();
		break;
	case '2':
		SignIn();
		break;
	case '3':
		ClosingAC();
		break;
	case '4':
		OP();
		break;
	case '5':
		ExitSW();
		Save();
		break;
	}
}


void LogIn()
{
	
}

void SignIn()
{
	DATA NewAC;
	memset(&NewAC,0,sizeof(DATA));
	int i = 0 ,times = 0;
	char PassW[32] = {NULL}, PassD[32] = {NULL};
	
	printf("请输入用户名：");
	scanf("%s",NewAC.sUserName);
	bool bRes = ChackUserName(NewAC.sUserName);
	
	printf("请设置密码：");
	while((PassW[i] = getch()) != '\r') 
	{
		if(i < 31)
		{
			printf("*");
			++i;
		}
		else
			break;
	}
	PassW[i] = '\0' ;
	puts("");
	printf("请再输入一次:");
	i = 0;
	while((PassW[i] = getch()) != '\r')
	{
		if(i < 31)
		{
			printf("*");
			++i;
		}
		else
			break;
	}
	PassD[i] = '\0' ;
	puts("");

	if(strcmp(PassW, PassD) == 0)
	{
		strcpy(NewAC.sPassW, PassW);
		puts("设置完成！");
	}
	Insert(NewAC);
}

bool ChackUserName(char *NewUserName)
{
	return true;
}

void ExitSW()
{

}

void OP()
{

}

void ClosingAC()
{
	
}
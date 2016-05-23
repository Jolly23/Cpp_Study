// 项目：银行后台与ATM.cpp : Defines the entry point for the console application.
//

/*
2015年7月20日：
项目规划：实现1000人的账户管理，
个人信息包括（姓名、性别、卡号、密码、存款等），
实现银行ATM					:用户账户模拟取款、模拟存款、卡对卡转账、挂失、（利息计算）
银行管理员对账户管理（加密）:冻结账户，资产管理排序
*/

/*
2015年8月9日：项目开始编写；
*/

#include "stdafx.h"
#include <stdio.h>
#include <process.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

enum
{
	Normal = 50001,
		ReportLoss,
		AccountFrozen,
};

enum
{
	Female = 70001,
		Male,
};

struct USER
{
	int		nAccountNum;		//账号
	char	cPassword[7];		//密码
	char	sName[20];			//户主姓名
	double	lfMoney;			//账户余额（RMB）
	double  lfInterest;			//利息计算
	int		cSex;				//户主性别			enum编码：女   = 70001，男   = 70002
	int		cSafety;			//安全信息			enum编码：正常 = 50001，挂失 = 50002， 冻结 = 50003
	char	IDCard[19];			//身份证号
};

struct SNode
{
	USER  data;
	SNode *pNext;
} *g_pHead = NULL;


void Load()								;
void Save()								;
void MenuRoot()							;
void SWVersion()						;
void MenuManage()						;
void MenuATM(SNode *p)					;
void MenuATMDispose(char cSel,SNode *p)	;	
void MenuRootDispose(char cSel)			;
void CreateAccount()					;
char* NewACPassWSetting()				;
void ExitSW()							;
void CreateAccountDispose(USER NewAC)	;
void Print()							;
void Signin()							;
double Balance(SNode *p)						;
void CheckBalance(SNode *p)						;
void SaveMoney(SNode *p)				;
void DrawMoney(SNode *p)				;
void DrawMoneyDispose(double DM, SNode *p)	;
void TransferMoney(SNode *p)				;
SNode* CheckACNumb(int ACNumb)					;




void main()
{
	Load();
	while(1)
		MenuRoot();
}


void Print()
{
	if(g_pHead == NULL)
		return;
	int i = 1;
	SNode *p = g_pHead;
	
	while(p)
	{
		printf("用户%d:\n",i++);
		printf("******************************\n");
		printf("姓    名:  %s\n",p->data.sName);
		if(p->data.cSex == Male)
			printf("性    别:  男\n");
		else
			printf("性    别:  女\n");
		printf("身份证号:  %s\n",p->data.IDCard);
		printf("账    号:  %d\n",p->data.nAccountNum);
		printf("密    码:  %s\n",p->data.cPassword);
		printf("余    额:  %.2lf\n",p->data.lfMoney);
		printf("利    息:  %.2lf\n",p->data.lfInterest);
		printf("******************************\n\n");
		
		p = p->pNext;
	}
}


void SWVersion()
{
	puts("***********************");
	puts("*赵磊银行管理系统CODE*");
	puts("***********************");
}

void Load()
{
	FILE *fp = fopen("SQL.lqm","a+");
	USER DATA;
	while( fread(&DATA,1,sizeof(USER),fp) > 0 )
		CreateAccountDispose(DATA);
	fclose(fp);
}

void Save()
{
	FILE *fp = fopen("SQL.lqm","w");
	SNode *p = g_pHead;
	while(p)
	{
		fwrite(&p->data,1,sizeof(USER),fp);
		p = p->pNext;
	}
	
	fclose(fp);
}

void MenuRoot()
{
	system("cls");
	SWVersion();
	char cSel;
	puts("1.银行账户管理");
	puts("");
	puts("2.  ATM系统");
	puts("");
	puts("3.   开 户");
	puts("");
	puts("0.  退出程序");
	cSel = getch();
	if(cSel >= '0'  &&  cSel <= '3')
		MenuRootDispose(cSel);
	else
		return;
}

void MenuRootDispose(char cSel)
{
	switch(cSel)
	{
	case '0':
		ExitSW();
		break;
	case '1':
		MenuManage();
		break;
	case '2':
		Signin();
		break;
	case '3':
		CreateAccount();
		break;
	}
}

void MenuManage()			
{
	//查看银行用户信息、修改信息、冻结挂失账户、
	system("cls");
	Print();
	system("pause");
	
}

void MenuATM(SNode *p)				
{
	//查询余额、修改密码、存钱、取钱、转账、挂失、开户、（利息）
	system("cls");
	SWVersion();
	char cSel;
	char sTime[10];
	int nTime;
	_strtime(sTime);
	sTime[2] = NULL;
	nTime = atoi(sTime);
	
	if(nTime > 5  &&  nTime < 11)
		printf(" 上午好，");
	if(nTime >= 11  &&  nTime < 14)
		printf(" 中午好，");
	if(nTime >= 14  &&  nTime < 19)
		printf(" 下午好，");
	if(nTime >= 19  &&  nTime < 6)
		printf(" 晚上好，");
	printf("%s ",p->data.sName);
	if(p->data.cSex == Female)
		puts("女士");
	else
		puts("先生");
	puts("***********************");
	puts("1. 查询余额 ");
	puts("2. 存入现金 ");
	puts("3. 取出现金 ");
	puts("4.卡对卡转账");
	puts("5. 修改密码 ");
	puts("6.   挂 失  ");
	puts("0.退卡并返回根菜单");
	cSel = getch();
	if(cSel >= '0'  &&  cSel <= '6')
		MenuATMDispose(cSel,p);
	else
	{
		puts("您输入的选项有误");
		system("pause");
		MenuATM(p);
	}
}

void MenuATMDispose(char cSel,SNode *p)
{
	switch(cSel)
	{
	case '0':
		return;
		break;
	case '1':
		CheckBalance(p);
		MenuATM(p);
		break;
	case '2':
		SaveMoney(p);
		MenuATM(p);
		break;
	case '3':
		DrawMoney(p);
		MenuATM(p);
		break;
	case '4':
		TransferMoney(p);
		MenuATM(p);
		break;
	case '5':

		MenuATM(p);
		break;
	case '6':

		MenuATM(p);
		break;
	}
}

void Signin()
{
	int ACNumb , i = 0 ,times = 0;
	char PassW[7];
	
	system("cls");
	printf("请刷卡或输入账号：");
	scanf("%d",&ACNumb);

	SNode *p = CheckACNumb(ACNumb);
	
	if(!p)
		{
			puts("不识别该卡 或 无此账户");
			system("pause");
			return;
		}
		
	do{
		i = 0;
		if(times == 0)
			printf("请输入密码:");
		else	
		{
			printf("\n密码输入错误，您还有 %d 次机会\n",3-times);
			printf("请输入密码：");
		}

		memset(PassW,0,sizeof(PassW));

		while(i<6)
		{
			PassW[i] = getch();
			printf("*");
			++i;
		}
		PassW[i] = '\0' ;
		
		times++;
	}while(strcmp(PassW,p->data.cPassword)  &&  times < 3);

	if(strcmp(PassW,p->data.cPassword) == 0)
			MenuATM(p);

	if(times == 3)
	{
		puts("\n输入错误次数太多，登录失败！");
		system("pause");
		return;
	}
}

SNode* CheckACNumb(int ACNumb)
{
	SNode *p = g_pHead;

	while(p)
	{
		if(p->data.nAccountNum == ACNumb)
			return p;

		p = p->pNext;
	}

	return NULL;
}

void CheckBalance(SNode *p)
{
	system("cls");
	printf("你卡号为 %d 的银行卡余额： %.2lf \n",p->data.nAccountNum, Balance(p));
	system("pause");
}

double Balance(SNode *p)
{
	return p->data.lfMoney;
}

void SaveMoney(SNode *p)
{
	double Cash;
	system("cls");
	printf("请输入存入数额：");
	scanf("%lf",&Cash);
	p->data.lfMoney += Cash;
	Save();
	puts("存入成功！");
	printf("你卡号为 %d 的银行卡余额： %.2lf \n",p->data.nAccountNum, Balance(p));

	system("pause");
}

void DrawMoney(SNode *p)
{
	double Cash;
	char Sel;

	system("cls");
	puts("请选择取款数额：");
	puts("1、100元");
	puts("2、300元");
	puts("3、500元");
	puts("4、1000元");
	puts("5、3000元");
	puts("6、5000元");
	puts("7、输入数额");
	
	Sel = getch();
	switch(Sel)
	{
	case '1':
		DrawMoneyDispose(100.0,p);
		break;
	case '2':
		DrawMoneyDispose(300.0,p);
		break;
	case '3':
		DrawMoneyDispose(500.0,p);
		break;
	case '4':
		DrawMoneyDispose(1000.0,p);
		break;
	case '5':
		DrawMoneyDispose(3000.0,p);
		break;
	case '6':
		DrawMoneyDispose(5000.0,p);
		break;
	case '7':
		printf("请输入要取出的金额：");
		scanf("%lf",&Cash);
		DrawMoneyDispose(Cash,p);
		break;

	}
}

void DrawMoneyDispose(double DM, SNode *p)
{
	if(p->data.lfMoney < DM)
	{
		printf("余额不足 %.2lf 元，无法取现。",DM);
		printf("你卡号为 %d 的银行卡余额： %.2lf \n",p->data.nAccountNum, Balance(p));
		system("pause");
		MenuATM(p);
	}

	p->data.lfMoney -= DM;
	Save();
	puts("取现成功！");
	printf("你卡号为 %d 的银行卡余额： %.2lf \n",p->data.nAccountNum, Balance(p));
	
	system("pause");
	MenuATM(p);
}

void TransferMoney(SNode *p)
{
	int ACNumb;
	double TM;
	system("cls");
	printf("请输入你要转向的的卡号：");
	scanf("%d",&ACNumb);

	SNode *pTo = CheckACNumb(ACNumb);
	
	if(!pTo)
	{
		puts("本行不存在此账户，请查正后再转账");
		system("pause");
		MenuATM(p);
		return;
	}

	printf("请输入转账金额：");
	scanf("%lf",&TM);
	
	if(p->data.lfMoney < TM)
	{
		printf("余额不足 %.2lf 元，无法转账。",TM);
		printf("你卡号为 %d 的银行卡余额： %.2lf \n",p->data.nAccountNum, Balance(p));
		system("pause");
		MenuATM(p);
		return;
	}

	p->data.lfMoney   -= TM;
	pTo->data.lfMoney += TM;
	Save();

	printf("转账成功！%s",pTo->data.sName);
	if(pTo->data.cSex == Female)
		printf(" 女士");
	else
		printf(" 先生");
	printf("已收到您 %.2lf 元的转账！\n",TM);
	printf("你卡号为 %d 的银行卡余额： %.2lf \n",p->data.nAccountNum, Balance(p));
	system("pause");
	MenuATM(p);
	return;
}

void CreateAccount()
{
	system("cls");
	USER NewAC;
	char PassW[7] = {NULL};
	char PassD[7] = {NULL};
	int i = 0, j = 0 , times = 0, k = 0, ACNumb = 1001;
	printf("请输入您的姓名：");
	scanf("%s",NewAC.sName);
	printf("\n请输入您的身份证号：");
	while(k < 18)
	{
		NewAC.IDCard[k] = getch();
		printf("%c",NewAC.IDCard[k]);
		++k;
	}
	NewAC.IDCard[k] = '\0' ;
	if(NewAC.IDCard[17] % 2 == 1)
		NewAC.cSex = Male;
	else
		NewAC.cSex = Female;
	
	do{
		i = 0, j = 0 ;
		
		if(times > 0)
		{
			system("cls");
			puts("两次输入的密码不相同，请重新输入！");
		}
		
		printf("\n请设定一个密码[6位数字]：");
		while(i<6)
		{
			NewAC.cPassword[i] = getch();
			printf("*");
			++i;
		}
		NewAC.cPassword[i] = '\0' ;
		printf("\n请再输入一次：");
		while(j<6)
		{
			PassD[j] = getch();
			printf("*");
			++j;
		}
		PassD[j] = '\0' ;
		
		if(strcmp(NewAC.cPassword,PassD))
			memset(NewAC.cPassword,0,sizeof(NewAC.cPassword));
		
		++times;
		
	}while(times < 3  &&  strcmp(NewAC.cPassword,PassD) != 0);
	
	if(strcmp(NewAC.cPassword,PassD) != 0)
	{
		system("cls");
		puts("多次输入错误，创建账户失败！");
		system("pause");
		return;
	}
	
	NewAC.lfMoney = 0.0;
	
	SNode *p = g_pHead;
	while(p)
	{
		ACNumb++;
		p = p->pNext;
	}
	NewAC.lfInterest  = 0.0;
	NewAC.nAccountNum = ACNumb;
	NewAC.cSafety = Normal;
	
	CreateAccountDispose(NewAC);
	Save();
	puts("开户成功！请牢记您的银行卡信息");
	printf("账号：%d\n",NewAC.nAccountNum);
	printf("密码：%s\n",NewAC.cPassword);
	system("pause");
}

void CreateAccountDispose(USER NewAC)
{
	SNode *pNew = (SNode*)malloc(sizeof(SNode));
	pNew->data = NewAC;
	pNew->pNext = g_pHead;
	g_pHead = pNew;
}


void ExitSW()	
{
	system("cls");
	puts("感谢使用，再见！");
	system("pause");
	exit(1);
}
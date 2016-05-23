// ��Ŀ�����к�̨��ATM.cpp : Defines the entry point for the console application.
//

/*
2015��7��20�գ�
��Ŀ�滮��ʵ��1000�˵��˻�����
������Ϣ�������������Ա𡢿��š����롢���ȣ���
ʵ������ATM					:�û��˻�ģ��ȡ�ģ������Կ�ת�ˡ���ʧ������Ϣ���㣩
���й���Ա���˻��������ܣ�:�����˻����ʲ���������
*/

/*
2015��8��9�գ���Ŀ��ʼ��д��
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
	int		nAccountNum;		//�˺�
	char	cPassword[7];		//����
	char	sName[20];			//��������
	double	lfMoney;			//�˻���RMB��
	double  lfInterest;			//��Ϣ����
	int		cSex;				//�����Ա�			enum���룺Ů   = 70001����   = 70002
	int		cSafety;			//��ȫ��Ϣ			enum���룺���� = 50001����ʧ = 50002�� ���� = 50003
	char	IDCard[19];			//���֤��
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
		printf("�û�%d:\n",i++);
		printf("******************************\n");
		printf("��    ��:  %s\n",p->data.sName);
		if(p->data.cSex == Male)
			printf("��    ��:  ��\n");
		else
			printf("��    ��:  Ů\n");
		printf("���֤��:  %s\n",p->data.IDCard);
		printf("��    ��:  %d\n",p->data.nAccountNum);
		printf("��    ��:  %s\n",p->data.cPassword);
		printf("��    ��:  %.2lf\n",p->data.lfMoney);
		printf("��    Ϣ:  %.2lf\n",p->data.lfInterest);
		printf("******************************\n\n");
		
		p = p->pNext;
	}
}


void SWVersion()
{
	puts("***********************");
	puts("*�������й���ϵͳCODE*");
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
	puts("1.�����˻�����");
	puts("");
	puts("2.  ATMϵͳ");
	puts("");
	puts("3.   �� ��");
	puts("");
	puts("0.  �˳�����");
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
	//�鿴�����û���Ϣ���޸���Ϣ�������ʧ�˻���
	system("cls");
	Print();
	system("pause");
	
}

void MenuATM(SNode *p)				
{
	//��ѯ���޸����롢��Ǯ��ȡǮ��ת�ˡ���ʧ������������Ϣ��
	system("cls");
	SWVersion();
	char cSel;
	char sTime[10];
	int nTime;
	_strtime(sTime);
	sTime[2] = NULL;
	nTime = atoi(sTime);
	
	if(nTime > 5  &&  nTime < 11)
		printf(" ����ã�");
	if(nTime >= 11  &&  nTime < 14)
		printf(" ����ã�");
	if(nTime >= 14  &&  nTime < 19)
		printf(" ����ã�");
	if(nTime >= 19  &&  nTime < 6)
		printf(" ���Ϻã�");
	printf("%s ",p->data.sName);
	if(p->data.cSex == Female)
		puts("Ůʿ");
	else
		puts("����");
	puts("***********************");
	puts("1. ��ѯ��� ");
	puts("2. �����ֽ� ");
	puts("3. ȡ���ֽ� ");
	puts("4.���Կ�ת��");
	puts("5. �޸����� ");
	puts("6.   �� ʧ  ");
	puts("0.�˿������ظ��˵�");
	cSel = getch();
	if(cSel >= '0'  &&  cSel <= '6')
		MenuATMDispose(cSel,p);
	else
	{
		puts("�������ѡ������");
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
	printf("��ˢ���������˺ţ�");
	scanf("%d",&ACNumb);

	SNode *p = CheckACNumb(ACNumb);
	
	if(!p)
		{
			puts("��ʶ��ÿ� �� �޴��˻�");
			system("pause");
			return;
		}
		
	do{
		i = 0;
		if(times == 0)
			printf("����������:");
		else	
		{
			printf("\n����������������� %d �λ���\n",3-times);
			printf("���������룺");
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
		puts("\n����������̫�࣬��¼ʧ�ܣ�");
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
	printf("�㿨��Ϊ %d �����п��� %.2lf \n",p->data.nAccountNum, Balance(p));
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
	printf("������������");
	scanf("%lf",&Cash);
	p->data.lfMoney += Cash;
	Save();
	puts("����ɹ���");
	printf("�㿨��Ϊ %d �����п��� %.2lf \n",p->data.nAccountNum, Balance(p));

	system("pause");
}

void DrawMoney(SNode *p)
{
	double Cash;
	char Sel;

	system("cls");
	puts("��ѡ��ȡ�����");
	puts("1��100Ԫ");
	puts("2��300Ԫ");
	puts("3��500Ԫ");
	puts("4��1000Ԫ");
	puts("5��3000Ԫ");
	puts("6��5000Ԫ");
	puts("7����������");
	
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
		printf("������Ҫȡ���Ľ�");
		scanf("%lf",&Cash);
		DrawMoneyDispose(Cash,p);
		break;

	}
}

void DrawMoneyDispose(double DM, SNode *p)
{
	if(p->data.lfMoney < DM)
	{
		printf("���� %.2lf Ԫ���޷�ȡ�֡�",DM);
		printf("�㿨��Ϊ %d �����п��� %.2lf \n",p->data.nAccountNum, Balance(p));
		system("pause");
		MenuATM(p);
	}

	p->data.lfMoney -= DM;
	Save();
	puts("ȡ�ֳɹ���");
	printf("�㿨��Ϊ %d �����п��� %.2lf \n",p->data.nAccountNum, Balance(p));
	
	system("pause");
	MenuATM(p);
}

void TransferMoney(SNode *p)
{
	int ACNumb;
	double TM;
	system("cls");
	printf("��������Ҫת��ĵĿ��ţ�");
	scanf("%d",&ACNumb);

	SNode *pTo = CheckACNumb(ACNumb);
	
	if(!pTo)
	{
		puts("���в����ڴ��˻������������ת��");
		system("pause");
		MenuATM(p);
		return;
	}

	printf("������ת�˽�");
	scanf("%lf",&TM);
	
	if(p->data.lfMoney < TM)
	{
		printf("���� %.2lf Ԫ���޷�ת�ˡ�",TM);
		printf("�㿨��Ϊ %d �����п��� %.2lf \n",p->data.nAccountNum, Balance(p));
		system("pause");
		MenuATM(p);
		return;
	}

	p->data.lfMoney   -= TM;
	pTo->data.lfMoney += TM;
	Save();

	printf("ת�˳ɹ���%s",pTo->data.sName);
	if(pTo->data.cSex == Female)
		printf(" Ůʿ");
	else
		printf(" ����");
	printf("���յ��� %.2lf Ԫ��ת�ˣ�\n",TM);
	printf("�㿨��Ϊ %d �����п��� %.2lf \n",p->data.nAccountNum, Balance(p));
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
	printf("����������������");
	scanf("%s",NewAC.sName);
	printf("\n�������������֤�ţ�");
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
			puts("������������벻��ͬ�����������룡");
		}
		
		printf("\n���趨һ������[6λ����]��");
		while(i<6)
		{
			NewAC.cPassword[i] = getch();
			printf("*");
			++i;
		}
		NewAC.cPassword[i] = '\0' ;
		printf("\n��������һ�Σ�");
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
		puts("���������󣬴����˻�ʧ�ܣ�");
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
	puts("�����ɹ������μ��������п���Ϣ");
	printf("�˺ţ�%d\n",NewAC.nAccountNum);
	printf("���룺%s\n",NewAC.cPassword);
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
	puts("��лʹ�ã��ټ���");
	system("pause");
	exit(1);
}
// VVVѧ�����ݹ�������.cpp : Defines the entry point for the console application.



//��Ŀ�滮��ʹ������mallocʵ�����ݵ� ��ɾ�Ĳ� ���ܣ��Ż��û�������
//�Ͻ��ڴ�й¶


//2015��7��28�շ��� V1.0��	ʵ�ֻ������ܼ��浵
//2015��7��28��		V1.1��	�Ż����ܣ��򻯴��룬����ͨ�����ַ�ʽ�޸ġ�ɾ������
//2015��8�� 3��		V1.3��	�Ż��������룬ʹ�ûص����������ϴ��븴����

#include "stdafx.h"
#include <stdio.h>
#include <process.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>


struct SSTU
{
	int   nNumb;
	char  sName[20];
	float fMath;
};

struct SNode
{
	SSTU data;
	SNode *pNext;
} *g_pHead = NULL;


void Load()										;		//���ش浵��û�д浵�򴴽���
void Save()										;		//��������
void Version()									;		//��ʾ�汾��
void Menu()										;		//�û��˵�
void MenuDispose(char Select)					;		//�˵�ѡ���
void Print()									;		//��ʾ����
void Insert()									;		//�������
int	 CheckNumb(int ls)							;		//�����������ѧ���Ƿ��ظ�
void InsertDispose(SSTU DATA)					;		//������ݴ���
void SearchMenu()								;		//��������
void ModifyMenu()								;		//�޸�����
void ModifyMenu2(SNode* p)						;		//�޸����ݲ˵����޸���Ŀѡ��
void DeleteMenu()								;		//ɾ������
void SayByeToUser()								;		//�˳�����
SNode* SearchByName()							;		//ͨ����������
SNode* SearchByNumb()							;		//ͨ��ѧ������
void ModifyNumb(SNode* p)						;		//�޸�ѧ��
void ModifyName(SNode* p)						;		//�޸�����
void ModifyMath(SNode* p)						;		//�޸ĳɼ�
SNode* FindByNumbDispose(int SearchNumb)		;		//ͨ��ѧ��������������ֵΪ��ַ
SNode* FindByNameDispose(char SearchName[20])	;		//ͨ������������������ֵΪ��ַ
void DeleteFindByName()							;		//ͨ���������Ҳ�ɾ��
void DeleteFindByNumb()							;		//ͨ��ѧ�Ų��Ҳ�ɾ��
void DeleteAllApprove()							;		//���ȫ������Ա������֤	
int  DeleteAllDispose()							;		//ִ�����ȫ��
void SortByWhat( int (*SortBy) (SNode *p1,SNode *p2) )								;		//ͨ��ѧ������
char BrowseMenu()								;		//������ݲ˵�
int  DATASum()									;		//ͳ����������
void DataAnalyse()								;		//���ݷ���
int SortByNumb(SNode *p1,SNode *p2);
int SortByName(SNode *p1,SNode *p2);
int SortByMath(SNode *p1,SNode *p2);


void main()
{
	Load();
	while(1)	
		Menu();
}

void Load()
{
	FILE *fp = fopen("stud.lqm","a+");
	SSTU DATA;
	while( fread(&DATA,1,sizeof(SSTU),fp) >0 )
		InsertDispose(DATA);
	fclose(fp);
}

void Save()
{
	FILE *fp = fopen("stud.lqm","w");
	SNode *p = g_pHead;
	
	while(p)
	{
		fwrite(&p->data,1,sizeof(SSTU),fp);
		p = p ->pNext;
	}
	
	fclose(fp);
}

void Version()
{
	puts("***************");
	puts("���ݹ����� V1.3");
}

void Menu()
{
	system("cls");
	char Select = 0;
	Version();
	puts("**************");
	puts("**1.�������**");
	puts("**2.���ݷ���**");
	puts("**3.�������**");
	puts("**4.��������**");
	puts("**5.�޸�����**");
	puts("**6.ɾ������**");
	puts("**0.�˳�����**");
	puts("**************");
	
	Select = getch();
	
	if(Select >= '0'  &&  Select <= '6')
		MenuDispose(Select);
	
	else
	{
		puts("��������");
		system("pause");
	}
}

void MenuDispose(char Select)
{
	switch(Select)
	{
	case '1':
		while( BrowseMenu() != '0' );
		break;
	case '2':
		DataAnalyse();
		break;
	case '3':
		Insert();
		break;
	case '4':
		SearchMenu();
		break;
	case '5':
		ModifyMenu();	
		break;
	case '6':
		DeleteMenu();	
		break;
	case '0':
		SayByeToUser();
	}
}

void DataAnalyse()
{
	//������߷֡���ͷ�
	//ȫ������ƽ����
	//���ݼ�����
	//���� �š������С���
	int SumNumberOfData = DATASum();
	
	if(!SumNumberOfData)
	{
		puts("�����ݣ�");
		system("pause");
		return;
	}

	float SumMath = 0.0;
	int   Qualified = 0;
	int   Good = 0, Well = 0, Mid = 0, Bad = 0;

	system("cls");
	printf("Ŀǰ���� %d ������\n",SumNumberOfData);

	SNode *p = g_pHead, *pMax = g_pHead, *pMin = g_pHead;

	while(p)
	{
		if(p->data.fMath > pMax->data.fMath)
			pMax = p;
		if(p->data.fMath < pMin->data.fMath)
			pMin = p;

		SumMath += p->data.fMath;

		if(p->data.fMath >= 60.0)
			Qualified++;

		if(p->data.fMath >= 85.0)
			Good++;
		if(p->data.fMath >= 75.0  &&  p->data.fMath < 85.0)
			Well++;
		if(p->data.fMath >= 60.0  &&  p->data.fMath < 75.0)
			Mid++;
		if(p->data.fMath < 60.0)
			Bad++;

		p = p->pNext;
	}

	printf("������ߣ�ѧ��Ϊ %4d��������%4s������Ϊ%.1f\n",pMax->data.nNumb,pMax->data.sName,pMax->data.fMath);
	printf("������ͣ�ѧ��Ϊ %4d��������%4s������Ϊ%.1f\n\n",pMin->data.nNumb,pMin->data.sName,pMin->data.fMath);
	printf("��������  ƽ����Ϊ %.2f \n\n",SumMath/SumNumberOfData);
	printf("��������  ������Ϊ %.2f%%\n\n",(float)Qualified/(float)SumNumberOfData*100);
	printf("��������  ����<����85��>��Ϊ %.2f%%\n",(float)Good/(float)SumNumberOfData*100);
	printf("��������  ���� <75~85��>��Ϊ %.2f%%\n",(float)Well/(float)SumNumberOfData*100);
	printf("��������  �е� <60~85��>��Ϊ %.2f%%\n",(float)Mid/(float)SumNumberOfData*100);
	printf("��������   �� <����60��>��Ϊ %.2f%%\n\n",(float)Bad/(float)SumNumberOfData*100);


	system("pause");
}


char BrowseMenu()
{
	char Sel;
	system("cls");
	puts("***�������***");
	puts("**************");
	puts("*1.��ѧ������*");
	puts("*2.����������*");
	puts("*3.���ɼ�����*");
	puts("*0.�������˵�*");

	Sel = getch();
	
	switch(Sel)
	{
	case '1':
		SortByWhat(SortByNumb);		
		break;
	case '2':
		SortByWhat(SortByName);
		break;
	case '3':
		SortByWhat(SortByMath);
		break;
	case '0':
		return Sel;
	default:
		puts("��������");
		system("pause");
		return '1';
	}
	
	Print();
	system("pause");

	return Sel;
}

void Print()
{
	system("cls");

	int Sum = DATASum();
	if(!Sum)
	{
		puts("�����ݣ�");
		system("pause");
		return;
	}

	SNode *p = g_pHead;
	puts("*********************");
	printf("  Ŀǰ���� %d ������\n",Sum);
	puts("ѧ��\t����\t�ɼ�");
	while(p)
	{
		printf("%d\t%s\t%.1f\n",p->data.nNumb,p->data.sName,p->data.fMath);
		p = p->pNext;
	}
}

int SortByNumb(SNode *p1,SNode *p2)
{
	return p1->data.nNumb < p2->data.nNumb;
}

int SortByName(SNode *p1,SNode *p2)
{
	return strcmp(p1->data.sName , p2->data.sName) < 0;
}

int SortByMath(SNode *p1,SNode *p2)
{
	return p1->data.fMath > p2->data.fMath;
}



void SortByWhat( int (*SortBy) (SNode *p1,SNode *p2) )
{
	if(g_pHead == NULL  ||  g_pHead ->pNext ==NULL)
		return;
	
	SNode *p = g_pHead, *p1, *pMin;

	while(p)
	{
		p1 = p->pNext;
		pMin = p;

		while(p1)
		{
			if( (*SortBy) (p1,pMin) )
				pMin = p1;
			p1 = p1->pNext;
		}
		
		if(p != pMin)
		{
			SSTU t      =   p->data;
			p ->data    =   pMin->data;
			pMin ->data =   t;
		}
	
		p = p ->pNext;
	}
}


void Insert()
{	
	SSTU pNew;
	int ls = 0,Check = 0;
	char Sel;
	do
	{
		system("cls");
		puts("***�������***");
		printf("�� �� �� ѧ �ţ�");
		scanf("%d",&ls);
		
		Check = CheckNumb(ls);
		
		if(Check == 0)
		{
			puts("��ѧ���Ѵ��ڣ�");
			system("pause");
			return;
		}
		
		pNew.nNumb = ls;
		printf("�� �� �� �� ����");
		scanf("%s",&pNew.sName);
		printf("��������ѧ�ɼ���");
		scanf("%f",&pNew.fMath);
		
		InsertDispose(pNew);
		Save();
		
		puts("¼��ɹ����Ƿ����¼�룿����Yȷ�ϡ�");
		
		Sel = getch();
		
	}while(Sel == 'y'  ||  Sel == 'Y');
	
}

void InsertDispose(SSTU DATA)
{
	SNode *pNew = (SNode*)malloc(sizeof(SNode));
	pNew->data = DATA;
	pNew->pNext = g_pHead;
	g_pHead = pNew;
}

int  CheckNumb(int ls)
{
	SNode *pTest = g_pHead;
	
	while(pTest)
	{
		if(pTest->data.nNumb == ls)
			return 0;
		pTest = pTest->pNext;
	}
	return 1;
}

void SearchMenu()
{
	system("cls");
	puts("***��������***");
	char Sel;
	puts("**************");
	puts("*1.����������*");
	puts("*2.��ѧ�Ų���*");
	puts("**************");
	Sel = getch();
	
	switch(Sel)
	{
	case '1':
		SearchByName();
		system("pause");
		break;
	case '2':
		SearchByNumb();
		system("pause");
		break;
	default:
		puts("�������");
		system("pause");
		return;
	}
}
SNode* SearchByName()
{	
	char SearchName[20];
	printf("������Ҫ���ҵ�ͬѧ������");
	scanf("%s",SearchName);
	
	SNode *p;
	p = FindByNameDispose(SearchName);
	
	if(p == NULL)
		puts("����δ�ҵ���");
	else
	{
		puts("��Ҫ���ҵ������ѱ��ҵ���");
		printf("ѧ�ţ�%d\t������%s\t�ɼ���%.1f\n",p->data.nNumb,p->data.sName,p->data.fMath);
	}
	return p;
}

SNode* FindByNameDispose(char SearchName[20])
{
	SNode *p = g_pHead;
	
	while(p)
	{
		if( strcmp(p->data.sName , SearchName) == 0 )
			break;
		p = p->pNext;
	}
	return p;
} 

SNode* SearchByNumb()
{
	int SearchNumb;
	
	printf("������Ҫ���ҵ�ͬѧѧ�ţ�");
	scanf("%d",&SearchNumb);
	
	SNode *p;
	p = FindByNumbDispose(SearchNumb);
	
	if(p == NULL)
		puts("δ�ҵ������ݣ�");
	
	else
	{
		puts("��Ҫ���ҵ������ѱ��ҵ���");
		printf("ѧ�ţ�%d\t������%s\t�ɼ���%.1f\n",p->data.nNumb,p->data.sName,p->data.fMath);
	}
	return p;
}

SNode* FindByNumbDispose(int SearchNumb)
{
	SNode *p = g_pHead;
	
	while(p)
	{
		if( p->data.nNumb == SearchNumb )
			break;
		p = p->pNext;
	}
	return p;
}

void ModifyMenu()
{
	system("cls");
	char Sel;
	puts("*****�޸�����*****");
	puts("******************");
	puts("1.���������Ҳ��޸�");
	puts("2.��ѧ�Ų��Ҳ��޸�");
	puts("******************");
	Sel = getch();
	
	SNode *p = NULL;
	switch(Sel)
	{
	case '1':
		p = SearchByName();
		ModifyMenu2(p);
		break;
	case '2':
		p = SearchByName();
		ModifyMenu2(p);
		break;
	default:
		puts("�������");
		system("pause");
		return;
	}	
	
}

void ModifyMenu2(SNode* p)
{
	char Sel = 0;
	puts("******************");
	puts("��ѡ��Ҫ�޸ĵ���Ŀ");
	puts(" ***1.�޸�ѧ��***");
	puts(" ***2.�޸�����***");
	puts(" ***3.�޸ĳɼ�***");
	Sel = getch();
	
	switch(Sel)
	{
	case '1':
		ModifyNumb(p);
		break;
	case '2':
		ModifyName(p);
		break;
	case '3':
		ModifyMath(p);
		break;
	default:
		puts("��������");
		system("pause");
		return;
	}
}

void ModifyNumb(SNode* p)
{
	char Decision;
	int  NewNumb;
	
	printf("ԭѧ��Ϊ%d���������޸ĺ��ѧ�ţ�",p->data.nNumb);
	scanf("%d",&NewNumb);
	
	printf("��ȷ����ԭѧ��Ϊ%d������Ϊ%s������ ѧ�Ÿ�Ϊ%d�𣿡���Yȷ�ϡ�",p->data.nNumb,p->data.sName,NewNumb);
	Decision = getch();
	
	if(Decision == 'y'  ||  Decision == 'Y')
	{
		p->data.nNumb = NewNumb;
		Save();
		puts("�޸ĳɹ���");
	}
	else
		puts("ȡ���޸ģ�");
	system("pause");
	return;
}

void ModifyName(SNode* p)
{
	char NewName[20],Decision;
	
	printf("ԭ����Ϊ%s���������޸ĺ��������",p->data.sName);
	scanf("%s",NewName);
	
	printf("��ȷ����ѧ��Ϊ%d��ԭ����Ϊ%s������ ������Ϊ%s�𣿡���Yȷ�ϡ�",p->data.nNumb,p->data.sName,NewName);
	Decision = getch();
	
	if(Decision == 'y'  ||  Decision == 'Y')
	{
		strcpy( p->data.sName , NewName );
		Save();
		puts("�޸ĳɹ���");
	}
	else
		puts("ȡ���޸ģ�");
	system("pause");
	return;	
}

void ModifyMath(SNode* p)
{
	char  Decision;
	float NewMath;
	
	printf("ԭ�ɼ�Ϊ%.1f���������޸ĺ�ĳɼ���",p->data.fMath);
	scanf("%f",&NewMath);
	
	printf("��ȷ��������Ϊ%s������ �ɼ���Ϊ%.1f�𣿡���Yȷ�ϡ�",p->data.sName,NewMath);
	Decision = getch();
	
	if(Decision == 'y'  ||  Decision == 'Y')
	{
		p->data.fMath = NewMath;
		Save();
		puts("�޸ĳɹ���");
	}
	else
		puts("ȡ���޸ģ�");
	system("pause");	
}

void DeleteMenu()
{	
	system("cls");
	char Sel;
	puts("******ɾ������******");
	puts("********************");
	puts("1.������ɾ��");
	puts("2.��ѧ��ɾ��");
	puts("3.�������<����Ա>");
	
	Sel = getch();
	
	switch(Sel)
	{
	case '1':
		DeleteFindByName();
		break;
	case '2':
		DeleteFindByNumb();
		break;
	case '3':
		DeleteAllApprove();
		break;
	default:
		puts("�������");
		system("pause");
		return;
	}
	
}

void DeleteFindByName()
{
	char DName[20],Sel;
	printf("������Ҫɾ�������ݵ�������");
	scanf("%s",DName);
	
	SNode *p = g_pHead, *p1 = NULL;
	
	while(p)
	{
		if( strcmp(p->data.sName , DName) == 0 )
			break;
		p1= p;
		p = p->pNext;
	}
	
	if(p == NULL)
	{
		puts("δ�ҵ������ݣ�");
		system("pause");
		return;
	}
	
	printf("ȷ��Ҫɾ��ѧ��Ϊ��%d ����Ϊ��%s �ɼ�Ϊ��%.1f �������𣿡���Yɾ����",p->data.nNumb,p->data.sName,p->data.fMath);
	Sel = getch();
	
	if(Sel == 'y'  ||  Sel == 'Y')
	{
		if(p1 != NULL)
			p1->pNext = p->pNext;	
		else
			g_pHead = p->pNext;
		free(p);
		Save();
		puts("ɾ���ɹ���");
		system("pause");
		return;
	}

	else
	{
		puts("ȡ��ɾ����");
		system("pause");
		return;
	}
}

void DeleteFindByNumb()
{
	char Sel;
	int  DNumb;
	printf("������Ҫɾ�������ݵ�ѧ�ţ�");
	scanf("%d",&DNumb);
	
	SNode *p = g_pHead, *p1 = NULL;
	
	while(p)
	{
		if( p->data.nNumb == DNumb )
			break;
		p1= p;
		p = p->pNext;
	}
	
	if(p == NULL)
	{
		puts("δ�ҵ������ݣ�");
		system("pause");
		return;
	}
	
	printf("ȷ��Ҫɾ��ѧ��Ϊ��%d ����Ϊ��%s �ɼ�Ϊ��%.1f �������𣿡���Yɾ����",p->data.nNumb,p->data.sName,p->data.fMath);
	Sel = getch();
	
	if(Sel == 'y'  ||  Sel == 'Y')
	{
		if(p1 != NULL)
			p1->pNext = p->pNext;	
		else
			g_pHead = p->pNext;
		free(p);
		Save();
		puts("ɾ���ɹ���");
		system("pause");
		return;
	}
	else
	{
		puts("ȡ��ɾ����");
		system("pause");
		return;
	}
}

void DeleteAllApprove()
{
	system("cls");

	int nRes ;
	
	char Passcode[32];
	printf("���������Ա���룺");
	scanf("%s",Passcode);
	
	if( strcmp(Passcode , "Arsenal2") == 0 )
	{
		nRes = DeleteAllDispose();
		Save();
		if(nRes == 0)
		{
			puts("����Ϊ�գ�");
			system("pause");
			return;
		}
		puts("��ճɹ���");
		system("pause");
		return;
	}
	
	else
	{
		puts("�������");
		system("pause");
		return;
	}
}


int  DeleteAllDispose()
{
	SNode *p = g_pHead, *p1 = NULL;
	
	if(g_pHead == NULL)
		return 0;
	
	while(p)
	{
		if(p1)
			free(p1);
		p1 = p;
		p = p->pNext;
	}
	free(p);
	g_pHead = NULL;
	
	return 1;
}

int  DATASum()
{
	if(g_pHead == NULL)
		return 0;
	SNode *p = g_pHead;
	int Sum = 0;

	while(p)
	{
		++Sum;
		p = p ->pNext;
	}
	return Sum;
}

void SayByeToUser()
{
	Save();
	DeleteAllDispose();
	system("cls");
	puts("\t\t���Ƽ���Ʒ");
	system("pause");
	exit(1);
}

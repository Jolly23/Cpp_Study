// �༶ѧ����Ϣ����.cpp : Defines the entry point for the console application.
//

/*
V1.0 2015��6��5�շ����������������ӡ����ҡ��޸ġ�ɾ������
V1.1 2015��6��7��	 ���������ģʽѡ���ܣ�֧�ֶ��ַ�ʽ����������Ż��Ӿ�Ч������ǿ�û�ʹ���Ѻöȡ�
V1.2 2015��6��8��	 ����ǿ�û�ʹ���Ѻöȡ�
V1.3 2015��6��8��	 ���ش���£��������ݱ��溯����������ݿɱ��棬�����ʹ�ã�
V1.4 2015��6��16��	 ����������������˳�򣬳�����Ӿ���
V1.5 2015��7��17��	 �����Ӵ������ܣ�����ɾ�����޸Ļ���
V1.6 2015��7��17��	 �������޸��������
V1.7 2015��7��18��	 ����������ɸѡ������ܡ��޸������Ż��������ݻ��ƣ���ֹ�������˳������µ����ݶ�ʧ
V1.8 2015��7��18��	 ���������ݷ�������
V1.9 2015��7��18��	 ���޸���֪��BUG
V2.0 2015��7��20��	 �������޸����� ɾ�����޸ĺ� �޷���������⣬�Ż����ݷ����Ľ����ʾ
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

void Version()			;	//��ʾ����汾��
int  Menu()				;	//�����ܲ˵�
void Browse()			;	//������ܲ˵�
void AutoSort()			;	//�ض�������չʾ����ǰ�Ȱ�ѧ������
void SortByName()		;	//������˳����������
void SortByNumb()		;	//��ѧ��˳����������
void SortByMath()		;	//����ѧ�ɼ���������
void Insert()			;	//�������
void Search()			;	//�������ܲ˵�
void SearchNumb()		;	//ͨ��ѧ����������
void SearchName()		;	//ͨ��������������
void Modify()			;	//�޸����ݹ��ܲ˵�
void ModifyNumb()		;	//ͨ��ѧ�Ų��Ҳ��޸�����
void ModifyName()		;	//ͨ���������Ҳ��޸�����
void Delete()			;	//ɾ�����ܲ˵�
void DeleteNumb()		;	//ͨ��ѧ��ɾ������
void DeleteName()		;	//ͨ������ɾ������
void Print()			;	//�������
void Load()				;	//��������
void Save()				;	//��������
void Condition()		;	//����ɸѡ���
int  AllData()			;	//��ǰ�������Ч��������
void DeleteAll();		;	//��յ�ǰȫ������
void DataAnalyse()		;	//���ݷ���
bool Compare(SSTU& s1, SSTU& s2)	;


void main()
{
	float f=0.0f;
	Load();
	while( Menu() != '0' );
	system("cls");
	Save();			//�˴���Save����Ϊ�Է���һ����ֹ��������²�������δ������ɵ����ݶ�ʧ
	printf("\n\n\t\t\t���Ƽ���Ʒ\n\n\n");
	system("pause");
}

void Load()	
{
	FILE *pf = fopen("./stud.lqm","a+");	//�ɶ���д
	int i=0;
	while(fread(&g_stud[i],1,sizeof(SSTU),pf))		//fread(&g_stud[i],1,sizeof(SSTU),pf) ��ȡ�ļ���ֱ��β��
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
	puts("�༶��Ϣ����ϵͳV2.0");
}

int Menu()
{
	system("cls");
	char mode = 0;
	Version();
	puts("1.�������");
	puts("2.��������");
	puts("3.�������");
	puts("4.��������");
	puts("5.�޸�����");
	puts("6.ɾ������");
	puts("0.�˳�����");
	puts("***���๦�����ڿ�����***");
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
	puts("1.����������");
	puts("2.��ѧ������");
	puts("3.����ѧ�ɼ�����");
	puts("4.��ָ������ɸѡ����");
	puts("0.�˻����˵�");
	puts("��ѡ��");
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
		puts("��������");
		system("pause");
		return;
	}
}

void DataAnalyse()
{
	//������߷֡���ͷ�
	//ȫ������ƽ����
	//���ݼ�����
	//���� �š������С���
	system("cls");
	int i=0,Gross;
	float sum = 0,ok = 0,good=0,well=0,mid=0,bad=0;
	SSTU t;
	Gross = AllData();
	Version();
	puts("*********************************\n");
	printf("Ŀǰ���� %d ��ѧ��������\n",Gross);
	while(i<COUNT)
	{
		if(g_stud[i].fMath > t.fMath)
			t = g_stud[i];
		++i;
	}
	printf("\n�������ݵ���߷��� %s ͬѧ����ѧ�ɼ�Ϊ %.1f \n\n",t.sName,t.fMath);
	
	i=0;
	while(i<COUNT)
	{
		if(g_stud[i].fMath < t.fMath  && g_stud[i].nNumb >0 )
			t = g_stud[i];
		++i;
	}
	printf("�������ݵ���ͷ��� %s ͬѧ����ѧ�ɼ�Ϊ %.1f \n\n",t.sName,t.fMath);
	
	i=0;
	while(i < COUNT)
	{
		if( g_stud[i].nNumb >0 )
			sum += g_stud[i].fMath;
		++i;
	}
	printf("�������ݵ�ƽ����Ϊ%.2f\n\n",sum/Gross);
	
	i=0;
	while(i<COUNT)
	{
		if(g_stud[i].fMath >= 60.0)
			++ok;
		++i;
	}
	printf("�������ݵ� ������ Ϊ%.2f%%\n\n",ok/Gross*100);
	
	i=0;
	while(i<COUNT)
	{
		if(g_stud[i].fMath >= 85.0)
			++good;
		++i;
	}
	printf("�������ݵ����� (����85��) ��Ϊ%.2f%%\n\n",good/Gross*100);
	
	i=0;
	while(i<COUNT)
	{
		if(g_stud[i].fMath >= 75.0  &&  g_stud[i].fMath < 85.0)
			++well;
		++i;
	}
	printf("�������ݵ����� (75~85��) ��Ϊ%.2f%%\n\n",well/Gross*100);
	
	i=0;
	while(i<COUNT)
	{
		if(g_stud[i].fMath >= 60.0  &&  g_stud[i].fMath < 75.0)
			++mid;
		++i;
	}
	printf("�������ݵ��е� (60~75��) ��Ϊ%.2f%%\n\n",mid/Gross*100);
	
	i=0;
	while(i<COUNT)
	{
		if(g_stud[i].fMath < 60.0  && g_stud[i].nNumb > 0)
			++bad;
		++i;
	}
	printf("�������ݵ� �� (С��60��) ��Ϊ%.2f%%\n\n",bad/Gross*100);
	
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
	puts("��������ɸѡ����");
	printf("����������Ρ��ո�����:");
	scanf("%f %f",&a,&b);
	if(a>b)
	{
		puts("��������������");
		system("pause");
		return;
	}
	AutoSort();
	printf("\nѧ��\t����\t�ɼ�\n");
	while(i<COUNT)
	{
		if(g_stud[i].nNumb >0  &&  g_stud[i].fMath >= a  &&  g_stud[i].fMath <= b)
		{
			printf("%d\t%s\t%.1f\n",g_stud[i].nNumb,g_stud[i].sName,g_stud[i].fMath);
			gross++;
		}
		++i;
	}
	printf("\n������ɸѡ����%.1f�ֵ�%.1f�ֹ���%d��\n\n\n",a,b,gross);
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
	printf("ѧ��\t����\t�ɼ�\n");
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
	printf("Ŀǰ���� %d ��ѧ��������\n",Gross);
	printf("ѧ��\t����\t�ɼ�\n");
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
			printf("\n����������������������ϵ����Ա��");
			system("pause");
			return;
		}
		printf("\n�� �� �� ѧ �ţ�");
		scanf("%d",&ls);
		if( ls == 0)
			return;
		while(n<COUNT)
		{
			if(g_stud[n].nNumb == ls)
			{
				puts("��ѧ���Ѵ��ڣ�");
				system("pause");
				return;
			}
			++n;
		}
		g_stud[i].nNumb = ls;
		printf("�� �� �� �� ����");
		scanf("%s",g_stud[i].sName);
		printf("��������ѧ�ɼ���");
		scanf("%f",&g_stud[i].fMath);
		system("cls");
		SortByNumb();
		Save();
		printf("\n\n¼��ɹ����Ƿ����¼�����ݣ�����Y����¼�롿��");
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
	puts("1.����ѧ�Ų���");
	puts("2.������������");
	puts("0.�˻����˵�");
	printf("��ѡ��");
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
	printf("������Ҫ���ҵ�ͬѧѧ�ţ�");
	scanf("%d",&SNumb);
	if( SNumb == 0)
		return;
	while(i<COUNT)
	{
		if(SNumb == g_stud[i].nNumb)
			break;
		++i;
	}
	printf("\n%sͬѧ��ѧ��Ϊ%d����ѧ�ɼ�Ϊ%.1f\n",g_stud[i].sName,g_stud[i].nNumb,g_stud[i].fMath);
	system("pause");
}

void SearchName()
{
	system("cls");
	Version();
	int i=0;
	char SName[20];
	printf("������Ҫ���ҵ�ͬѧ������");
	scanf("%s",SName);
	while(i<COUNT)
	{
		if( strcmp(g_stud[i].sName,SName) == 0 )
			break;
		++i;
	}
	printf("\n%sͬѧ��ѧ��Ϊ%d����ѧ�ɼ�Ϊ%.1f\n",g_stud[i].sName,g_stud[i].nNumb,g_stud[i].fMath);
	system("pause");
}

void Modify()
{
	system("cls");
	Version();
	char Mmode = 0;
	puts("*****************");
	puts("1.����ѧ�Ų��Ҳ��޸�");
	puts("2.�����������Ҳ��޸�");
	puts("0.�˻����˵�");
	printf("��ѡ��");
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
	printf("������Ҫ�޸ĵ�ͬѧ��ԭѧ�ţ�");
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
		puts("δ�ҵ��������ݣ�");
		system("pause");
		return;
	}
	printf("\n%sͬѧ��ѧ��Ϊ%d����ѧ�ɼ�Ϊ%.1f\nȷ��Ҫ�޸Ĵ��������𣿡���Y��ʼ�޸ġ�",g_stud[i].sName,g_stud[i].nNumb,g_stud[i].fMath);
	Decision = getch();
	if(Decision == 'y' || Decision == 'Y')
	{
		puts("\n**************");
		puts("1.ѧ���޸�");
		puts("2.�����޸�");
		puts("3.��ѧ�ɼ��޸�");
		puts("0.ȡ���޸�");
		Mmode = getch();
		switch(Mmode)
		{
		case '1':
			{
				printf("�������޸ĺ��ѧ�ţ�");
				scanf("%d",&g_stud[i].nNumb);
				Save();
				puts("\n**************");
				printf("\n�޸ĳɹ���");
				printf("\n�޸ĺ�%sͬѧ��ѧ��Ϊ%d����ѧ�ɼ�Ϊ%.1f\n",g_stud[i].sName,g_stud[i].nNumb,g_stud[i].fMath);
				system("pause");
				return;
			}
			break;
		case '2':
			{
				printf("�������޸ĺ��������");
				scanf("%s",g_stud[i].sName);
				Save();
				puts("\n**************");
				printf("\n�޸ĳɹ���");
				printf("\n�޸ĺ�%sͬѧ��ѧ��Ϊ%d����ѧ�ɼ�Ϊ%.1f\n",g_stud[i].sName,g_stud[i].nNumb,g_stud[i].fMath);
				system("pause");
				return;
			}
			break;
		case '3':
			{
				printf("�������޸ĺ����ѧ�ɼ���");
				scanf("%f",&g_stud[i].fMath);
				Save();
				puts("\n**************");
				printf("\n�޸ĳɹ���");
				printf("\n�޸ĺ�%sͬѧ��ѧ��Ϊ%d����ѧ�ɼ�Ϊ%.1f\n",g_stud[i].sName,g_stud[i].nNumb,g_stud[i].fMath);
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
	printf("������Ҫ�޸ĵ�ͬѧ��ԭ������");
	scanf("%s",&MName);
	while(i<COUNT)
	{
		if(  strcmp(g_stud[i].sName , MName)==0  )
			break;
		++i;
	}
	if(i == COUNT)
	{
		puts("δ�ҵ��������ݣ�");
		system("pause");
		return;
	}
	printf("\n%sͬѧ��ѧ��Ϊ%d����ѧ�ɼ�Ϊ%.1f\nȷ��Ҫ�޸Ĵ��������𣿡���Y��ʼ�޸ġ�",g_stud[i].sName,g_stud[i].nNumb,g_stud[i].fMath);
	Decision = getch();
	if(Decision == 'y' || Decision == 'Y')
	{
		puts("\n**************");
		puts("1.ѧ���޸�");
		puts("2.�����޸�");
		puts("3.��ѧ�ɼ��޸�");
		puts("0.ȡ���޸�");
		Mmode = getch();
		switch(Mmode)
		{
		case '1':
			{
				printf("�������޸ĺ��ѧ�ţ�");
				scanf("%d",&g_stud[i].nNumb);
				Save();
				puts("\n**************");
				printf("\n�޸ĳɹ���");
				printf("\n�޸ĺ�%sͬѧ��ѧ��Ϊ%d����ѧ�ɼ�Ϊ%.1f\n",g_stud[i].sName,g_stud[i].nNumb,g_stud[i].fMath);
				system("pause");
				return;
			}
			break;
		case '2':
			{
				printf("�������޸ĺ��������");
				scanf("%s",g_stud[i].sName);
				Save();
				puts("\n**************");
				printf("\n�޸ĳɹ���");
				printf("\n�޸ĺ�%sͬѧ��ѧ��Ϊ%d����ѧ�ɼ�Ϊ%.1f\n",g_stud[i].sName,g_stud[i].nNumb,g_stud[i].fMath);
				system("pause");
				return;
			}
			break;
		case '3':
			{
				printf("�������޸ĺ����ѧ�ɼ���");
				scanf("%f",&g_stud[i].fMath);
				Save();
				puts("\n**************");
				printf("\n�޸ĳɹ���");
				printf("\n�޸ĺ�%sͬѧ��ѧ��Ϊ%d����ѧ�ɼ�Ϊ%.1f\n",g_stud[i].sName,g_stud[i].nNumb,g_stud[i].fMath);
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
	puts("1.����ѧ��ɾ��");
	puts("2.��������ɾ��");
	puts("3.���ȫ������(����Ա)");
	puts("0.�˻����˵�");
	printf("��ѡ��");
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
	printf("������Ҫɾ����ͬѧѧ�ţ�");
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
		puts("δ�ҵ���ѧ�ţ�");
		system("pause");
		return;
	}
	printf("ȷ��Ҫɾ��ѧ��Ϊ%d��%s����Ϣ������Yɾ����\n",g_stud[i].nNumb,g_stud[i].sName);
	Decision = getch();
	if(Decision == 'y' || Decision == 'Y')
	{
		g_stud[i].nNumb = -1;
		Save();
		puts("\nɾ���ɹ���\n");
		system("pause");
	}
	else
	{
		puts("\nɾ��ȡ����\n");
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
	printf("������Ҫɾ����ͬѧ������");
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
		puts("δ�ҵ���������");
		system("pause");
		return;
	}
	printf("ȷ��Ҫɾ��ѧ��Ϊ%d��%s����Ϣ������Yɾ����\n",g_stud[i].nNumb,g_stud[i].sName);
	Decision = getch();
	if(Decision == 'y' || Decision == 'Y')
	{
		g_stud[i].nNumb = -1;
		Save();
		puts("\nɾ���ɹ���\n");
		system("pause");
	}
	else
	{
		puts("\nɾ��ȡ����\n");
		system("pause");
		return;
	}
}

void DeleteAll()
{
	system("cls");
	Version();
	puts("\n���棺��ѡ�������ȫ�����ݣ������ʹ�ô˹��ܣ�");
	char password[32],Decision;
	printf("\n������������룺");
	scanf("%s",password);
	if( strcmp( password , "Arsenal2" ) == 0 )
	{
		puts("\nȷ�����ȫ�������𣿡���Yȷ�ϡ�");
		Decision = getch();
		if(Decision == 'y'  ||  Decision == 'Y')
		{
			memset(g_stud,0,sizeof(g_stud));
			Save();
			puts("�����ѱ�ȫ����գ�");
			system("pause");
			return;
		}
		else
		{
			puts("ȡ����գ�");
			system("pause");
			return;
		}
	}
	else
	{
		puts("�������");
		system("pause");
		return;
	}
}

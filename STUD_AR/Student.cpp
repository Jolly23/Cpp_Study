// Student.cpp: implementation of the CStudent class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Student.h"
#include <conio.h>
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStudent::CStudent()
{
	
}

CStudent::~CStudent()
{

}

void CStudent::Version()
{
	cout << "���԰�1.0" << endl;
}

void CStudent::Load()
{
	FILE *fp = fopen("workers.lqm","a+");
	DATA data ;
	while( fread(&data,1,sizeof(DATA),fp) >0 )
		m_arr.Add(data);
	fclose(fp);
}

void CStudent::Save()
{
	FILE *fp = fopen("workers.lqm","w");
	
	int i = 0 ;
	int nSize = m_arr.GetSize();

	while(i < nSize)
	{
		DATA &data = m_arr.ElementAt(i++);
		fwrite(&data,1,sizeof(SInfo),fp);	
	}
	fclose(fp);
}
void CStudent::Menu()
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

void CStudent::MenuDispose(char Select)
{
	switch(Select)
	{
	case '1':
//		Print();
		while( BrowseMenu() != '0' );
		system("pause");
		break;
	case '2':
//		DataAnalyse();
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

void CStudent::Print()
{
	system("cls");
	int i = 0;
	int nSize = m_arr.GetSize();

	cout << "����\t����\t����" << endl;
	while(i < nSize)
	{
		cout << m_arr[i].nNumb << "\t" << m_arr[i].sName << "\t" << m_arr[i].fSala << endl;
		++i;
	}
}

void CStudent::Print(int Numb)
{
	cout << "����\t����\t����" << endl;
	cout << m_arr[Numb].nNumb << "\t" << m_arr[Numb].sName << "\t" << m_arr[Numb].fSala <<endl;
	system("pause");
}

void CStudent::Insert()
{
	system("cls");
	DATA New;
	cout << "�����빤�ţ�";
	cin  >> New.nNumb ;
	if(ChackNumb(New.nNumb) == false)
	{
		cout << "�Ѵ��ڴ�Ա����Ϣ�������޸���ѡ���޸ġ�ѡ��" << endl;
		return;
	}
	cout << "������������";
	cin  >> New.sName ;
	cout << "�����빤�ʣ�";
	cin  >> New.fSala ;
	m_arr.Add(New);
	cout << "¼��ɹ���" << endl;
	system("pause");
}


void CStudent::SayByeToUser()
{
	Save();
	cout << "���н���" << endl;
	system("pause");
	exit(1);
}


bool CStudent::ChackNumb(int nNumb)
{
	int i = 0;
	int nSize = m_arr.GetSize();
	while(i < nSize)
	{
		if(m_arr[i].nNumb == nNumb)
			return false;
		++i;
	}
	return true;
}

void CStudent::SearchMenu()
{
	system("cls");
	char Sel;
	int position;
	cout << "��ѡ��������ʽ" << endl
		 << "1.����������"   << endl
		 << "2.����������"   << endl;
	Sel = getch();
	switch(Sel)
	{
	case '1':
		position = SearchByName();
		if(position != -1)
			Print(position);
		break;
	case '2':
		position = SearchByNumb();
		if(position != -1)
			Print(position);
		break;
	default:
		SearchMenu();
	}
}

int CStudent::SearchByName()
{
	system("cls");
	char SName[20];
	cout << "������Ա��������" ;
	cin  >> SName;
	
	int i = 0, nSize = m_arr.GetSize();
	while( i < nSize )
	{
		if(strcmp(m_arr[i].sName,SName)==0)
			return i;
		++i;
	}
	cout << "δ�ҵ�����Ϊ " << SName << " ��Ա�������֤���ٲ飡" << endl;
	system("pause");
	return -1;
}

int CStudent::SearchByNumb()
{
	system("cls");
	int SNumb;
	cout << "�����빤�ţ�" ;
	cin  >> SNumb;
	
	int i = 0, nSize = m_arr.GetSize();
	while( i < nSize )
	{
		if(m_arr[i].nNumb == SNumb)
			return i;
		++i;
	}
	cout << "δ�ҵ�����Ϊ " << SNumb << " ��Ա�������֤���ٲ飡" << endl;
	system("pause");
	return -1;
}

void CStudent::DeleteMenu()
{
	system("cls");
	char Sel;
	int position;
	cout << "��ѡ��ɾ����ʽ��" << endl
		 << "1.������ɾ��" << endl
		 << "2.������ɾ��" << endl;
	Sel = getch();
	switch(Sel)
	{
	case '1':
		position = SearchByName();
		if(position != -1)
		{
			Delete(position);
			cout << "ɾ���ɹ���" << endl;
			system("pause");
		}
		break;

	case '2':
		position = SearchByNumb();
		if(position != -1)
		{
			Delete(position);
			cout << "ɾ���ɹ���" << endl;
			system("pause");
		}
		break;
	default:
		DeleteMenu();
	}
}

void CStudent::Delete(int DNumb)
{
	m_arr.RemoveAt(DNumb);
}

void CStudent::ModifyMenu()
{
	system("cls");
	char Sel;
	int  position;
	cout << "��ѡ���޸ķ�ʽ��" << endl
		 << "1.�����������޸�" << endl
		 << "2.�����Ų����޸�" << endl;
	Sel = getch();
	switch(Sel)
	{
	case '1':
		position = SearchByName();
		ModifyOS(position);
		break;
	case '2':
		position = SearchByNumb();
		ModifyOS(position);
		break;
	default:
		ModifyMenu();
	}
}

void CStudent::ModifyOS(int position)
{
	system("cls");
	char Sel;
	cout << "��ѡ��Ҫ�޸ĵ�����" << endl
		 << "1.�޸�����" << endl
		 << "2.�޸Ĺ���" << endl
		 << "3.�޸Ĺ���" << endl;
	Sel = getch();
	switch(Sel)
	{
	case '1':
		ModifyName(position);
	case '2':
		ModifyNumb(position);
	case '3':
		ModifySalary(position);
	default:
		ModifyOS(position);
	}
}

void CStudent::ModifyName(int position)
{
	system("cls");
	char MName[20];

	cout << "���� " << m_arr[position].nNumb << " ��Ա����ԭ����Ϊ " << m_arr[position].sName << endl
		 << "�������޸ĺ��������" ;
	cin  >> MName;
	strcpy(m_arr[position].sName , MName);
	cout << "�޸ĳɹ���" << endl;
	system("pause");
}

void CStudent::ModifyNumb(int position)
{
	system("cls");
	int MNumb;

	cout << "���� " << m_arr[position].sName << " ��Ա����ԭ����Ϊ " << m_arr[position].nNumb << endl
		 << "�������޸ĺ�Ĺ��ţ�" ;
	cin  >> MNumb;
	m_arr[position].nNumb = MNumb;
	cout << "�޸ĳɹ���" << endl;
	system("pause");

}

void CStudent::ModifySalary(int position)
{
	system("cls");
	float MSalary;

	cout << "���� " << m_arr[position].sName << " ��Ա����ԭ����Ϊ " << m_arr[position].fSala << endl
		 << "�������޸ĺ�Ĺ��ʣ�" ;
	cin  >> MSalary;
	m_arr[position].fSala = MSalary;
	cout << "�޸ĳɹ���" << endl;
	system("pause");
}

char CStudent::BrowseMenu()
{
	system("cls");
	if( !m_arr.GetSize() )
	{
		cout << "�����ݣ�" << endl;
		system("pause");
		Menu();
		return -1;
	}
	char Sel;
	puts("***�������***");
	puts("**************");
	puts("*1.����������*");
	puts("*2.����������*");
	puts("*3.����������*");
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
		SortByWhat(SortBySalary);
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

void CStudent::SortByWhat( int (*SortBy) (DATA *p1,DATA *p2) )
{
	int i = 0 , j = 0 , nMin = 0 , nSize = m_arr.GetSize();
	while(i < nSize)
	{
		j = i + 1;
		nMin = i;

		while(j < nSize)
		{
			if( (*SortBy) (&m_arr[j],&m_arr[nMin]) )
				nMin = j;
			++j;
		}
		
		if(i != nMin)
		{
			DATA t      =   m_arr[i];
			m_arr[i]    =   m_arr[nMin];
			m_arr[nMin] =   t;
		}
	
		++i;
	}
}

int SortByNumb(DATA *p1,DATA *p2)
{	return p1->nNumb < p2->nNumb;				}

int SortByName(DATA *p1,DATA *p2)
{	return strcmp(p1->sName , p2->sName) < 0;	}

int SortBySalary(DATA *p1,DATA *p2)
{	return p1->fSala > p2->fSala;				}

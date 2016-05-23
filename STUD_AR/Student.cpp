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
	cout << "测试版1.0" << endl;
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
	puts("**1.浏览数据**");
	puts("**2.数据分析**");
	puts("**3.添加数据**");
	puts("**4.查找数据**");
	puts("**5.修改数据**");
	puts("**6.删除数据**");
	puts("**0.退出程序**");
	puts("**************");
	
	Select = getch();
	
	if(Select >= '0'  &&  Select <= '6')
		MenuDispose(Select);
	
	else
	{
		puts("输入有误！");
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

	cout << "工号\t姓名\t工资" << endl;
	while(i < nSize)
	{
		cout << m_arr[i].nNumb << "\t" << m_arr[i].sName << "\t" << m_arr[i].fSala << endl;
		++i;
	}
}

void CStudent::Print(int Numb)
{
	cout << "工号\t姓名\t工资" << endl;
	cout << m_arr[Numb].nNumb << "\t" << m_arr[Numb].sName << "\t" << m_arr[Numb].fSala <<endl;
	system("pause");
}

void CStudent::Insert()
{
	system("cls");
	DATA New;
	cout << "请输入工号：";
	cin  >> New.nNumb ;
	if(ChackNumb(New.nNumb) == false)
	{
		cout << "已存在此员工信息，如需修改请选择“修改”选项" << endl;
		return;
	}
	cout << "请输入姓名：";
	cin  >> New.sName ;
	cout << "请输入工资：";
	cin  >> New.fSala ;
	m_arr.Add(New);
	cout << "录入成功！" << endl;
	system("pause");
}


void CStudent::SayByeToUser()
{
	Save();
	cout << "运行结束" << endl;
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
	cout << "请选择搜索方式" << endl
		 << "1.按姓名搜索"   << endl
		 << "2.按工号搜索"   << endl;
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
	cout << "请输入员工姓名：" ;
	cin  >> SName;
	
	int i = 0, nSize = m_arr.GetSize();
	while( i < nSize )
	{
		if(strcmp(m_arr[i].sName,SName)==0)
			return i;
		++i;
	}
	cout << "未找到姓名为 " << SName << " 的员工，请查证后再查！" << endl;
	system("pause");
	return -1;
}

int CStudent::SearchByNumb()
{
	system("cls");
	int SNumb;
	cout << "请输入工号：" ;
	cin  >> SNumb;
	
	int i = 0, nSize = m_arr.GetSize();
	while( i < nSize )
	{
		if(m_arr[i].nNumb == SNumb)
			return i;
		++i;
	}
	cout << "未找到工号为 " << SNumb << " 的员工，请查证后再查！" << endl;
	system("pause");
	return -1;
}

void CStudent::DeleteMenu()
{
	system("cls");
	char Sel;
	int position;
	cout << "请选择删除方式：" << endl
		 << "1.按姓名删除" << endl
		 << "2.按工号删除" << endl;
	Sel = getch();
	switch(Sel)
	{
	case '1':
		position = SearchByName();
		if(position != -1)
		{
			Delete(position);
			cout << "删除成功！" << endl;
			system("pause");
		}
		break;

	case '2':
		position = SearchByNumb();
		if(position != -1)
		{
			Delete(position);
			cout << "删除成功！" << endl;
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
	cout << "请选择修改方式：" << endl
		 << "1.按姓名查找修改" << endl
		 << "2.按工号查找修改" << endl;
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
	cout << "请选择要修改的内容" << endl
		 << "1.修改姓名" << endl
		 << "2.修改工号" << endl
		 << "3.修改工资" << endl;
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

	cout << "工号 " << m_arr[position].nNumb << " 的员工，原姓名为 " << m_arr[position].sName << endl
		 << "请输入修改后的姓名：" ;
	cin  >> MName;
	strcpy(m_arr[position].sName , MName);
	cout << "修改成功！" << endl;
	system("pause");
}

void CStudent::ModifyNumb(int position)
{
	system("cls");
	int MNumb;

	cout << "姓名 " << m_arr[position].sName << " 的员工，原工号为 " << m_arr[position].nNumb << endl
		 << "请输入修改后的工号：" ;
	cin  >> MNumb;
	m_arr[position].nNumb = MNumb;
	cout << "修改成功！" << endl;
	system("pause");

}

void CStudent::ModifySalary(int position)
{
	system("cls");
	float MSalary;

	cout << "姓名 " << m_arr[position].sName << " 的员工，原工资为 " << m_arr[position].fSala << endl
		 << "请输入修改后的工资：" ;
	cin  >> MSalary;
	m_arr[position].fSala = MSalary;
	cout << "修改成功！" << endl;
	system("pause");
}

char CStudent::BrowseMenu()
{
	system("cls");
	if( !m_arr.GetSize() )
	{
		cout << "无数据！" << endl;
		system("pause");
		Menu();
		return -1;
	}
	char Sel;
	puts("***浏览数据***");
	puts("**************");
	puts("*1.按工号排序*");
	puts("*2.按姓名排序*");
	puts("*3.按工资排序*");
	puts("*0.返回主菜单*");

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
		puts("输入有误！");
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

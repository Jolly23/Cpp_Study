// Students.cpp: implementation of the CStudents class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStudents::CStudents():ServerPort(10150)
{

}

CStudents::~CStudents()
{

}

void CStudents::Start()
{
	while(Menu())
		;
}

int CStudents::Menu()
{
	system("cls");
	cout << "*************" << endl;
	cout << "1、浏览数据" << endl;
	cout << "2、添加数据" << endl;
	cout << "3、删除数据" << endl;
	cout << "4、修改数据" << endl;
	cout << "5、查找数据" << endl;
	cout << "0、 退 出 "  << endl;
	cout << "*************" << endl;
	char cSel = getch();
	switch(cSel)
	{
	case '0':
		return 0;
	case '1':
		PrintMenu();
		break;
	case '2':
		Input();
		break;
	case '3':
		Delete();
		break;
	case '4':
		Modify();
		break;
	case '5':
		FindData();
		break;
	default:
		return 1;
	};
	return 1;
}

void CStudents::Input()
{
	Stud NewSt;
	cout << "请输入姓名：";
	cin >> NewSt.sName;
	cout << endl << "请输入学号：" ;
	cin >> NewSt.nNumb;
	if(!CheckNumb(NewSt.nNumb))
	{
		cout << "此学号已存在！" << endl;
		system("pause");
		return;
	}
	char cSelSex;
	do{
		cout << "请选择性别 （1.男 - 2.女）" << endl;
		cSelSex = getch();
		if(cSelSex == '1')
			strcpy(NewSt.sSex,"男");
		if(cSelSex == '2')
			strcpy(NewSt.sSex,"女");
	}while(cSelSex != '1'  &&  cSelSex != '2');
	
	int nCmd = REQ_ADD;	
	SockJollyEx sock;
	if(!sock.Start())
		return;
	sock.Send(&nCmd,4);
	sock.Send(&NewSt,sizeof(NewSt));
}

void CStudents::Print()
{
	int nCount = 0;
	Stud StuData;	
	int nCmd = REQ_BROW;

	SockJollyEx sock;
	if(!sock.Start())
		return;
	sock.Send(&nCmd,4);
	sock.Receive(&nCount,sizeof(int));
	cout << "共有 " << nCount << " 条数据" << endl;
	while(nCount--)
	{
		sock.Receive(&StuData,sizeof(Stud));
		cout << "学号：" << StuData.nNumb << "\t姓名" <<  StuData.sName << "\t性别:" << StuData.sSex << endl;
	}
}

bool CStudents::Print(int nPNumb)
{
	int nCmd = REQ_BROWONE;
	Stud StuData;
	
	SockJollyEx sock;
	if(!sock.Start())
		return false;
	sock.Send(&nCmd,sizeof(nCmd));
	sock.Send(&nPNumb,sizeof(nPNumb));
	sock.Receive(&StuData,sizeof(Stud));

	if(StuData.nNumb == -1)
		return false;
	cout << "学号：" << StuData.nNumb << "\t姓名:" <<  StuData.sName << "\t性别:" << StuData.sSex << endl;
	return true;
}

void CStudents::Delete()
{
	Print();
	int DNumb;
	fflush(stdin);
	cout << "请输入要删除的数据学号：" ;
	cin >> DNumb;
	if(  !(Print(DNumb))  ){
		cout << "未找到此数据！" << endl;
		return;
	}
	cout << "确认要删除这条数据吗？[Y/N]" << endl;
	char cSel = getch();
	if(cSel == 'Y'  ||  cSel == 'y'){
		int nCmd = REQ_DELONE;
		SockJollyEx sock;
		if(!sock.Start())
			return;
		sock.Send(&nCmd,sizeof(nCmd));
		sock.Send(&DNumb,sizeof(DNumb));
	}
	else
		cout << "取消删除！" << endl;
}

void CStudents::FindData()
{
	int nNumb;
	cout << "请输入要查找的学号：" ;
	cin >> nNumb;
	if( !Print(nNumb) )
		cout << "学号 " << nNumb << " 不存在！ " << endl;
	system("pause");
	return;
}

void CStudents::Modify()
{
	int MNumb ;
	Stud ModData,Giveup = {-1,"NULL","ER"},NewData;
	char NewName[20],cSelSex;

	cout << "请输入要修改的数据学号：";
	cin  >> MNumb;

	if(!Print(MNumb)){
		cout << "此学号不存在！" << endl;
		system("pause");
		return;
	}

	cout << "请输入修改后的姓名：" ;
	cin >> NewData.sName;
	do{
		cout << "请选择性别 （1.男 - 2.女）" << endl;
		cSelSex = getch();
		if(cSelSex == '1')
			strcpy(NewData.sSex,"男");
		if(cSelSex == '2')
			strcpy(NewData.sSex,"女");
	}while(cSelSex != '1'  &&  cSelSex != '2');
	cout << (cSelSex == 1 ? "男" : "女") << endl;

	NewData.nNumb = MNumb;
	cout << "确认保存更改吗？[Y/N]" << endl;
	char cD = getch();

	int nCmd = REQ_MOD;
	if(cD == 'Y'  ||  cD == 'y'){
		SockJollyEx sock;
		if(!sock.Start())
			return;
		sock.Send(&nCmd,sizeof(nCmd));
		sock.Send(&NewData,sizeof(Stud));
	}
}

int SortByNumb(Stud *p1,Stud *p2)
{
	return p1->nNumb < p2->nNumb;
}

int SortByName(Stud *p1,Stud *p2)
{
	return strcmp(p1->sName , p2->sName) < 0;
}

int SortBySex(Stud *p1,Stud *p2)
{
	return strcmp(p1->sSex , p2->sSex) < 0;
}

int CStudents::PrintMenu()
{
	cout << "请选择浏览排序方式" << endl
		 << "1.按学号排序" << endl
		 << "2.按姓名排序" << endl
		 << "0.退出浏览" << endl;
	char cSel = getch();
	switch(cSel)
	{
	case '1':
		SortBy(1);
		break;
	case '2':
		SortBy(2);
		break;
	case '0':
		return 0;
	};
	return 0;
}

int SortByNumb (const void * a, const void * b)
{
	Stud *stu1 = (Stud*)a;
	Stud *stu2 = (Stud*)b;
	if(stu1->nNumb < stu2->nNumb)	return -1;
	if(stu1->nNumb == stu2->nNumb)	return 0;
	if(stu1->nNumb > stu2->nNumb)	return 1;
}

int SortByName (const void * a, const void * b)
{
	Stud *stu1 = (Stud*)a;
	Stud *stu2 = (Stud*)b;
	return strcmp(stu1->sName , stu2->sName);
}

void CStudents::SortBy(int nSel)
{
	int nCmd = REQ_BROW, nCount, i = 0;
	vector<Stud> ls_list;
	Stud StuData;

	SockJollyEx sock;
	if(!sock.Start())
		return;
	sock.Send(&nCmd,4);
	sock.Receive(&nCount,sizeof(int));
	if(nCount == 0)
		return ;

	while(i < nCount)
	{
		sock.Receive(&StuData,sizeof(StuData));
		ls_list.push_back(StuData);
		++i;
	}
	sock.Close;
	
	if(nSel == 1)	{
		qsort (&ls_list[0], nCount, sizeof(Stud), SortByNumb);
	}
	if(nSel == 2)	{
		qsort (&ls_list[0], nCount, sizeof(Stud), SortByName);
	}

	i = 0;
	while(i < nCount)
	{
		cout << "学号：" << ls_list[i].nNumb << "\t姓名：" <<  ls_list[i].sName << "\t性别:" << ls_list[i].sSex << endl;
		++i;
	}
	system("pause");
}

BOOL CStudents::CheckNumb(int CNumb)
{
	int nCmd = REQ_CNUMB, i = 0;
	SockJollyEx sock;
	if(!sock.Start())
		return FALSE;
	sock.Send(&nCmd,4);
	sock.Send(&CNumb,sizeof(int));
	sock.Receive(&i,sizeof(int));

	if(-1 == i)
		return TRUE;
	else
		return FALSE;
}

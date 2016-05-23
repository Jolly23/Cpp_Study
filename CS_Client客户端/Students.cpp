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
	cout << "1���������" << endl;
	cout << "2���������" << endl;
	cout << "3��ɾ������" << endl;
	cout << "4���޸�����" << endl;
	cout << "5����������" << endl;
	cout << "0�� �� �� "  << endl;
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
	cout << "������������";
	cin >> NewSt.sName;
	cout << endl << "������ѧ�ţ�" ;
	cin >> NewSt.nNumb;
	if(!CheckNumb(NewSt.nNumb))
	{
		cout << "��ѧ���Ѵ��ڣ�" << endl;
		system("pause");
		return;
	}
	char cSelSex;
	do{
		cout << "��ѡ���Ա� ��1.�� - 2.Ů��" << endl;
		cSelSex = getch();
		if(cSelSex == '1')
			strcpy(NewSt.sSex,"��");
		if(cSelSex == '2')
			strcpy(NewSt.sSex,"Ů");
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
	cout << "���� " << nCount << " ������" << endl;
	while(nCount--)
	{
		sock.Receive(&StuData,sizeof(Stud));
		cout << "ѧ�ţ�" << StuData.nNumb << "\t����" <<  StuData.sName << "\t�Ա�:" << StuData.sSex << endl;
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
	cout << "ѧ�ţ�" << StuData.nNumb << "\t����:" <<  StuData.sName << "\t�Ա�:" << StuData.sSex << endl;
	return true;
}

void CStudents::Delete()
{
	Print();
	int DNumb;
	fflush(stdin);
	cout << "������Ҫɾ��������ѧ�ţ�" ;
	cin >> DNumb;
	if(  !(Print(DNumb))  ){
		cout << "δ�ҵ������ݣ�" << endl;
		return;
	}
	cout << "ȷ��Ҫɾ������������[Y/N]" << endl;
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
		cout << "ȡ��ɾ����" << endl;
}

void CStudents::FindData()
{
	int nNumb;
	cout << "������Ҫ���ҵ�ѧ�ţ�" ;
	cin >> nNumb;
	if( !Print(nNumb) )
		cout << "ѧ�� " << nNumb << " �����ڣ� " << endl;
	system("pause");
	return;
}

void CStudents::Modify()
{
	int MNumb ;
	Stud ModData,Giveup = {-1,"NULL","ER"},NewData;
	char NewName[20],cSelSex;

	cout << "������Ҫ�޸ĵ�����ѧ�ţ�";
	cin  >> MNumb;

	if(!Print(MNumb)){
		cout << "��ѧ�Ų����ڣ�" << endl;
		system("pause");
		return;
	}

	cout << "�������޸ĺ��������" ;
	cin >> NewData.sName;
	do{
		cout << "��ѡ���Ա� ��1.�� - 2.Ů��" << endl;
		cSelSex = getch();
		if(cSelSex == '1')
			strcpy(NewData.sSex,"��");
		if(cSelSex == '2')
			strcpy(NewData.sSex,"Ů");
	}while(cSelSex != '1'  &&  cSelSex != '2');
	cout << (cSelSex == 1 ? "��" : "Ů") << endl;

	NewData.nNumb = MNumb;
	cout << "ȷ�ϱ��������[Y/N]" << endl;
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
	cout << "��ѡ���������ʽ" << endl
		 << "1.��ѧ������" << endl
		 << "2.����������" << endl
		 << "0.�˳����" << endl;
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
		cout << "ѧ�ţ�" << ls_list[i].nNumb << "\t������" <<  ls_list[i].sName << "\t�Ա�:" << ls_list[i].sSex << endl;
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

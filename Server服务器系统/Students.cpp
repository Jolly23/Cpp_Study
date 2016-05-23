// Students.cpp: implementation of the CStudents class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Students.h"
#include "SockJolly.h"
#include <process.h>
#include <iostream>
using namespace std;
const int SelfPort = 10150;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStudents::CStudents()
{
	this->Load();
}	

CStudents::~CStudents()
{
	this->Save();
}

void theProc(void *p)
{
	SockJolly *pSocka = (SockJolly*)p;
	while( CStudents::st.OnReceive(pSocka) )
		;
	pSocka->Close();
	delete pSocka;
}

void CStudents::Start()
{
	if(!m_sock.Create(SelfPort)) 
	{
		cout << "端口创建失败：" << WSAGetLastError() << endl;
		return;
	}
	m_sock.Listen();
	char szIP[20];
	UINT nPort;
	SockJolly *pSocka = new SockJolly;
	while( m_sock.Accept(*pSocka,szIP,&nPort) )
	{
		cout << "客户端登录：" << szIP << " - " << nPort << endl;
		_beginthread(theProc,0,pSocka);
		pSocka = new SockJolly;
	}
	delete pSocka;
}

BOOL CStudents::OnReceive(SockJolly *pSocka)
{
	int nCmd = 0;
	if(  (pSocka ->Receive(&nCmd,sizeof(int))) <= 0  )
		return FALSE;
	switch(nCmd)
	{
	case REQ_ADD:
		cout << "请求添加数据" << endl;
		return AddStud(pSocka);
		break;
	case REQ_DELALL:
		cout << "请求删除全部数据" << endl;
		break;
	case REQ_DELONE:
		cout << "请求删除单个数据" << endl;
		return DeleteOne(pSocka);
	case REQ_MOD:
		cout << "请求修改单个数据" << endl;
		return ModifyData(pSocka);
		break;
	case REQ_FINDBYNUMB:
		cout << "请求查询单个数据" << endl;
		break;
	case REQ_BROW:
		cout << "请求查看全部数据" << endl;
		return SendAllData(pSocka);
	case REQ_BROWONE:
		cout << "请求查询单个数据" << endl;
		return SendOneData(pSocka);
		break;
	case REQ_CNUMB:
		cout << "请求检查学号是否存在" << endl;
		return CheckOneNumb(pSocka);
		break;
	};
	return TRUE;
}

BOOL CStudents::AddStud(SockJolly *pSocka)
{
	Stud NewSt;
	if(  (pSocka ->Receive(&NewSt,sizeof(Stud))) <= 0 )
		return FALSE;
	m_list.push_back(NewSt);
	this->Save();
	return TRUE;
}

BOOL CStudents::SendAllData(SockJolly *pSocka)
{
	int nCount = m_list.size(), i = 0;
	pSocka ->Send(&nCount,sizeof(int));
	
	while(i < nCount)
	{
		Stud &data = m_list[i];
		pSocka ->Send(&data,sizeof(Stud));
		++i;
	}
	return TRUE;
}

BOOL CStudents::SendOneData(SockJolly *pSocka)
{
	int nDeleteNumb, i = 0, nCount = m_list.size();
	if(  (pSocka ->Receive(&nDeleteNumb,sizeof(nDeleteNumb))) <= 0 )
		return FALSE;
	
	while(i < nCount)
	{
		Stud &data = m_list[i];
		if(data.nNumb == nDeleteNumb){
			pSocka ->Send(&data,sizeof(Stud));
			return TRUE;
		}
		++i;
	}
	Stud NotFound = {-1,"NULL","ER"};
	pSocka ->Send(&NotFound,sizeof(NotFound));
	return TRUE;
}

BOOL CStudents::DeleteOne(SockJolly *pSocka)
{
	int nDeleteNumb, i = 0, nCount = m_list.size();
	pSocka ->Receive(&nDeleteNumb,sizeof(nDeleteNumb));
	
	while(i < nCount)
	{
		Stud &data = m_list[i];
		if(data.nNumb == nDeleteNumb){
			m_list.erase(&m_list[i]);
			this->Save();
			return TRUE;
		}
		++i;
	}
	return FALSE;
}

BOOL CStudents::ModifyData(SockJolly *pSocka)
{
	Stud NewData;
	int nCount = m_list.size(), i = 0;
	if( (pSocka->Receive(&NewData,sizeof(Stud))) <=0)
		return FALSE;
	while(i < nCount)
	{
		if(m_list[i].nNumb == NewData.nNumb) {
			m_list.erase(&m_list[i]);
			m_list.push_back(NewData);
			break;
		}
		++i;
	}
	this->Save();
	return TRUE;
}

BOOL CStudents::CheckOneNumb(SockJolly *pSocka)
{
	int CNumb;
	int nCount = m_list.size(), i = 0;
	if( (pSocka->Receive(&CNumb,sizeof(int))) <=0)
		return FALSE;
	while(i < nCount)
	{
		if(m_list[i].nNumb == CNumb)
		{
			pSocka->Send(&i,sizeof(int));
			return TRUE;
		}
		++i;
	}
	int NULLL = -1;
	pSocka->Send(&NULLL,4);
	return TRUE;
}

void CStudents::Save()
{
	FILE *fp = fopen("./stud.lv","w");
	if(!fp)
		return;
	int nCount = m_list.size();
	int i = 0;
	while(i < nCount)
	{
		fwrite(&m_list[i],1,sizeof(Stud),fp);
		++i;
	}
	fclose(fp);
}

void CStudents::Load()
{
	FILE *fp = fopen("./stud.lv","r");
	if(!fp)
		return;
	Stud data;
	while( (fread(&data,1,sizeof(Stud),fp)) >0 )
		m_list.push_back(data);
	fclose(fp);
}



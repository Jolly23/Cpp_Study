// VVVͨѶSock��.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SockJolly.h"
#include <process.h>
#include <iostream>
using namespace std;

void theProc(void *p)
{
	SockJolly *pSocka = (SockJolly*)p;
	char sInfo[256];
	int  nSizeInfo;

	while(( nSizeInfo = pSocka->Receive(sInfo,sizeof(sInfo)-1)) > 0)
	{
		sInfo[nSizeInfo] = '\0';
		cout << sInfo << endl;	
	}
	delete pSocka;
}

int main(int argc, char* argv[])
{
	SockJolly sock;
	if(sock.Create(10150))
		cout << "�󶨶˿ڳɹ���" << endl;
	else
		cout << "�󶨶˿�ʧ�� Error=" << WSAGetLastError() << endl;
/*************************************************************************/
	sock.Listen();
	char sIP[20];
	UINT nPort;							//�������������õı���������
/*************************************************************************/
	SockJolly *pSocka = new SockJolly;
	while(sock.Accept(*pSocka,sIP,&nPort))
	{
		cout << "�ͻ��˽���! IP=" << sIP << "\t�˿�=" << nPort << endl;
		_beginthread(theProc,0,pSocka);
	}

	return 0;
}

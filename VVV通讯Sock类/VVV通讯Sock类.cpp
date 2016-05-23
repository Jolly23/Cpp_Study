// VVV通讯Sock类.cpp : Defines the entry point for the console application.
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
		cout << "绑定端口成功！" << endl;
	else
		cout << "绑定端口失败 Error=" << WSAGetLastError() << endl;
/*************************************************************************/
	sock.Listen();
	char sIP[20];
	UINT nPort;							//接收数据所采用的变量定义区
/*************************************************************************/
	SockJolly *pSocka = new SockJolly;
	while(sock.Accept(*pSocka,sIP,&nPort))
	{
		cout << "客户端接入! IP=" << sIP << "\t端口=" << nPort << endl;
		_beginthread(theProc,0,pSocka);
	}

	return 0;
}

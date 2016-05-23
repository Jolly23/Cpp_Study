// UDP_Server使用CSocket类.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <afxsock.h>
#include <iostream>
using namespace std;

const int PORT = 49152;
int main(int argc, char* argv[])
{
	WSADATA wd;
	WSAStartup(0x0202,&wd);
	CSocket sock;
	BOOL b = sock.Create(PORT,SOCK_DGRAM);
	if(!b){
		cout << "Creat函数错误：" << WSAGetLastError() << endl;
		return -1;
	}
	CString szIP;
	UINT nPort;
	char sAccept[1024];
	cout << "服务器" << endl;
	int nRes;
	while(( nRes = sock.ReceiveFrom(sAccept,sizeof(sAccept)-1,szIP,nPort)) > 0)
	{
		sAccept[nRes] = '\0';
		cout << szIP << " - " << nPort << ": " << sAccept << endl;
	}


	return 0;
}

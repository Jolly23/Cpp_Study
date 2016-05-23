// CSocket ¿‡.cpp : Defines the entry point for the console application.
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
		cout << "Creat∫Ø ˝¥ÌŒÛ£∫" << WSAGetLastError() << endl;
		return -1;
	}


	return 0;
}

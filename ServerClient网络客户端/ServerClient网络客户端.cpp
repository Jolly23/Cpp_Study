// ServerClient����ͻ���.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <winsock2.h>
#include <process.h>
#include <iostream>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
//TCP
const int PORT = 10150;

void main()
{
	/////////////////////////////////////////////////////////////////////
	//Step1:
	WSADATA wd;
	WSAStartup(0x0202,&wd);
	/////////////////////////////////////////////////////////////////////
	//Step2:
	SOCKET sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock == INVALID_SOCKET){
		cout << "����SOCKETʧ�ܣ��������=" << WSAGetLastError() << endl;
		return;
	}
	/////////////////////////////////////////////////////////////////////
	//Step3:
	sockaddr_in sa = {AF_INET};
	int nLen = sizeof(sa);
	int nRes = bind(sock,(sockaddr*)&sa,sizeof(sa));
	if(nRes == SOCKET_ERROR){
		cout << "bind����ʧ�ܣ��������=" << WSAGetLastError() << endl;
		return;
	}
	/////////////////////////////////////////////////////////////////////
	//Step4:
	char ToIP[20];
	cout << "������Ҫ���ӵķ�����IP��" ;
	cin  >> ToIP;
	sa.sin_addr.S_un.S_addr = inet_addr(ToIP);
	sa.sin_port = htons(PORT);
	nRes = connect(sock,(sockaddr*)&sa,sizeof(sa));
	if(nRes == SOCKET_ERROR){
		cout << "���ӷ�����ʧ�ܣ��������=" << WSAGetLastError() << endl;
		return;
	}
	/////////////////////////////////////////////////////////////////////
	//Step5:
	//���������ӳɹ�����ʼ��������
	char sSend[256];
	while(true)
	{
		fflush(stdin);
		cout << "�����뷢�����ݣ�";
		gets(sSend);
		send(sock,sSend,strlen(sSend)+1,0);
	}
	system("pause");
}

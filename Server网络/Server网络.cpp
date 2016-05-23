// Server����.cpp : Defines the entry point for the console application.
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
	sockaddr_in sa = {AF_INET,htons(PORT)};
	int nLen = sizeof(sa);
	int nRes = bind(sock,(sockaddr*)&sa,sizeof(sa));
	if(nRes == SOCKET_ERROR){
		cout << "bind����ʧ�ܣ��������=" << WSAGetLastError() << endl;
		return;
	}
	/////////////////////////////////////////////////////////////////////
	//Step4:
	listen(sock,5);
	SOCKET socka = accept(sock,(sockaddr*)&sa,&nLen);	//�շ�����3
	if(socka == INVALID_SOCKET){
		cout << "Accept�������󣬴������=" << WSAGetLastError() << endl;
		return;
	}
	//���������
	cout << "�������ӽ�����" << inet_ntoa(sa.sin_addr) << "��" << htons(sa.sin_port) << endl;
	char sAccept[1024];
	while( (nRes = recv(socka,sAccept,sizeof(sAccept)-1,0)) > 0)
	{
		sAccept[nRes] = '\0';
		cout << sAccept << endl;
	}
	if(WSAGetLastError() == 10054)
		cout << "�Է��ѶϿ����ӣ�" << endl;
	system("pause");
}

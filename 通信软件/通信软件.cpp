// ͨ�����.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <winsock2.h>
#include <process.h>
#include <iostream>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

//unsigned long _beginthread( void( __cdecl *start_address )( void * ), unsigned stack_size, void *arglist );
const int PORT = 8008;

SOCKET sock;

void RecvMain(void *pSock)		//���߳̽��ն�
{
	//���գ�
	SOCKET sock = (SOCKET)pSock;
	sockaddr_in sfrom = {0};
	int nLen = sizeof(sfrom);
	char GetString[256];
	int i = 1;
	while(true)
	{
		recvfrom(sock,GetString,sizeof(GetString),0,(sockaddr*)&sfrom,&nLen);
		cout << "����" << i++ << ": ���ͷ�IP:" << inet_ntoa(sfrom.sin_addr) 
			 <<"�˿ڣ�" << htons(sfrom.sin_port) << ": " << GetString << endl;
	}
}

int main(int argc, char* argv[])
{
	WSADATA wd;
	int n = WSAStartup(0x0202,&wd);		//����
	sock = socket(AF_INET,SOCK_DGRAM,0);
/////////////////////////////////////////////////////////////////////
	if(sock == INVALID_SOCKET)
	{
		cout << "SOCKET�׽��ִ���ʧ�ܣ�" << endl;
		cout << "�������=" << WSAGetLastError() << endl;
		return -1;
	}

/////////////////////////////////////////////////////////////////////
	sockaddr_in sa = {AF_INET,htons(PORT)};//{AF_INET,PORT};		
	//��ַ��Ϣ const struct sockaddr FAR*  name
	//�ͻ��ˣ����Ͷˣ� ���Բ��󶨷��Ͷ˿ڣ�PORT����д0��д
	sockaddr_in sself = {0};

	int sLen = sizeof(sself);

	n = bind (sock,(sockaddr*)&sa,sizeof(sa));
	if(n == SOCKET_ERROR)
	{
		cout << "Bind�󶨶˿�ʧ�ܣ�" << endl;
		cout << "�������=" << WSAGetLastError() << endl;
		return -1;
	}

/////////////////////////////////////////////////////////////////////
	_beginthread(RecvMain,1024*1024,(void*)sock);				//�������߳̽��ն�
/////////////////////////////////////////////////////////////////////

	//���Ͷ�!!
	n = getsockname(sock,(sockaddr*)&sself,&sLen);		//�ɻ�ȡ�˿�
	cout << "����IP = " << inet_ntoa(sself.sin_addr) << "\t�����˿� = " << htons(sself.sin_port) << endl;
	
	int ToPort = 0;
	char ToIP[20] = {0};
	cout << "������Է�IP��";
	cin  >> ToIP;

	sockaddr_in SATO = {AF_INET,htons(PORT)};
	SATO.sin_addr.S_un.S_addr = inet_addr(ToIP);
	char GetString[256];
	while(true)
	{
		cout << "������Ҫ���͵����ݣ�" ;
		gets(GetString);
		sendto(sock,GetString,strlen(GetString)+1,0,(sockaddr*)&SATO,sizeof(SATO));
		Sleep(16);
	}
/////////////////////////////////////////////////////////////////////
	return 0;
}
//Ŀ��IP
//10.54.1.251
//10.0.2.15

//char my_ip[13];
//strcpy(my_ip,inet_ntoa(user_addr.sin_addr));  
//printf("my_ip:%s\n",inet_ntoa(user_addr.sin_addr)); 
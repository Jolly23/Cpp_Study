// SockJollyEx.cpp: implementation of the SockJollyEx class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SockJollyEx.h"
#include <windows.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
const int ServerPort = 10150;
SockJollyEx::SockJollyEx()
{
 
}

SockJollyEx::~SockJollyEx()
{
	this->Close();
}

bool SockJollyEx::Start()
{
	int nRes;
	nRes = this->Create();
	if(nRes == 0){
		std::cout << "ÍøÂçÁ¬½ÓÊ§°Ü£¬´íÎó´úÂë£º" << WSAGetLastError() << std::endl;
		Sleep(3000);
		return false;
	}
	
	nRes = this->Connect("10.0.2.15",ServerPort);
	if(!nRes){
		std::cout << "ÍøÂçÁ¬½ÓÊ§°Ü£¬´íÎó´úÂë£º" << WSAGetLastError() << std::endl;
		Sleep(3000);
		return false;
	}
	return true;
}

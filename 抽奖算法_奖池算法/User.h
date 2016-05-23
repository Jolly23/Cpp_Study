// User.h: interface for the CUser class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_USER_H__F6A3EBD7_EFAA_41F6_9D7B_F12280CC5E50__INCLUDED_)
#define AFX_USER_H__F6A3EBD7_EFAA_41F6_9D7B_F12280CC5E50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Lucky.h"

struct User
{
	char cQQNumb[12];
	char cQQName[20];
	char cPassword[32];
	double lfPay;
	unsigned int unUserlevel;
	unsigned int unPayTimes;
};

class CUser  
{
	CLucky UserL;	//³é½±Ò³Ãæ
	bool CheckOccupied(char QQNumb[],size_t Count);
public:
	void Signup();
	void Login();
	void Default();
	CUser();
	~CUser();
private:
	void Login(User *pLogin);
};

#endif // !defined(AFX_USER_H__F6A3EBD7_EFAA_41F6_9D7B_F12280CC5E50__INCLUDED_)

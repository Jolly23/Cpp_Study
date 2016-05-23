// User.cpp: implementation of the CUser class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "User.h"
#include <vector>
#include <iostream>
using namespace std;
vector<User> UserList;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
enum{low = 3557,mid,high };

CUser::CUser()
{

}

CUser::~CUser()
{

}

void CUser::Login()
{
	User *pLogin = new User;
	cout << "请输入QQ号码：" ;
	cin  >> pLogin->cQQNumb;
	cout << endl << "请输入密码：" ;
	cin  >> pLogin->cPassword;
	Login(pLogin);
	return;
}

void CUser::Signup()
{
	char NewQQNumb[12];
	cout << "请输入QQ号码：" ;
	cin  >> NewQQNumb;
	if( CheckOccupied(NewQQNumb,sizeof(NewQQNumb)) == false)
	{	
		cout << endl << "此号码已被使用！" << endl;
		system("pause");
		return;
	}

	User *pNew = new User;
	strcpy(pNew-> cQQNumb, NewQQNumb);
	cout << endl << "请设置名字：";
	cin  >> pNew-> cQQName;
	cout << endl << "请设置密码：";
	cin  >> pNew-> cPassword;
	pNew-> lfPay = 0.0;
	pNew-> unUserlevel = low;
	pNew-> unPayTimes = 0;
	UserList.push_back(*pNew);
	return;
}
/*
	char cQQNumb[12];
	char cQQName[20];
	char cPassword[32];
	double lfPay;
	unsigned int unUserlevel;
	unsigned int unPayTimes;
*/

bool CUser::CheckOccupied(char QQNumb[],size_t Count)
{
	int i = 0;
	while(i < UserList.size())
	{
		if( strcmp(UserList[i].cQQName, QQNumb) == 0 )
			return false;
		++i;
	}

	return true;
}

void CUser::Default()
{
	int i = 0;
	char LSQQNumb[10][12] = {"10001","10002","10003","10004","10005","10006","10007","10008","10009","10010"};
	char LSQQName[10][20] = {"zhaolei","dongbaoqi","lizhogngan","liaolongfei","wuhuanjing",
							"wudexin","xuke","wangbo","liujingdong","linshouzheng"};
	while(i < 10)
	{
		User *pLS = new User;
		strcpy(pLS->cQQNumb, LSQQNumb[i]);
		strcpy(pLS->cQQName, LSQQName[i]);
		strcpy(pLS->cPassword, "zhaolei");
		pLS-> lfPay = 0.0;
		pLS-> unUserlevel = low;
		pLS-> unPayTimes = 0;
		UserList.push_back(*pLS);
		++i;
	}
}


void CUser::Login(User *pLogin)
{
	int i = 0;
	User &pL = UserList[0]; //初始化引用变量pL
	while(i < UserList.size())
	{
		pL = UserList[i];
		if(strcmp(pL.cQQNumb,pLogin->cQQNumb) == 0)
			break;
		++i;
	}
	if(strcmp(pL.cQQNumb,pLogin->cQQNumb) == 0)
	{
		//账号验证成功
		if( strcmp(pLogin->cPassword, pL.cPassword) == 0 )
		{
			cout << "登陆成功！" << endl;
			UserL.Menu();	//抽奖页面
			system("pause");
			return;
		}
	}
	else
	{
		cout << "您输入的账号或密码有误！"<< endl;
		system("pause");
		return;
	}
}

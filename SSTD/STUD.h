// STUD.h: interface for the STUD class.
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <process.h>
#include <conio.h>
#include <string.h>

#if !defined(AFX_STUD_H__21755B2C_87D1_4030_9029_9766D74EB69B__INCLUDED_)
#define AFX_STUD_H__21755B2C_87D1_4030_9029_9766D74EB69B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


using namespace std;

struct SSTU
{
	int   nNumb;
	char  sName[20];
	float fMath;
};
struct SNode
{
	SSTU data;
	SNode *pNext;
};

class STUD  
{
	SNode *g_pHead ;
	void Save()												;		//保存数据
	void Version()											;		//显示版本号
	void MenuDispose(char Select)							;		//菜单选项处理
	void Print()											;		//显示数据
	void Insert()											;		//添加数据
	int	 CheckNumb(int ls)									;		//检查输入数据学号是否重复
	void InsertDispose(SSTU DATA)							;		//添加数据处理
	void SearchMenu()										;		//查找数据
	void ModifyMenu()										;		//修改数据
	void ModifyMenu2(SNode* p)								;		//修改数据菜单：修改项目选择
	void DeleteMenu()										;		//删除数据
	void SayByeToUser()										;		//退出程序
	SNode* SearchByName()									;		//通过姓名搜索
	SNode* SearchByNumb()									;		//通过学号搜索
	void ModifyNumb(SNode* p)								;		//修改学号
	void ModifyName(SNode* p)								;		//修改姓名
	void ModifyMath(SNode* p)								;		//修改成绩
	SNode* FindByNumbDispose(int SearchNumb)				;		//通过学号搜索处理，返回值为地址
	SNode* FindByNameDispose(char SearchName[20])			;		//通过姓名搜索处理，返回值为地址
	void DeleteFindByName()									;		//通过姓名查找并删除
	void DeleteFindByNumb()									;		//通过学号查找并删除
	void DeleteAllApprove()									;		//清空全部管理员密码验证	
	int  DeleteAllDispose()									;		//执行清空全部
	void SortByWhat( int (*SortBy) (SNode *p1,SNode *p2) )	;		//通过学号排序
	char BrowseMenu()										;		//浏览数据菜单
	int  DATASum()											;		//统计数据总数
	void DataAnalyse()										;		//数据分析

public:
	//接口函数
	STUD();
	virtual ~STUD();
	void Load()												;		//加载存档（没有存档则创建）
	void Menu()												;		//用户菜单

};

#endif // !defined(AFX_STUD_H__21755B2C_87D1_4030_9029_9766D74EB69B__INCLUDED_)

int SortByNumb(SNode *p1,SNode *p2);
int SortByName(SNode *p1,SNode *p2);
int SortByMath(SNode *p1,SNode *p2);
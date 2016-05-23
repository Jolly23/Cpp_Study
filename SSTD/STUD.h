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
	void Save()												;		//��������
	void Version()											;		//��ʾ�汾��
	void MenuDispose(char Select)							;		//�˵�ѡ���
	void Print()											;		//��ʾ����
	void Insert()											;		//�������
	int	 CheckNumb(int ls)									;		//�����������ѧ���Ƿ��ظ�
	void InsertDispose(SSTU DATA)							;		//������ݴ���
	void SearchMenu()										;		//��������
	void ModifyMenu()										;		//�޸�����
	void ModifyMenu2(SNode* p)								;		//�޸����ݲ˵����޸���Ŀѡ��
	void DeleteMenu()										;		//ɾ������
	void SayByeToUser()										;		//�˳�����
	SNode* SearchByName()									;		//ͨ����������
	SNode* SearchByNumb()									;		//ͨ��ѧ������
	void ModifyNumb(SNode* p)								;		//�޸�ѧ��
	void ModifyName(SNode* p)								;		//�޸�����
	void ModifyMath(SNode* p)								;		//�޸ĳɼ�
	SNode* FindByNumbDispose(int SearchNumb)				;		//ͨ��ѧ��������������ֵΪ��ַ
	SNode* FindByNameDispose(char SearchName[20])			;		//ͨ������������������ֵΪ��ַ
	void DeleteFindByName()									;		//ͨ���������Ҳ�ɾ��
	void DeleteFindByNumb()									;		//ͨ��ѧ�Ų��Ҳ�ɾ��
	void DeleteAllApprove()									;		//���ȫ������Ա������֤	
	int  DeleteAllDispose()									;		//ִ�����ȫ��
	void SortByWhat( int (*SortBy) (SNode *p1,SNode *p2) )	;		//ͨ��ѧ������
	char BrowseMenu()										;		//������ݲ˵�
	int  DATASum()											;		//ͳ����������
	void DataAnalyse()										;		//���ݷ���

public:
	//�ӿں���
	STUD();
	virtual ~STUD();
	void Load()												;		//���ش浵��û�д浵�򴴽���
	void Menu()												;		//�û��˵�

};

#endif // !defined(AFX_STUD_H__21755B2C_87D1_4030_9029_9766D74EB69B__INCLUDED_)

int SortByNumb(SNode *p1,SNode *p2);
int SortByName(SNode *p1,SNode *p2);
int SortByMath(SNode *p1,SNode *p2);
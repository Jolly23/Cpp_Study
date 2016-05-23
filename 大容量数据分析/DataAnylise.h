// DataAnylise.h: interface for the CDataAnylise class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATAANYLISE_H__CCE38A7F_E5AF_4E86_AD0F_DAAF5278BBE0__INCLUDED_)
#define AFX_DATAANYLISE_H__CCE38A7F_E5AF_4E86_AD0F_DAAF5278BBE0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDataAnylise  
{
	int Width ;		//���
	int OSMax ;		//����
	unsigned int MinMax[2]	;
	unsigned int Times		;	//�ܲ�������
	unsigned int OldTimes	;	//��¼�ϴβ�������
	unsigned int Success	;	//�����������
	unsigned int OSTimes	;	//������ż�¼
	char MSel ;		//1����Χ�����ȡ��ģʽ�� 2����Χ��ȡ�м���ģʽ
	unsigned int TimesMin ;	//��С�������ô���
	unsigned int TimesMax ;	//���������ô���
	unsigned int TimesOne ; //���������н�����ò²����
	
	void OS();
	int RandNumb();
	int RandNumb(int Min,int Max);
	bool Compare(int ComputerNumb, int ComputerGuess) ;
	
public:
	void OSMain();
	CDataAnylise();
	virtual ~CDataAnylise();
};

#endif // !defined(AFX_DATAANYLISE_H__CCE38A7F_E5AF_4E86_AD0F_DAAF5278BBE0__INCLUDED_)

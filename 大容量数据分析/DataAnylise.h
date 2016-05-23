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
	int Width ;		//跨度
	int OSMax ;		//样本
	unsigned int MinMax[2]	;
	unsigned int Times		;	//总猜数次数
	unsigned int OldTimes	;	//记录上次猜数次数
	unsigned int Success	;	//总完成样本数
	unsigned int OSTimes	;	//样本序号记录
	char MSel ;		//1：范围内随机取数模式。 2：范围内取中间数模式
	unsigned int TimesMin ;	//最小猜中所用次数
	unsigned int TimesMax ;	//最大猜中所用次数
	unsigned int TimesOne ; //单样本猜中结果所用猜测次数
	
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

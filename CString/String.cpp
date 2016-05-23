// String.cpp: implementation of the CString class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "String.h"
#include <string.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CString::CString()
{
	this ->m_pData = NULL;
	this ->m_nLength = 0;
}

CString::~CString()
{
	if(this ->m_pData)
		delete []this ->m_pData;
}

CString::CString(const char* p)
{
	m_nLength = strlen(p);
	m_pData = new char[m_nLength+1];
	strcpy(m_pData,p);
}

CString::CString( const CString& stringSrc )	//拷贝构造(深拷贝)
{
	m_nLength = stringSrc.m_nLength;
	m_pData = new char[m_nLength+1];
	strcpy(m_pData,stringSrc.m_pData);
}	//拷贝构造发生的条件是：当用一个已有的对象，作为初始化数据的一个新对象时

CString &CString::operator +=(const char *p)
{
	m_nLength += strlen(p);
	char *pNew = new char[m_nLength+1];

//	strcpy(pNew,this->m_pData);
//	strcat(pNew,p);							
//  以上写法许多循环strlen(原m_pData)次
	char *p1 = pNew, *p2 = m_pData;
	while(*p1 = *p2)
		++p1, ++p2;
	while(*p1 = *p)
		++p1, ++p;
//  此写法最简
	delete []m_pData;
	this ->m_pData = pNew;
	this ->m_pData = pNew;

	return *this;
}

CString& CString::operator+=(  const CString& str)	//删除已有文字的堆空间，重新分配
{
	m_nLength += str.m_nLength;
	char *pNew = new char[m_nLength+1];

	strcpy(pNew , this ->m_pData);
	strcat(pNew , str.m_pData);

	delete []this ->m_pData;
	this ->m_pData = pNew;
	this ->m_pData = pNew;

	return *this;
}

CString::CString( char ch, int nRepeat /* = 1 */ )	//串内有n个ch字符
{
	this ->m_pData = new char[nRepeat+1];
	this ->m_nLength = nRepeat ;
	this ->m_pData[nRepeat] = '\0';

	while(nRepeat--)
		this->m_pData[nRepeat] = ch;
}

CString::CString(const char* cstr,int nLength)	//根据字符串常量的一部分
{
	this ->m_nLength = strlen(cstr);
	m_nLength = m_nLength < nLength ? m_nLength : nLength;
	this ->m_pData   = new char[m_nLength+1]; 
	int i = 0;
	while(i < m_nLength)
		m_pData[i] = cstr[i++];
	this ->m_pData[i] = '\0';
}

CString &CString::operator=(const char* cstr)	//删除已有文字的堆空间，重新分配
{
	this ->m_nLength = strlen(cstr);
	delete []this->m_pData;
	this ->m_pData = new char[m_nLength+1];
	strcpy(this ->m_pData , cstr);
	return *this;
}

CString& CString::operator=(const CString &str)	//删除已有文字的堆空间，重新分配
{
	this ->m_nLength = str.m_nLength;
	delete []this->m_pData;
	this ->m_pData = new char[m_nLength+1];
	strcpy(this ->m_pData,str.m_pData);
	return *this;		
}

CString CString::operator+(  const char* pszSrc) const	//来源不改变，返回一个对象
{
	CString Res;
	Res.m_nLength = this ->m_nLength + strlen(pszSrc);
	Res.m_pData   = new char[Res.m_nLength+1];
	strcpy(Res.m_pData , this ->m_pData);
	strcat(Res.m_pData , pszSrc);

	return Res;
}

CString CString::operator+(  const CString& str) const	//来源不改变，返回一个对象
{
	CString Res;
	Res.m_nLength = this ->m_nLength + str.m_nLength;
	Res.m_pData   = new char[Res.m_nLength+1];
	strcpy(Res.m_pData , this ->m_pData);
	strcat(Res.m_pData , str.m_pData);

	return Res;
}

bool operator==(const CString& str1,const CString& str2) 
{	return strcmp(str1.m_pData,str2.m_pData) == 0 ;	}
bool operator<(const CString& str1,  const CString& str2)
{	return strcmp(str1.m_pData,str2.m_pData) > 0 ;	}
bool operator>(const CString& str1,  const CString& str2) 
{	return strcmp(str1.m_pData,str2.m_pData) < 0 ;	}
bool operator!=(const CString& str1,const CString& str2) 
{	return strcmp(str1.m_pData,str2.m_pData) != 0 ;	}

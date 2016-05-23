// String.cpp: implementation of the CString class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "String.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
bool operator!=(const CString& str1,const CString& str2) 
{	return strcmp(str1 ,str2) != 0;	 }

bool operator==(const CString& str1,const CString& str2) 
{	return strcmp(str1 ,str2) == 0;	 }

bool operator<(const CString& str1, const CString& str2) 
{	return strcmp(str1 ,str2) < 0;	 }

bool operator>(const CString& str1,  const CString& str2)
{	return strcmp(str1 ,str2) > 0;	 }

CString::CString()
{
	m_pData = new char(0);
	//m_pData = new char;
	//*m_pData = 0;
	m_nLength = 0;
}

CString::~CString()
{
	this->m_nLength = 0;
	delete []m_pData;
}

CString::CString( const CString& stringSrc )	//拷贝构造
{
	this->m_nLength = stringSrc.m_nLength ;
	m_pData = new char[m_nLength+1];
	strcpy(this->m_pData,stringSrc.m_pData);
}

CString::CString( const char* lpsz )		//根据字符串常量初始化
{
	this->m_nLength = strlen(lpsz);
	m_pData = new char[m_nLength+1];
	strcpy(this->m_pData,lpsz);
}

CString::CString( char ch, int nRepeat)	//串内有n个ch字符
{
	this->m_nLength = nRepeat;
	int i = 0;
	m_pData = new char[nRepeat+1];
	m_pData[nRepeat] = '\0';
	while(nRepeat--)
		m_pData[nRepeat] = ch;
}

CString::CString(const char* cstr,int nLength)	//根据字符串常量的一部分
{
	int nLen = strlen(cstr) < nLength ? strlen(cstr) : nLength;
	this->m_nLength = nLen;
	m_pData = new char[nLen+1];
	m_pData[nLen] = '\0';
	while(nLen--)
		m_pData[nLen] = cstr[nLen];
}

CString& CString::operator=(const char* cstr) 	//删除已有文字的堆空间，重新分配
{
	delete []m_pData;
	m_nLength = strlen(cstr);
	m_pData = new char[m_nLength+1];
	strcpy(m_pData,cstr);
	return *this;
}

CString& CString::operator=(const CString &str)	//删除已有文字的堆空间，重新分配
{
	delete []m_pData;
	m_nLength = str.m_nLength;
	m_pData = new char[m_nLength+1];
	strcpy(m_pData,str.m_pData);
	return *this;
}

CString& CString::operator+=(  const char* pszSrc)	//删除已有文字的堆空间，重新分配
{
	this->m_nLength += strlen(pszSrc);
	char* pNew = new char[m_nLength+1];
	int i = 0,n = 0;
	while(i < strlen(m_pData))
		pNew[i] = m_pData[i++];
	
	while(i < this->m_nLength )
		pNew[i++] = pszSrc[n++];
	pNew[i] = '\0';
	delete []m_pData;
	m_pData = pNew;
	return *this;
}

CString& CString::operator+=(  const CString& pszSrc)	//删除已有文字的堆空间，重新分配
{
	this->m_nLength += pszSrc.m_nLength;
	char* pNew = new char[m_nLength+1];
	int i = 0,n = 0;
	while(i < strlen(m_pData))
		pNew[i] = m_pData[i++];
	while(i < this->m_nLength )
		pNew[i++] = pszSrc.m_pData[n++];
	pNew[i] = '\0';
	delete []m_pData;
	m_pData = pNew;
	return *this;
}

CString CString::operator+(  const char* pszSrc) const	//来源不改变，返回一个对象
{	
	CString str;
	str.m_nLength = this->m_nLength + strlen(pszSrc);
	str.m_pData = new char[str.m_nLength + 1];
	int i = 0,j = 0;
	while(i < this->m_nLength)
		str.m_pData[i] = this->m_pData[i++];
	while(j < strlen(pszSrc))
		str.m_pData[i++] = pszSrc[j++];
	return str;	
}

CString CString::operator+(  const CString& str) const	//来源不改变，返回一个对象
{	
	CString Str;
	Str.m_nLength = this->m_nLength + str.m_nLength;
	Str.m_pData = new char[Str.m_nLength + 1];
	int i = 0,j = 0;
	while(i < this->m_nLength)
		Str.m_pData[i] = this->m_pData[i++];
	while(j < str.m_nLength)
		Str.m_pData[i++] = str.m_pData[j++];
	return Str;		
}

CString CString::Mid( int nFirst, int nCount ) const
{
	CString str;
	if(nFirst < 0)
		nFirst = 0;
	if(nCount <= 0)
		return str;
	if(nFirst + nCount > this->m_nLength)
		nCount = this->m_nLength - nFirst;
	int nLen = nCount;
	str.m_pData = new char[nLen+1];
	str.m_nLength = nLen;
	str.m_pData[nLen] = '\0';
	while(nLen--)
		str.m_pData[nLen] = this->m_pData[nFirst + nLen];
	return str;
}

CString CString::Mid( int nFirst ) const
{	return Mid(nFirst,this->m_nLength - nFirst);	}

CString CString::Left( int nCount ) const
{	return Mid(0,nCount);	}

CString CString::Right( int nCount ) const
{	return Mid(this->m_nLength - nCount);	}

void CString::MakeUpper( )
{
	int nLen = this->m_nLength;
	while(nLen--)
		if( islower(this->m_pData[nLen]) )
			this->m_pData[nLen] = toupper(this->m_pData[nLen]);
		//只用一句话完成此功能： strupr(this->m_pData);
}

void CString::MakeLower( )
{
	int nLen = this->m_nLength;
	while(nLen--)
		if( isupper(this->m_pData[nLen]) )
			this->m_pData[nLen] = tolower(this->m_pData[nLen]);
		//只用一句话完成此功能： strlwr(this->m_pData);
}

void CString::MakeUpperLower()
{
	int nLen = this->m_nLength;
	while(nLen--)
	{
		if( isupper(this->m_pData[nLen]) )
			this->m_pData[nLen] = tolower(this->m_pData[nLen]);
		if( islower(this->m_pData[nLen]) )
			this->m_pData[nLen] = toupper(this->m_pData[nLen]);
	}
}

void CString::MakeReverse( )
{
	char *p = this->m_pData;
	char *q = this->m_pData + this->m_nLength - 1;
	char Tch;
	while(p < q)
	{
		Tch = *p;
		*p = *q;
		*q = Tch;
		++p;
		--q;
	}
}

int CString::Find( char ch, int nStart ) const
{
	if(nStart > this->m_nLength)
		return -1;

	int i = nStart;
	while(i < this->m_nLength)
	{
		if(this->m_pData[i] == ch)
			return i;
		++i;
	}
	return -1;
}

int CString::Find( const char* pstr, int nStart ) const
{
	int nLenStr = strlen(pstr);
	if(nStart > this->m_nLength - nLenStr)
		return -1;

	char *pSear = new char[nLenStr+1];
	int i = nStart;
	while(i <= this->m_nLength - nLenStr)
	{
		strcpy(pSear,(this->Mid(i,nLenStr)).m_pData);
		if(strcmp(pSear,pstr) == 0)
			return i;
		++i;
	}
	return -1;
}

int CString::ReverseFind( char ch ) const
{
	int nLen = this->m_nLength;
	while(nLen--)
		if(this->m_pData[nLen] == ch)
			return nLen;
		return -1;
}

int CString::Replace( char chOld, char chNew )
{
	int nLen = this->m_nLength;
	int Sum = 0;
	while(nLen--)
	{
		if(this->m_pData[nLen] == chOld)
		{
			this->m_pData[nLen] = chNew;
			Sum++;
		}
	}
	return Sum;
}
/*
int CString::Replace( const char* lpszOld, const char* lpszNew )
{
	int nLenOld = strlen(lpszOld);
	int nLenNew = strlen(lpszNew);
	int Sum = 0;
	int i = 0;
	int j = 0;
	int m = 0;
	int n = 0;
	do{
		char *lpSearch = new char[nLenOld+1];
		while(i <= this->m_nLength - nLenOld)
		{
			strcpy(lpSearch, ( this->Mid(i,nLenOld) ).m_pData);
			if(strcmp(lpSearch, lpszOld) == 0)
				break;
			++i;
		}
		if(i > this->m_nLength - nLenOld)
			return 0;
		char *pNew = new char[m_nLength - nLenOld + nLenNew + 1];
		while(m < i)
			pNew[m] = this->m_pData[m++];
		while(m < i + nLenNew)
			pNew[m++] = lpszNew[j++];
		while(m < strlen(pNew))
			pNew[m++] = this->m_pData[i + nLenOld + n++];
		delete []this->m_pData;
		this->m_nLength = strlen(pNew);
		m_pData = new char[strlen(pNew)+1];
		strcpy(this->m_pData , pNew);
		delete []pNew;
		Sum++;
	}while(i < this->m_nLength - nLenOld);
	return Sum;
}*/
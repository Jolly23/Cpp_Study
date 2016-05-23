// String.h: interface for the CString class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRING_H__DF8FA73F_964E_450E_B822_E579A44C7D26__INCLUDED_)
#define AFX_STRING_H__DF8FA73F_964E_450E_B822_E579A44C7D26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CString  
{
	char * m_pData;
	int m_nLength;

public:
	int GetLength(){return m_nLength;}

	CString( const CString& stringSrc );	//拷贝构造
	CString( const char* lpsz );		//根据字符串常量初始化
	CString( char ch, int nRepeat = 1  );	//串内有n个ch字符
	CString(const char* cstr,int nLength);	//根据字符串常量的一部分

	CString();
	~CString();

public:
	operator const char* (){return m_pData;}
	
	//单行函数放在头文件中，编译器自动使用Inline内联格式编译（节省入栈时间）：
	char operator []( int nIndex ) const	//获取串内上的某个字符
	{	return this ->m_pData[nIndex];	}

	CString& operator=(const char* cstr);	//删除已有文字的堆空间，重新分配
	CString& operator=(const CString &str);	//删除已有文字的堆空间，重新分配

	CString& operator+=(const char* pszSrc);	//删除已有文字的堆空间，重新分配
	CString& operator+=(const CString& str);	//删除已有文字的堆空间，重新分配

	CString operator+(  const char* pszSrc) const;	//来源不改变，返回一个对象
	CString operator+(  const CString& str) const;	//来源不改变，返回一个对象

friend bool operator!=(const CString& str1,const CString& str2) ;
friend bool operator==(const CString& str1,const CString& str2) ;
friend bool operator<(const CString& str1, const CString& str2) ;
friend bool operator>(const CString& str1,  const CString& str2) ;
};

#endif // !defined(AFX_STRING_H__DF8FA73F_964E_450E_B822_E579A44C7D26__INCLUDED_)

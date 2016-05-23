// String.h: interface for the CString class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRING_H__F402EC00_B343_488A_842A_24E9A7E9DDC3__INCLUDED_)
#define AFX_STRING_H__F402EC00_B343_488A_842A_24E9A7E9DDC3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CString  
{
public:	//以下是增强的CString功能函数：
	char * m_pData;
	int m_nLength;
	void Empty( )
	{
		delete []m_pData;
		m_pData = 0;
		m_nLength = 0;
	}
	bool IsEmpty( ) const
	{	return m_nLength == 0;	}

	CString Mid( int nFirst ) const;
	CString Mid( int nFirst, int nCount ) const;
	CString Left( int nCount ) const;
	CString Right( int nCount ) const;

	void MakeUpper( );
	void MakeLower( );
	void MakeReverse( );
	int Replace( char chOld, char chNew );
	int Replace( const char* lpszOld, const char* lpszNew );
	int Remove( char ch );
	int Insert( int nIndex, char ch );
	int Insert( int nIndex, const char* pstr );
	int Delete( int nIndex, int nCount = 1 );
	int Find( char ch, int nStart = 0 ) const;
	int Find( const char* pstr, int nStart = 0 ) const;
	int ReverseFind( char ch ) const;
	void TrimLeft( );
	void CString::TrimLeft( char chTarget );
	void CString::TrimLeft( const char* lpszTargets );
	void TrimRight( );
	void TrimRight( char chTarget );
	void TrimRight( const char* lpszTargets );
public:
	int GetLength(){return m_nLength;}//一定要准确

	CString( const CString& stringSrc );	//拷贝构造
	CString( const char* lpsz );		//根据字符串常量初始化
	CString( char ch, int nRepeat = 1);	//串内有n个ch字符
	CString(const char* cstr,int nLength);	//根据字符串常量的一部分

	CString(); //缺省构造
	~CString();
public:
	void MakeUpperLower();
	operator const char* () const
	{
		return m_pData;
	}
	//凡是单行函数放在头文件中，编译器会自动使用inline内联格式编译
	char operator []( int nIndex ) const	//获取串内上的某个字符
	{
		return m_pData[nIndex];
	}
	CString& operator=(const char* cstr) ;	//删除已有文字的堆空间，重新分配
	CString& operator=(const CString &str);	//删除已有文字的堆空间，重新分配

	CString& operator+=(  const char* pszSrc);	//删除已有文字的堆空间，重新分配
	CString& operator+=(  const CString& pszSrc);	//删除已有文字的堆空间，重新分配

	CString operator+(  const char* pszSrc) const;	//来源不改变，返回一个对象
	CString operator+(  const CString& str) const;	//来源不改变，返回一个对象

friend bool operator!=(const CString& str1,const CString& str2) ;
friend bool operator==(const CString& str1,const CString& str2) ;
friend bool operator<(const CString& str1, const CString& str2) ;
friend bool operator>(const CString& str1,  const CString& str2);
};

#endif // !defined(AFX_STRING_H__F402EC00_B343_488A_842A_24E9A7E9DDC3__INCLUDED_)

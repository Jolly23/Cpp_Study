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
public:	//��������ǿ��CString���ܺ�����
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
	int GetLength(){return m_nLength;}//һ��Ҫ׼ȷ

	CString( const CString& stringSrc );	//��������
	CString( const char* lpsz );		//�����ַ���������ʼ��
	CString( char ch, int nRepeat = 1);	//������n��ch�ַ�
	CString(const char* cstr,int nLength);	//�����ַ���������һ����

	CString(); //ȱʡ����
	~CString();
public:
	void MakeUpperLower();
	operator const char* () const
	{
		return m_pData;
	}
	//���ǵ��к�������ͷ�ļ��У����������Զ�ʹ��inline������ʽ����
	char operator []( int nIndex ) const	//��ȡ�����ϵ�ĳ���ַ�
	{
		return m_pData[nIndex];
	}
	CString& operator=(const char* cstr) ;	//ɾ���������ֵĶѿռ䣬���·���
	CString& operator=(const CString &str);	//ɾ���������ֵĶѿռ䣬���·���

	CString& operator+=(  const char* pszSrc);	//ɾ���������ֵĶѿռ䣬���·���
	CString& operator+=(  const CString& pszSrc);	//ɾ���������ֵĶѿռ䣬���·���

	CString operator+(  const char* pszSrc) const;	//��Դ���ı䣬����һ������
	CString operator+(  const CString& str) const;	//��Դ���ı䣬����һ������

friend bool operator!=(const CString& str1,const CString& str2) ;
friend bool operator==(const CString& str1,const CString& str2) ;
friend bool operator<(const CString& str1, const CString& str2) ;
friend bool operator>(const CString& str1,  const CString& str2);
};

#endif // !defined(AFX_STRING_H__F402EC00_B343_488A_842A_24E9A7E9DDC3__INCLUDED_)

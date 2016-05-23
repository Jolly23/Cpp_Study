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

	CString( const CString& stringSrc );	//��������
	CString( const char* lpsz );		//�����ַ���������ʼ��
	CString( char ch, int nRepeat = 1  );	//������n��ch�ַ�
	CString(const char* cstr,int nLength);	//�����ַ���������һ����

	CString();
	~CString();

public:
	operator const char* (){return m_pData;}
	
	//���к�������ͷ�ļ��У��������Զ�ʹ��Inline������ʽ���루��ʡ��ջʱ�䣩��
	char operator []( int nIndex ) const	//��ȡ�����ϵ�ĳ���ַ�
	{	return this ->m_pData[nIndex];	}

	CString& operator=(const char* cstr);	//ɾ���������ֵĶѿռ䣬���·���
	CString& operator=(const CString &str);	//ɾ���������ֵĶѿռ䣬���·���

	CString& operator+=(const char* pszSrc);	//ɾ���������ֵĶѿռ䣬���·���
	CString& operator+=(const CString& str);	//ɾ���������ֵĶѿռ䣬���·���

	CString operator+(  const char* pszSrc) const;	//��Դ���ı䣬����һ������
	CString operator+(  const CString& str) const;	//��Դ���ı䣬����һ������

friend bool operator!=(const CString& str1,const CString& str2) ;
friend bool operator==(const CString& str1,const CString& str2) ;
friend bool operator<(const CString& str1, const CString& str2) ;
friend bool operator>(const CString& str1,  const CString& str2) ;
};

#endif // !defined(AFX_STRING_H__DF8FA73F_964E_450E_B822_E579A44C7D26__INCLUDED_)

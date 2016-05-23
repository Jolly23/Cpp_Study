// Complex.h: interface for the CComplex class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPLEX_H__EDB9E59C_DABA_435F_92C7_E5343484042F__INCLUDED_)
#define AFX_COMPLEX_H__EDB9E59C_DABA_435F_92C7_E5343484042F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CTest;
class CComplex  
{
	int m_nReal;
	int m_nImag;
	friend void Test();
	friend CTest;
public:
	CComplex();
	virtual ~CComplex();

};

#endif // !defined(AFX_COMPLEX_H__EDB9E59C_DABA_435F_92C7_E5343484042F__INCLUDED_)

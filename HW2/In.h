// In.h: interface for the CIn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IN_H__B45A22F3_8E41_41BE_A726_7DF23F84085C__INCLUDED_)
#define AFX_IN_H__B45A22F3_8E41_41BE_A726_7DF23F84085C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CInput
{
public:
	CInput& operator>>(int &i);
	CInput& operator>>(char str[]);
	CInput& operator>>(short &i);
	CInput& operator>>(char &i);

}

#endif // !defined(AFX_IN_H__B45A22F3_8E41_41BE_A726_7DF23F84085C__INCLUDED_)

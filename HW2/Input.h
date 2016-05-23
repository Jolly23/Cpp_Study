// Input.h: interface for the CInput class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INPUT_H__9AB8A7BB_6E8E_4AFA_AB86_8FE009D1B53E__INCLUDED_)
#define AFX_INPUT_H__9AB8A7BB_6E8E_4AFA_AB86_8FE009D1B53E__INCLUDED_

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
	
	CInput& operator>>(long &i);
	CInput& operator>>(float &i);
	CInput& operator>>(double &i);
};

#endif // !defined(AFX_INPUT_H__9AB8A7BB_6E8E_4AFA_AB86_8FE009D1B53E__INCLUDED_)

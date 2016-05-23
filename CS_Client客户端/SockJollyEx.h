// SockJollyEx.h: interface for the SockJollyEx class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOCKJOLLYEX_H__CDDFFB93_046A_42EB_8CDE_DC1E812F25D6__INCLUDED_)
#define AFX_SOCKJOLLYEX_H__CDDFFB93_046A_42EB_8CDE_DC1E812F25D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SockJolly.h"

class SockJollyEx : public SockJolly  
{
public:
	bool Start();
	SockJollyEx();
	virtual ~SockJollyEx();

};

#endif // !defined(AFX_SOCKJOLLYEX_H__CDDFFB93_046A_42EB_8CDE_DC1E812F25D6__INCLUDED_)

// Input.cpp: implementation of the CInput class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Input.h"
#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CInput& CInput::operator>>(int &i)
{
	scanf("%d",&i);
	return *this;
}
CInput& CInput::operator>>(char str[])
{
	scanf("%s",str);
	return *this;
}
CInput& CInput::operator>>(short &i)
{
	scanf("%d",&i);
	return *this;
}
CInput& CInput::operator>>(char &i)
{
	scanf("%c",&i);
	return *this;
}

CInput& CInput::operator>>(long &i)
{
	scanf("%ld",&i);
	return *this;
}
CInput& CInput::operator>>(float &i)
{
	scanf("%f",&i);
	return *this;
}
CInput& CInput::operator>>(double &i)
{
	scanf("%lf",&i);
	return *this;
}

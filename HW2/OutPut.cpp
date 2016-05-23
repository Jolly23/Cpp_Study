// OutPut.cpp: implementation of the OutPut class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OutPut.h"
#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OutPut& OutPut::operator<<(int i)
{
	printf("%d",i);
	return *this;
}
OutPut& OutPut::operator<<(short s)
{
	printf("%c",s);
	return *this;
}
OutPut& OutPut::operator<<(char c)
{
	printf("%c",c);
	return *this;
}
OutPut& OutPut::operator<<(const char* str)
{
	printf(str);
	return *this;
}
OutPut& OutPut::operator<<(float f)
{
	printf("%f",f);
	return *this;
}
OutPut& OutPut::operator<<(double dl)
{
	printf("%lf",dl);
	return *this;
}
OutPut& OutPut::operator<<(void *p)
{
	printf("0x%p",p);
	return *this;
}
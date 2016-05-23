// OutPut.h: interface for the OutPut class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OUTPUT_H__DD9ABF38_FF69_42D7_8B94_24D3EDAA8A11__INCLUDED_)
#define AFX_OUTPUT_H__DD9ABF38_FF69_42D7_8B94_24D3EDAA8A11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class OutPut  
{
public:

	OutPut& operator<<(int i);
	OutPut& operator<<(short s);
	OutPut& operator<<(char c);
	OutPut& operator<<(const char* str);
	OutPut& operator<<(float f);
	OutPut& operator<<(double dl);
	OutPut& operator<<(void *p);

};

#endif // !defined(AFX_OUTPUT_H__DD9ABF38_FF69_42D7_8B94_24D3EDAA8A11__INCLUDED_)

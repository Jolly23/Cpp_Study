// HW.cpp : Defines the entry point for the console application.
//
/*
请写出以下复数类的+-%的5种运算符重载函数：
说明：实数和虚数的统称为复数，两个复数相加等价于实数与实数相加，虚数与虚数相加。
其他的算法也大致一样的。

  class CComplex
  {
  public:
  double m_fReal;//实数
  double m_fImag;//虚数
  CComplex()
  {
		m_fReal = m_fImag;
		};
		CComplex(double fReal, double fImag=0){
		m_fReal=fReal;
		m_fImag=fImag;
		}
		void Print()
		{
		cout << "复数：("<<m_fReal << ":" << m_fImag <<")"<<endl;
		}
		};	
		CComplex operator+(CComplex& c1 ,CComplex& c2)
		{
		CComplex c;
		c.m_fImag = c1.m_fImag+c2.m_fImag;
		c.m_fReal = c1.m_fReal + c2.m_fReal;
		return c;	
		}
		int main(int argc, char* argv[])
		{
		CComplex x1(88,11),x2(-8,-21);
		(x1+x2).Print();
		return 0;
		}
		2、不允许重载的运算符只有5个：
		.		(成员访问符)
		.*		(成员指针访问运算符)
		::		(域运算符)
		sizeof	(长度运算符)
		?:		(条件运算符号)
		除了这5个运算符对照C语言运算符优先级列表，全部可以都做成以上复数类的运算符重载函数。
		首先区分以下符号是双目还是单目运算符，再做成重载函数（注释好是单双目运算符）
		例如：+=  -=  *=  /=  %=  = 　>=  <  <= 　&=  ^=  |= == != 　<、<=、>、>= 前++ -- 后++ --
		
		  struct DATA 
		  {
		  int a;
		  int b;
		  };
		  DATA operator+(DATA a,DATA b)
		  {
		  DATA NewDATA;
		  NewDATA.a = a.a + b.a;
		  NewDATA.b = a.b + b.b;
		  return NewDATA;
		  }
		  int main(int argc, char* argv[])
		  {
		  DATA a = {9,5} , b = {5,6};
		  DATA New = a+b;
		  cout << New.a <<endl <<New.b <<endl;
		  return 0;
} */

#include "stdafx.h"
#include <iostream>
using namespace std;

class CComplex
{
public:
	double m_fReal;//实数
	double m_fImag;//虚数
	CComplex()
	{
		m_fReal = m_fImag;
	};
	CComplex(double fReal, double fImag=0)
	{
		m_fReal=fReal;
		m_fImag=fImag;
	}
	CComplex operator+ (CComplex b)
	{
		CComplex New;
		New.m_fImag = this->m_fImag + b.m_fImag;
		New.m_fReal = this->m_fReal + b.m_fReal;
		return New;
	}
	
	CComplex operator- ()
	{
		this->m_fImag = -this->m_fImag;
		return *this;
	}
	
	CComplex operator++ ()
	{
		this->m_fImag += 1;
		this->m_fReal += 1;
		return *this;
		//	CComplex New;
		//	New.m_fImag = a.m_fImag + 1;
		//	New.m_fReal = a.m_fReal + 1;
		//	return New;
	}
	
	bool operator== (const CComplex b)
	{
		return this->m_fImag == b.m_fImag  &&  this->m_fReal == b.m_fReal;
	}
	
	bool operator!= (const CComplex b)
	{	
		return this->m_fImag != b.m_fImag  ||  this->m_fReal != b.m_fReal;	
	}

	CComplex &operator= (const CComplex b)
	{
		memcpy(this,&b,sizeof(CComplex));
		return *this;
	}

	void Print()
	{
		cout << "复数：("<<m_fReal << ":" << m_fImag <<")"<<endl;
	}
};	




void main()
{
	CComplex x1(88,11),x2(-8,-21);
	(x1+x2).Print();
//	(-x1).Print();
//	if(x1 != x2)
//		(++x1).Print();
	CComplex New;
	New = x1;
	New.Print();
}
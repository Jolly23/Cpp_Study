// HW.cpp : Defines the entry point for the console application.
//
/*
��д�����¸������+-%��5����������غ�����
˵����ʵ����������ͳ��Ϊ����������������ӵȼ���ʵ����ʵ����ӣ�������������ӡ�
�������㷨Ҳ����һ���ġ�

  class CComplex
  {
  public:
  double m_fReal;//ʵ��
  double m_fImag;//����
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
		cout << "������("<<m_fReal << ":" << m_fImag <<")"<<endl;
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
		2�����������ص������ֻ��5����
		.		(��Ա���ʷ�)
		.*		(��Աָ����������)
		::		(�������)
		sizeof	(���������)
		?:		(�����������)
		������5�����������C������������ȼ��б�ȫ�����Զ��������ϸ��������������غ�����
		�����������·�����˫Ŀ���ǵ�Ŀ����������������غ�����ע�ͺ��ǵ�˫Ŀ�������
		���磺+=  -=  *=  /=  %=  = ��>=  <  <= ��&=  ^=  |= == != ��<��<=��>��>= ǰ++ -- ��++ --
		
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
	double m_fReal;//ʵ��
	double m_fImag;//����
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
		cout << "������("<<m_fReal << ":" << m_fImag <<")"<<endl;
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
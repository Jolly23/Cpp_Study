// SShape.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
struct SShape 
{//ͼ�λ���
	enum EType{SHAPE,RECT,CIRCLE,ELLIPSE};
	virtual EType GetType() const 
	{//���������з�������������ࣺRECT��CIRCLE��ELLIPSE
		return SHAPE;
	};
	virtual void Input()
	{//��������������뾶��߿�ȳ�Ա��Ϣ111
	
	}
	virtual void Print() const
	{//���������д�ӡ���뾶����߿����Ա��Ϣ
		
	}
	virtual double GetCircum() const 
	{//���������м���������͵��ܳ�
		return 0.0;
	}
	virtual double GetArea() const 
	{//���������м���������͵����
		return 0.0;
	}
};
struct SRect:public SShape
{//���Σ��߿�
	double fWidth,fHeight;
......................
//�����fWidth*fHeight
//�ܳ���(fWidth+fHeight)*2
};
struct SCircle:public SShape
{//Բ�Σ��뾶
	double fRadius; 
......................
//�����fRadius*fRadius*PI
//�ܳ���fRadius*2*PI
};
struct SEllipse:public SShape
{//��Բ:������
	double fLong,fShort;
......................
//�����PI*fLong*fShort
//�ܳ���2PI*fShort+4*(fLong-fShort)
};


int main(int argc, char* argv[])
{
	return 0;
}

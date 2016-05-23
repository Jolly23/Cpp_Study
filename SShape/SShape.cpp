// SShape.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
struct SShape 
{//图形基类
	enum EType{SHAPE,RECT,CIRCLE,ELLIPSE};
	virtual EType GetType() const 
	{//在派生类中返回派生类的种类：RECT或CIRCLE或ELLIPSE
		return SHAPE;
	};
	virtual void Input()
	{//在派生类中输入半径或高宽等成员信息111
	
	}
	virtual void Print() const
	{//在派生类中打印：半径、或高宽类成员信息
		
	}
	virtual double GetCircum() const 
	{//在派生类中计算出本类型的周长
		return 0.0;
	}
	virtual double GetArea() const 
	{//在派生类中计算出本类型的面积
		return 0.0;
	}
};
struct SRect:public SShape
{//矩形：高宽
	double fWidth,fHeight;
......................
//面积：fWidth*fHeight
//周长：(fWidth+fHeight)*2
};
struct SCircle:public SShape
{//圆形：半径
	double fRadius; 
......................
//面积：fRadius*fRadius*PI
//周长：fRadius*2*PI
};
struct SEllipse:public SShape
{//椭圆:长短轴
	double fLong,fShort;
......................
//面积：PI*fLong*fShort
//周长：2PI*fShort+4*(fLong-fShort)
};


int main(int argc, char* argv[])
{
	return 0;
}

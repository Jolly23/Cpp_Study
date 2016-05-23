// ShapeSum.cpp : Defines the entry point for the console application.
//
/*
1、虚函数程序架构开发：
a)SShape类是公共的图形基类，派生出矩形、正圆、椭圆等派生类；
b)参照课堂视频开发一个多种图形混合录入、打印和计算的软件工程；
c)循环显示菜单：录入和打印等选项。
d)每次录入将派生类的信息用基类指针保存在链表或动态数组中；
e)每次录入之后可以循环打印集合中的每个图形的基本信息和计算信息。
	包括：打印每个图形的高宽或半径等信息，获取该图形的周长和面积并打印；
f)最后在循环遍历结束之后统计出所有图形的种类和统计信息，例如：
	总共有8种图形：3个矩形、4个圆形、1个椭圆
	8种图形的周长总计：8888.55  面积总计：995.61
*/

#include "stdafx.h"
#include <conio.h>
#include <list>
#include <iostream>
using namespace std;
const double PI = 3.14;
struct SShape	// 成员函数后编写 = 0；变为纯虚类：不可构建对象
{//图形基类
	enum EType{SHAPE,RECT,CIRCLE,ELLIPSE,ROUNDRECT};
	virtual EType GetType() const = 0;
	virtual void Input() = 0;
	virtual void Print() const = 0;
	virtual double GetCircum() const  = 0;
	virtual double GetArea() const  = 0;
};
struct SRect:public SShape
{//矩形：高宽
	double fWidth,fHeight;
	virtual EType GetType() const 
	{
		return RECT;
	}
	virtual void Input()
	{
		cout << "请输入矩形的宽 和 高（空格间隔）：";
		cin  >> fWidth >> fHeight;
	}
	virtual void Print() const
	{
		cout << "矩形： 宽=" << fWidth << "\t高=" << fHeight << endl;
	}
	virtual double GetCircum() const 
	{
		return (fWidth + fHeight) * 2;
	}
	virtual double GetArea() const 
	{
		return fWidth * fHeight;
	}
};
struct SCircle:public SShape
{//圆形：半径
	double fRadius; 
	virtual EType GetType() const 
	{
		return CIRCLE;
	}
	virtual void Input()
	{
		cout << "请输入圆形半径：" ;
		cin  >> fRadius;
	}
	virtual void Print() const
	{
		cout << "圆形： 半径=" << fRadius << endl;		
	}
	virtual double GetCircum() const 
	{
		return 2*PI*fRadius;
	}
	virtual double GetArea() const 
	{
		return PI*fRadius*fRadius;
	}
};
struct SRoundRect:public SShape
{//圆角矩形：高度 宽度 圆角半径
	double fHight,fWidth,fRadius; 
	virtual EType GetType() const 
	{
		return ROUNDRECT;
	}
	virtual void Input()
	{
		cout << "请输入圆角矩形的 高度 宽度 圆角半径：" ;
		cin  >> fHight >> fWidth >> fRadius;
	}
	virtual void Print() const
	{
		cout << "圆角矩形： 高度=" << fHight << "\t宽度=" << fWidth << "\圆角半径=" << fRadius << endl;		
	}
	virtual double GetCircum() const 
	{
		return ((fHight-2*fRadius) + (fWidth-2*fRadius))*2 + 2*PI*fRadius;
	}
	virtual double GetArea() const 
	{   
		return fHight*fWidth - (fRadius*2*fRadius*2 - PI*fRadius*fRadius);
	}
};
struct SEllipse:public SShape
{//椭圆:长短轴
	double fLong,fShort;
	virtual EType GetType() const 
	{
		return ELLIPSE;
	}
	virtual void Input()
	{
		cout << "请输入椭圆形长轴/短轴（空格间隔）：";
		cin  >> fLong >> fShort;
		if(fLong < fShort)
		{
			double t = fLong;
			fLong = fShort;
			fShort = t;
		}
	}
	virtual void Print() const
	{
		cout << "椭圆形： 长轴=" << fLong << "\t短轴=" << fShort << endl;	
	}
	virtual double GetCircum() const 
	{
		return PI*fLong*fShort;
	}
	virtual double GetArea() const 
	{
		return 2*PI*fShort + 4*(fLong-fShort);
	}
	//面积：PI*fLong*fShort
	//周长：2PI*fShort+4*(fLong-fShort)
};

list<SShape*> g_list;
int Menu();
void Input();
void Print();
int main(int argc, char* argv[])
{
	while(Menu());
	return 0;
}

int Menu()
{
	cout << endl 
		<< "1.添加数据" << endl
		<< "2.浏览数据" << endl
		<< "0.退出" << endl;
	char cSel = getch();
	switch(cSel)
	{
	case '1':
		Input();
		return 1;
	case '2':
		Print();
		return 1;
	case '0':
		return 0;
	};
	return 0;
}

void Input()
{
	cout << "请选择一个图形: 1.矩形  2.圆形  3.椭圆  4.圆角矩形" << endl;
	char cSel = getch();
	SShape *p = NULL;
	switch(cSel)
	{
	case '1':
		p = new SRect;
		break;
	case '2':
		p = new SCircle;
		break;
	case '3':
		p = new SEllipse;
		break;
	case '4':
		p = new SRoundRect;
		break;
	};
	if(p)
	{
		p->Input();
		g_list.push_back(p);
		Print();
		cout << endl;
	}
}

void Print()
{//SHAPE,RECT,CIRCLE,ELLIPSE
	int SumRECT = 0,SumCIRCLE = 0,SumELLIPSE = 0,SumROUNDRECT = 0;
	int nCount[4] = {0};//矩形/圆形/椭圆形/圆角矩形
	double fCircum[4] = {0}, fArea[4] = {0};
	list<SShape*>::iterator it = g_list.begin();
	while(it != g_list.end())
	{
		SShape *p = *it++;
		++nCount[p->GetType() - 1];
		fCircum[p->GetType() - 1] += p->GetCircum();
		fArea[p->GetType() - 1] += p->GetArea();
		p->Print();//基本信息
		cout << "\t\b周长=" << p->GetCircum() << "\t面积=" << p->GetArea() << endl << endl;
	}
	cout << "共有 " << nCount[0] + nCount[1] + nCount[2] + nCount[3] << " 个图形" << endl;
	cout << "矩形=" << nCount[0] << "\t圆形=" << nCount[1] << "\t椭圆形=" << nCount[2] << "\t圆角矩形=" << nCount[3] << endl;
	cout << "总周长=" << fCircum[0] + fCircum[1] + fCircum[2] + fCircum[3] << endl;
	cout << "总面积=" << fArea[0] + fArea[1] + fArea[2] + fArea[3] << endl;

	system("pause");
}
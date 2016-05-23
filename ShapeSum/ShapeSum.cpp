// ShapeSum.cpp : Defines the entry point for the console application.
//
/*
1���麯������ܹ�������
a)SShape���ǹ�����ͼ�λ��࣬���������Ρ���Բ����Բ�������ࣻ
b)���տ�����Ƶ����һ������ͼ�λ��¼�롢��ӡ�ͼ����������̣�
c)ѭ����ʾ�˵���¼��ʹ�ӡ��ѡ�
d)ÿ��¼�뽫���������Ϣ�û���ָ�뱣���������̬�����У�
e)ÿ��¼��֮�����ѭ����ӡ�����е�ÿ��ͼ�εĻ�����Ϣ�ͼ�����Ϣ��
	��������ӡÿ��ͼ�εĸ߿��뾶����Ϣ����ȡ��ͼ�ε��ܳ����������ӡ��
f)�����ѭ����������֮��ͳ�Ƴ�����ͼ�ε������ͳ����Ϣ�����磺
	�ܹ���8��ͼ�Σ�3�����Ρ�4��Բ�Ρ�1����Բ
	8��ͼ�ε��ܳ��ܼƣ�8888.55  ����ܼƣ�995.61
*/

#include "stdafx.h"
#include <conio.h>
#include <list>
#include <iostream>
using namespace std;
const double PI = 3.14;
struct SShape	// ��Ա�������д = 0����Ϊ�����ࣺ���ɹ�������
{//ͼ�λ���
	enum EType{SHAPE,RECT,CIRCLE,ELLIPSE,ROUNDRECT};
	virtual EType GetType() const = 0;
	virtual void Input() = 0;
	virtual void Print() const = 0;
	virtual double GetCircum() const  = 0;
	virtual double GetArea() const  = 0;
};
struct SRect:public SShape
{//���Σ��߿�
	double fWidth,fHeight;
	virtual EType GetType() const 
	{
		return RECT;
	}
	virtual void Input()
	{
		cout << "��������εĿ� �� �ߣ��ո�������";
		cin  >> fWidth >> fHeight;
	}
	virtual void Print() const
	{
		cout << "���Σ� ��=" << fWidth << "\t��=" << fHeight << endl;
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
{//Բ�Σ��뾶
	double fRadius; 
	virtual EType GetType() const 
	{
		return CIRCLE;
	}
	virtual void Input()
	{
		cout << "������Բ�ΰ뾶��" ;
		cin  >> fRadius;
	}
	virtual void Print() const
	{
		cout << "Բ�Σ� �뾶=" << fRadius << endl;		
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
{//Բ�Ǿ��Σ��߶� ��� Բ�ǰ뾶
	double fHight,fWidth,fRadius; 
	virtual EType GetType() const 
	{
		return ROUNDRECT;
	}
	virtual void Input()
	{
		cout << "������Բ�Ǿ��ε� �߶� ��� Բ�ǰ뾶��" ;
		cin  >> fHight >> fWidth >> fRadius;
	}
	virtual void Print() const
	{
		cout << "Բ�Ǿ��Σ� �߶�=" << fHight << "\t���=" << fWidth << "\Բ�ǰ뾶=" << fRadius << endl;		
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
{//��Բ:������
	double fLong,fShort;
	virtual EType GetType() const 
	{
		return ELLIPSE;
	}
	virtual void Input()
	{
		cout << "��������Բ�γ���/���ᣨ�ո�������";
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
		cout << "��Բ�Σ� ����=" << fLong << "\t����=" << fShort << endl;	
	}
	virtual double GetCircum() const 
	{
		return PI*fLong*fShort;
	}
	virtual double GetArea() const 
	{
		return 2*PI*fShort + 4*(fLong-fShort);
	}
	//�����PI*fLong*fShort
	//�ܳ���2PI*fShort+4*(fLong-fShort)
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
		<< "1.�������" << endl
		<< "2.�������" << endl
		<< "0.�˳�" << endl;
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
	cout << "��ѡ��һ��ͼ��: 1.����  2.Բ��  3.��Բ  4.Բ�Ǿ���" << endl;
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
	int nCount[4] = {0};//����/Բ��/��Բ��/Բ�Ǿ���
	double fCircum[4] = {0}, fArea[4] = {0};
	list<SShape*>::iterator it = g_list.begin();
	while(it != g_list.end())
	{
		SShape *p = *it++;
		++nCount[p->GetType() - 1];
		fCircum[p->GetType() - 1] += p->GetCircum();
		fArea[p->GetType() - 1] += p->GetArea();
		p->Print();//������Ϣ
		cout << "\t\b�ܳ�=" << p->GetCircum() << "\t���=" << p->GetArea() << endl << endl;
	}
	cout << "���� " << nCount[0] + nCount[1] + nCount[2] + nCount[3] << " ��ͼ��" << endl;
	cout << "����=" << nCount[0] << "\tԲ��=" << nCount[1] << "\t��Բ��=" << nCount[2] << "\tԲ�Ǿ���=" << nCount[3] << endl;
	cout << "���ܳ�=" << fCircum[0] + fCircum[1] + fCircum[2] + fCircum[3] << endl;
	cout << "�����=" << fArea[0] + fArea[1] + fArea[2] + fArea[3] << endl;

	system("pause");
}
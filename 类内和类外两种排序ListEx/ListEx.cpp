// ListEx.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ListEx1.h"
#include <iostream>
using namespace std;

bool Comp(const int& d1, const int& d2)
{
	return d1 < d2;
}

int main(int argc, char* argv[])
{
	CListEx<int,int> m_list;
	int a[] = {16,4889,1558,84213,8484,15,49,1,49,633};
	int i = 0;
	while(i < 10)
		m_list.AddTail(a[i++]);
	POSITION *p = m_list.Sort2(Comp);
	i = 0;
	while(i < 10)
	{
		cout << *(p+i) << endl;
		++i;
	}
	POSITION pos = m_list.GetHeadPosition();
	while(pos)
		cout << m_list.GetNext(pos) << endl;

	return 0;
}

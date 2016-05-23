// NewAR.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Array.h"
#include <iostream>
using namespace std;

int compar(const void* pData1, const void* pData2)
{
	TYPE* p1 = (TYPE*)pData1;
	TYPE* p2 = (TYPE*)pData2;
	return *p1 - *p2;
}

void main()
{
	CArray arr;
	arr.Add(1234);
	arr.Add(23);
	arr.Add(44);
	arr.Add(21);
	arr.Add(5);
	arr.RemoveAt(2,20000000); //从第二个位置起，删除2个数据
	arr.InsertAt(3,10,2);
	int i = 0;
	int nSize = arr.GetSize();
	cout << "共有 " << nSize << " 条数据" << endl;
	
	TYPE *p = arr.GetData();
	
	qsort(p,nSize,sizeof(TYPE),compar);

	while(i < nSize)
	{
		cout << arr[i] << endl;
		++i;
	}
}

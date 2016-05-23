// qsort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h> 
#include <search.h>
#include <iostream>
using namespace std;
void Sort(int arr[],int nCount);
void Search(int arr[],int nCount);
int NS(const void *elem1, const void *elem2);
void Print(int arr[],int nCount);
void Print(int arr[],int nIndex,int a);


int main(int argc, char* argv[])
{
	int arr[] = 
		{156,8941,156,15,12,561,841,1,34186,16,5813,61684,1388461,1684,136984,61,1698461,48694,169842318,15};

	int nSize = sizeof(arr)/sizeof(arr[0]);
	Sort(arr,nSize);
	Print(arr,nSize);
	Search(arr,nSize);
	return 0;
}

void Print(int arr[],int nCount)
{
	int i = 0;
	cout << "共有 " << nCount << " 条数据" << endl;
	while(i < nCount)
	{
		cout << arr[i] << endl;
		++i;
	}
}

void Print(int arr[],int nIndex, int a)
{
	cout << "找到了！ " <<endl;
	cout << "第 " << nIndex  << " 条数据" << endl;
	cout << arr[nIndex] << endl;
}

void Search(int arr[],int nCount)
{
//void *bsearch( const void *key, const void *base, size_t num, size_t width, 
//	int ( __cdecl *compare ) ( const void *elem1, const void *elem2 ) );
	int data;
	cout << "请输入你要查找的数字：" ;
	cin  >> data;
	Sort(arr,nCount);
	int *nIndex = (int*)bsearch(&data,arr,nCount,4,NS);
	int p = &arr - &nIndex;
	Print(arr,p+1,1);
}

void Sort(int arr[],int nCount)
{
//	void qsort( void *base, size_t num, size_t width, int (__cdecl *compare )(const void *elem1, const void *elem2 ) );
	qsort(arr,nCount,4,NS);
}

int NS(const void *elem1, const void *elem2)
{
	return *(int*)elem1 - *(int*)elem2;
} 


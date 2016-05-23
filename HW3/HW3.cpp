// HW3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <list>
using namespace std;
typedef int DATA ;
list<DATA>g_list;
void Test(char *a,int n)
{
	cout << a << endl;
	int i = 0;
	while(i < n)
	{
		cout << *a ;
		++a;
		++i;
	}
	cout << endl;
}
int main(int argc, char* argv[])
{
	char a[] = "zhaolei777abadwawÕÒÁËcd" ;
	Test(a,strlen(a));

	char str[] = "abadwawÕÒÁËcd";

	g_list.push_back(95);
	g_list.push_back(95);
	g_list.push_back(95);
	g_list.push_back(95);
	g_list.push_back(95);
	g_list.push_front(66);
	list<int>::iterator it = g_list.begin();
	while(it != g_list.end())
	{
		printf("%d\n",*it);
		++it;
	}
	return 0;
}

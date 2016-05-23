// ascll×Ö·û±È´óÐ¡.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int nCount = 0 ;
	cin >> nCount;

	int i = 0, m = 0,n = 0;
	while(i < nCount)
	{
		char *p = new char[4];
		memset(p,0,strlen(p));
		cin >> p;
		while(m < 3)
		{
			n = 0;
			while(n < 2)
			{
				if( (int)p[m] > (int)p[m+1])
				{
					if(p[m+1] == '\0'  ||  p[m] == '\0')
						break;
					char t = p[m];
					p[m] = p[m+1];
					p[m+1] = t;
				}
				++n;
			}
			++m;
		}
		cout << p[0] << " " << p[1] << " " << p[2] << endl;
	}
	return 0;
}

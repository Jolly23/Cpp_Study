// memoveTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void *Memcpy(void *dest, const void *src, size_t count)
{
	char *pDest = (char*)dest;
	char *pSrc  = (char*)src;

//	while(pDest - dest < count)
	if(pDest > pSrc + count  ||  pDest < pSrc)
	{
		while(count--)
			*pDest++ = *pSrc++;
	}
	else
	{
		pDest += count-1;
		pSrc  += count-1;
		while(count--)
			*pDest-- = *pSrc-- ;
	}
	return dest;

}

int main(int argc, char* argv[])
{
	char dest[] = "ZhaoLe123123i777";
	char src[]  = "YanXiao";
	
	Memcpy(dest,src,sizeof(src));
	cout << dest << endl;

	return 0;
}

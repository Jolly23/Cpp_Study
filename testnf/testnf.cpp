// testnf.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>


int main(int argc, char* argv[])
{
	FILE *fp = fopen("c:ReadMe.txt","r");
	FILE *fp2= fopen("c:ReadMe2.txt","a+");

	char c;
	while( fread(&c,1,1,fp) > 0)
	{
		fwrite(&c,1,1,fp2);
	}
	return 0;
}

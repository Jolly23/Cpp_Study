// PPtr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>

int main(int argc, char* argv[])
{
	int i = 0;
	char**ps = (char**)malloc(sizeof(char**)*5);
	ps[0] = "dasad";
	ps[1] = "xzcscxz";
	ps[2] = "yujiyt";
	ps[3] = "qw";
	ps[4] = 0;
	while(ps[i])
	{
		puts(ps[i]);
		++i;
	}
	free(ps);
	return 0;
}

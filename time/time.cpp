// time.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <string.h>

void main()
{
	char nowtime[128], ampm[] = "AM";
	_strtime(nowtime);
	puts(nowtime);
	char *p = strchr(nowtime,':');
	*p = 0;
	puts(nowtime);
}

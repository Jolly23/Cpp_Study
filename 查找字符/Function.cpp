#include "stdafx.h"
#include <stdio.h>

int Serch(char str[],char c)
{
	int i=0;
	while(str[i] != '\0')
	{
		if (str[i]==c)	break;
		i++;
	}
	if(i=='\0')	return -1;
	else return i;
}
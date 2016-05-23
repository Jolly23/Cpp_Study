#include "stdafx.h"
#include <stdio.h>

void main()
{
	char c[32];
	printf("«Î ‰»Î“ª¥Æ”¢Œƒ£∫");
	scanf("%s",c);
	int s=0;
	while(c[s])
		s++;
	s=s-1;
	while(s != -1)
	{
		printf("%c",c[s]);
		s--;
	}
	printf("\n");
}

#include<stdio.h>

void main()

{ long x;

int n=0;

  printf("����һ����");


  scanf("%d",&x);

 do

   {  n++;

      x/=10;


   }while(x!=0);

 printf("n=%d\n",n);
 printf("                                              ����-�Ϲ�Ƽ���Ʒ\n");

}


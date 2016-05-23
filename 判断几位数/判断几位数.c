#include<stdio.h>

void main()

{ long x;

int n=0;

  printf("输入一个数");


  scanf("%d",&x);

 do

   {  n++;

      x/=10;


   }while(x!=0);

 printf("n=%d\n",n);
 printf("                                              赵磊-南光科技出品\n");

}


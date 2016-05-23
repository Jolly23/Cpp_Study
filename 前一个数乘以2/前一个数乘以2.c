#include<stdio.h>

void main()


{  int a[3];

   int i;

   printf("Please input a[0]:");


   scanf("%d",&a[0]);

   for(i=1;i<3;i++)  a[i]=2*a[i-1];


   printf("%d   %d   %d\n",a[0],a[1],a[2]);

   printf("                                           赵磊-南光科技出品\n");

}


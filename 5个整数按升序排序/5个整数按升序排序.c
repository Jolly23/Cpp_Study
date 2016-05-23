#include <stdio.h>

#define N 5

void main()

{  int  i, j, k, t, a[N];

   printf("输入5个数:\n");

   for(i=0;i<=N-1;i++) scanf("%d",&a[i]);

   for(i=0;i<N-1;i++)

       {k=i;

          for(j=i+1;j<=N-1;j++)

                 if(a[j]<a[k]) k=j;

          if(i!=k){t=a[i];a[i]=a[k];a[k]=t;}

       }

 printf("从小到大排序:\n");

   for(i=0;i<=N-1;i++)  printf("%5d",a[i]);

   printf("\n");

   printf(" \n\n                                             赵磊-南光科技出品\n");

}


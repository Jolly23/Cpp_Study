#include<stdio.h>

void main()

{  int i;

   long f1,  f2;

f1=1,f2=1;
 
printf("Fibonacci����ǰ40��\n");
	 

 for(i=1;i<=20;i++)

  { printf("%12ld%12ld",f1,f2);

     if(i%2==0)printf("\n");

    f1+=f2;

f2=f2+f1;

  }
 printf("                                              ����-�Ϲ�Ƽ���Ʒ\n");

}

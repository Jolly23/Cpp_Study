#include<stdio.h>

void main()

{  char s[80],c1,c2;

   int i=0,num=0;

   printf("дһ�����ӣ���Ӣ��:\n");

   gets(s);
   
   while(s[i]!='\0')

     {  c1=s[i];

        if(i==0) c2=' ';

        else c2=s[i-1];

        if(c1!=' '&& c2==' ')num++;

        i++;

     }

   printf("�� %d ������.\n",num);

   printf("                                              ����-�Ϲ�Ƽ���Ʒ\n");

}


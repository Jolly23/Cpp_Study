#include<stdio.h>

void main()

{  char s[80],c1,c2;

   int i=0,num=0;

   printf("写一个句子，用英语:\n");

   gets(s);
   
   while(s[i]!='\0')

     {  c1=s[i];

        if(i==0) c2=' ';

        else c2=s[i-1];

        if(c1!=' '&& c2==' ')num++;

        i++;

     }

   printf("有 %d 个单词.\n",num);

   printf("                                              赵磊-南光科技出品\n");

}


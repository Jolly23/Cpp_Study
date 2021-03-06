#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

void dofile(char *in_fname,char *pwd,char *out_fname);/*对文件进行加密的具体函数*/
void usage(char *name);

void main(int argc,char *argv[])/*定义main()函数的命令行参数*/
{
    char in_fname[30];/*用户输入的要加密的文件名*/
    char out_fname[30];
    char pwd[10];/*用来保存密码*/

    if(argc!=4)
 {/*容错处理*/
    usage(argv[0]);
    printf("\nIn-fname:\n");
    gets(in_fname);/*得到要加密的文件名*/
 while(*in_fname==NULL)
 {
       printf("\nIn-fname:\n");
       gets(in_fname);
 }

    printf("Password 6-8:\n");
    gets(pwd);/*得到密码*/
 while(*pwd==NULL || strlen(pwd)>8 || strlen(pwd)<6)
 {
  printf("Password 6-8:\n");
        gets(pwd);
 }

    printf("Out-file:\n");
    gets(out_fname);/*得到加密后你要的文件名*/
 while(*in_fname==NULL)
 {
      printf("Out-file:\n");
      gets(out_fname);
 }
 while(!strcmp(in_fname,out_fname))
 {
  printf("文件名不能和源文件相同\n");
  printf("Out-file:\n");
        gets(out_fname);
 }
     dofile(in_fname,pwd,out_fname);
  printf("加密成功，解密请再次运行程序\n");

 }
    else
 {/*如果命令行参数正确,便直接运行程序*/

     strcpy(in_fname,argv[1]);
     strcpy(pwd,argv[2]);
     strcpy(out_fname,argv[3]);
  while(*pwd==NULL || strlen(pwd)>8 || strlen(pwd)<6)
  {  
  printf("Password faied!\n");
  printf("Password 6-8:\n");
        gets(pwd);
  }

  while(!strcmp(in_fname,out_fname))
 {
  printf("文件名不能和源文件相同\n");
  printf("Out-file:\n");
        gets(out_fname);
  while(*in_fname==NULL)
  {
             printf("Out-file:\n");
             gets(out_fname);
  }
 }

     dofile(in_fname,pwd,out_fname);
  printf("加密成功，解密请再次运行程序\n");

 }

}

/*加密子函数开始*/
void dofile(char *in_fname,char *pwd,char *out_file)
{
    FILE *fp1,*fp2;
    register char ch;
    int j=0;
    int j0=strlen(pwd);

    fp1=fopen(in_fname,"rb");
    if(fp1==NULL)
 {
    printf("cannot open in-file.\n");
    exit(1);/*如果不能打开要加密的文件,便退出程序*/
 }
    fp2=fopen(out_file,"wb");
    if(fp2==NULL)
 {
    printf("cannot open or create out-file.\n");
    exit(1);/*如果不能建立加密后的文件,便退出*/
 }

/*加密算法开始*/
 while(j0>=0)
    {
    ch=fgetc(fp1);
       while(!feof(fp1))
    {
         fputc(ch^pwd[j>=j0?j=0:j++],fp2);/*异或后写入fp2文件*/
         ch=fgetc(fp1);
    }
    j0--;
 }
      fclose(fp1);/*关闭源文件*/
      fclose(fp2);/*关闭目标文件*/
}

void usage(char *name)
{
printf("\t=======================File encryption======================\n");
printf("\tusage: %s In-fname password out_fname\n",name);
printf("\tExample: %s file1.txt 12345678 file2.txt\n",name);
}
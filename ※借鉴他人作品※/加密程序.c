#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

void dofile(char *in_fname,char *pwd,char *out_fname);/*���ļ����м��ܵľ��庯��*/
void usage(char *name);

void main(int argc,char *argv[])/*����main()�����������в���*/
{
    char in_fname[30];/*�û������Ҫ���ܵ��ļ���*/
    char out_fname[30];
    char pwd[10];/*������������*/

    if(argc!=4)
 {/*�ݴ���*/
    usage(argv[0]);
    printf("\nIn-fname:\n");
    gets(in_fname);/*�õ�Ҫ���ܵ��ļ���*/
 while(*in_fname==NULL)
 {
       printf("\nIn-fname:\n");
       gets(in_fname);
 }

    printf("Password 6-8:\n");
    gets(pwd);/*�õ�����*/
 while(*pwd==NULL || strlen(pwd)>8 || strlen(pwd)<6)
 {
  printf("Password 6-8:\n");
        gets(pwd);
 }

    printf("Out-file:\n");
    gets(out_fname);/*�õ����ܺ���Ҫ���ļ���*/
 while(*in_fname==NULL)
 {
      printf("Out-file:\n");
      gets(out_fname);
 }
 while(!strcmp(in_fname,out_fname))
 {
  printf("�ļ������ܺ�Դ�ļ���ͬ\n");
  printf("Out-file:\n");
        gets(out_fname);
 }
     dofile(in_fname,pwd,out_fname);
  printf("���ܳɹ����������ٴ����г���\n");

 }
    else
 {/*��������в�����ȷ,��ֱ�����г���*/

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
  printf("�ļ������ܺ�Դ�ļ���ͬ\n");
  printf("Out-file:\n");
        gets(out_fname);
  while(*in_fname==NULL)
  {
             printf("Out-file:\n");
             gets(out_fname);
  }
 }

     dofile(in_fname,pwd,out_fname);
  printf("���ܳɹ����������ٴ����г���\n");

 }

}

/*�����Ӻ�����ʼ*/
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
    exit(1);/*������ܴ�Ҫ���ܵ��ļ�,���˳�����*/
 }
    fp2=fopen(out_file,"wb");
    if(fp2==NULL)
 {
    printf("cannot open or create out-file.\n");
    exit(1);/*������ܽ������ܺ���ļ�,���˳�*/
 }

/*�����㷨��ʼ*/
 while(j0>=0)
    {
    ch=fgetc(fp1);
       while(!feof(fp1))
    {
         fputc(ch^pwd[j>=j0?j=0:j++],fp2);/*����д��fp2�ļ�*/
         ch=fgetc(fp1);
    }
    j0--;
 }
      fclose(fp1);/*�ر�Դ�ļ�*/
      fclose(fp2);/*�ر�Ŀ���ļ�*/
}

void usage(char *name)
{
printf("\t=======================File encryption======================\n");
printf("\tusage: %s In-fname password out_fname\n",name);
printf("\tExample: %s file1.txt 12345678 file2.txt\n",name);
}
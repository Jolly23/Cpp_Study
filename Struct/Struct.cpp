// Struct.cpp : Defines the entry point for the console application.
//
//Version bate 0.1    ����ʦ������

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <process.h>
#include <windows.h>

typedef struct Students STU;//�궨��

struct fScore    //�ɼ���Ϣ
{
	float fChin;//���ĳɼ�
	float fMath;//��ѧ�ɼ�
	float fEngl;//Ӣ��ɼ�
};
struct Students  //ѧ����Ϣ
{
	int nNumb;//ѧ��
	char sName[20];//����
	struct fScore Sc;//��ȡ�ɼ��ṹ��
};
void Input(STU *pSTU)//�ṹ�����뺯��
{
	printf("������ѧ�ź��������ո�����:");
	scanf("%d %s",&pSTU->nNumb,pSTU->sName);
	printf("���������ĳɼ���");
	scanf("%f",&pSTU->Sc.fChin);
	printf("��������ѧ�ɼ���");
	scanf("%f",&pSTU->Sc.fMath);
	printf("������Ӣ��ɼ���");
	scanf("%f",&pSTU->Sc.fEngl);
}
void Output(STU *pout)//�ṹ���������
{
	puts("ѧ��\t����\t����\t��ѧ\tӢ��");
	printf("%d\t%s\t%.1f\t%.1f\t%.1f\n",pout->nNumb,pout->sName,pout->Sc.fChin,pout->Sc.fMath,pout->Sc.fEngl);
}

STU D141[100]=
{
	{2000,"LTL",{16,16,16}},
	{2001,"LZG",{93,93,93}}
};

void main()//�������������д���չ��
{
	STU s1,s2,s3,*ptr;
	memset(&s1,0,sizeof(STU));
	Input(&s1);
	Output(&s1);
	memset(&s1,0,sizeof(STU));

	system("pause");
}

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <process.h>

struct SSTU
{
	int nNumb;
	char sName[20];
	float fMath;
	float fChin;
	float fEngl;
	float fAver;
};

void Output(SSTU *st,int i);//�����������
void Aver(SSTU *st,int i);//��ƽ����������
int Input(SSTU *st,int nSize);//¼����Ϣ����

void main()
{
	SSTU st[100];

	int i = Input(st,sizeof(st)/sizeof(st[0]));

	Output(st,i);

	system("pause");
}



int Input(SSTU *st,int nSize)//¼����Ϣ����
{	
	SSTU *LS=st;
	printf("���ͳ��100��ѧ������Ϣ��ֹͣ���������� 0 stop\n");
	while(LS-st<nSize)
	{
		printf("�����%d��ѧ����ѧ�š��������ո�������",LS-st+1);
		scanf("%d %s",&LS->nNumb,&LS->sName);
		if(memcmp(&LS->sName,"stop",sizeof("stop")) == 0)		break;
		printf("����������ѧ�����ġ�Ӣ��ɼ����ո�������");
		scanf("%f %f %f",&LS->fMath,&LS->fChin,&LS->fEngl);
		printf("\n");
		LS++;
	}
	system("cls");
	puts("��Ϣ¼����ɣ�\n");

	return LS-st;
	
}


void Output(SSTU *st,int i)//�๦���������
{
	int mode = 1;

	SSTU *LS=st;

	if(mode == 1)
	{
		puts("��ѡ��������ȫ��ͬѧ�ɼ���ƽ����");
		Aver(st,i);//������ƽ��������
		while(LS-st<i)
		{
			printf("%-8s��ƽ������ %.1f\n",LS->sName,LS->fAver);
			LS++;
		}
	}

}

void Aver(SSTU *st,int i)//��ƽ������
{
	SSTU *LS=st;
	while(LS-st<i)
	{
		LS->fAver = (LS->fChin + LS->fMath + LS->fEngl)/3;
		LS++;
	}
}

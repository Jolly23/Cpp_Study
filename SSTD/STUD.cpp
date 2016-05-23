// STUD.cpp: implementation of the STUD class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "STUD.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//回调函数不可成为成员函数

STUD::STUD()
{
	g_pHead = NULL ;
}

STUD::~STUD()
{
	DeleteAllDispose();
}

void STUD::Load()
{
	FILE *fp = fopen("stud.lqm","a+");
	SSTU DATA;
	while( fread(&DATA,1,sizeof(SSTU),fp) >0 )
		InsertDispose(DATA);
	fclose(fp);
}

void STUD::Save()
{
	FILE *fp = fopen("stud.lqm","w");
	
	SNode *p = g_pHead;
	
	while(p)
	{
		fwrite(&p->data,1,sizeof(SSTU),fp);
		p = p ->pNext;
	}
	
	fclose(fp);
}

void STUD::Version()
{
	puts("***************");
	puts("数据管理器 V1.3");
}

void STUD::Menu()
{
	system("cls");
	char Select = 0;
	Version();
	puts("**************");
	puts("**1.浏览数据**");
	puts("**2.数据分析**");
	puts("**3.添加数据**");
	puts("**4.查找数据**");
	puts("**5.修改数据**");
	puts("**6.删除数据**");
	puts("**0.退出程序**");
	puts("**************");
	
	Select = getch();
	
	if(Select >= '0'  &&  Select <= '6')
		MenuDispose(Select);
	
	else
	{
		puts("输入有误！");
		system("pause");
	}
}

void STUD::MenuDispose(char Select)
{
	switch(Select)
	{
	case '1':
		while( BrowseMenu() != '0' );
		break;
	case '2':
		DataAnalyse();
		break;
	case '3':
		Insert();
		break;
	case '4':
		SearchMenu();
		break;
	case '5':
		ModifyMenu();	
		break;
	case '6':
		DeleteMenu();	
		break;
	case '0':
		SayByeToUser();
	}
}

void STUD::DataAnalyse()
{
	//数据最高分、最低分
	//全体数据平均分
	//数据及格率
	//数据 优、良、中、差
	int SumNumberOfData = DATASum();
	
	if(!SumNumberOfData)
	{
		puts("无数据！");
		system("pause");
		return;
	}

	float SumMath = 0.0;
	int   Qualified = 0;
	int   Good = 0, Well = 0, Mid = 0, Bad = 0;

	system("cls");
	printf("目前共有 %d 条数据\n",SumNumberOfData);

	SNode *p = g_pHead, *pMax = g_pHead, *pMin = g_pHead;

	while(p)
	{
		if(p->data.fMath > pMax->data.fMath)
			pMax = p;
		if(p->data.fMath < pMin->data.fMath)
			pMin = p;

		SumMath += p->data.fMath;

		if(p->data.fMath >= 60.0)
			Qualified++;

		if(p->data.fMath >= 85.0)
			Good++;
		if(p->data.fMath >= 75.0  &&  p->data.fMath < 85.0)
			Well++;
		if(p->data.fMath >= 60.0  &&  p->data.fMath < 75.0)
			Mid++;
		if(p->data.fMath < 60.0)
			Bad++;

		p = p->pNext;
	}

	printf("分数最高：学号为 %4d，姓名：%4s，分数为%.1f\n",pMax->data.nNumb,pMax->data.sName,pMax->data.fMath);
	printf("分数最低：学号为 %4d，姓名：%4s，分数为%.1f\n\n",pMin->data.nNumb,pMin->data.sName,pMin->data.fMath);
	printf("所有数据  平均分为 %.2f \n\n",SumMath/SumNumberOfData);
	printf("所有数据  及格率为 %.2f%%\n\n",(float)Qualified/(float)SumNumberOfData*100);
	printf("所有数据  优秀<高于85分>率为 %.2f%%\n",(float)Good/(float)SumNumberOfData*100);
	printf("所有数据  良好 <75~85分>率为 %.2f%%\n",(float)Well/(float)SumNumberOfData*100);
	printf("所有数据  中等 <60~85分>率为 %.2f%%\n",(float)Mid/(float)SumNumberOfData*100);
	printf("所有数据   差 <低于60分>率为 %.2f%%\n\n",(float)Bad/(float)SumNumberOfData*100);


	system("pause");
}


char STUD::BrowseMenu()
{
	char Sel;
	system("cls");
	puts("***浏览数据***");
	puts("**************");
	puts("*1.按学号排序*");
	puts("*2.按姓名排序*");
	puts("*3.按成绩排序*");
	puts("*0.返回主菜单*");

	Sel = getch();
	
	switch(Sel)
	{
	case '1':
		SortByWhat(SortByNumb);		
		break;
	case '2':
		SortByWhat(SortByName);
		break;
	case '3':
		SortByWhat(SortByMath);
		break;
	case '0':
		return Sel;

	default:
		puts("输入有误！");
		system("pause");
		return '1';
	}
	
	Print();
	system("pause");

	return Sel;
}

void STUD::Print()
{
	system("cls");

	int Sum = DATASum();
	if(!Sum)
	{
		puts("无数据！");
		system("pause");
		return;
	}

	SNode *p = g_pHead;
	puts("*********************");
	printf("  目前共有 %d 条数据\n",Sum);
	puts("学号\t姓名\t成绩");
	while(p)
	{
		printf("%d\t%s\t%.1f\n",p->data.nNumb,p->data.sName,p->data.fMath);
		p = p->pNext;
	}
}

int SortByNumb(SNode *p1,SNode *p2)
{
	return p1->data.nNumb < p2->data.nNumb;
}

int SortByName(SNode *p1,SNode *p2)
{
	return strcmp(p1->data.sName , p2->data.sName) < 0;
}

int SortByMath(SNode *p1,SNode *p2)
{
	return p1->data.fMath > p2->data.fMath;
}


void STUD::SortByWhat( int (*SortBy) (SNode *p1,SNode *p2) )
{
	if(g_pHead == NULL  ||  g_pHead ->pNext ==NULL)
		return;
	
	SNode *p = g_pHead, *p1, *pMin;

	while(p)
	{
		p1 = p->pNext;
		pMin = p;

		while(p1)
		{
			if( (*SortBy) (p1,pMin) )
				pMin = p1;
			p1 = p1->pNext;
		}
		
		if(p != pMin)
		{
			SSTU t      =   p->data;
			p ->data    =   pMin->data;
			pMin ->data =   t;
		}
	
		p = p ->pNext;
	}
}


void STUD::Insert()
{	
	SSTU pNew;
	int ls = 0,Check = 0;
	char Sel;
	do
	{
		system("cls");
		puts("***添加数据***");
		printf("请 输 入 学 号：");
		scanf("%d",&ls);
		
		Check = CheckNumb(ls);
		
		if(Check == 0)
		{
			puts("此学号已存在！");
			system("pause");
			return;
		}
		
		pNew.nNumb = ls;
		printf("请 输 入 姓 名：");
		scanf("%s",&pNew.sName);
		printf("请输入数学成绩：");
		scanf("%f",&pNew.fMath);
		
		InsertDispose(pNew);
		Save();
		
		puts("录入成功，是否继续录入？【按Y确认】");
		
		Sel = getch();
		
	}while(Sel == 'y'  ||  Sel == 'Y');
	
}

void STUD::InsertDispose(SSTU DATA)
{
	SNode *pNew =new SNode;
	pNew->data = DATA;
	pNew->pNext = g_pHead;
	g_pHead = pNew;
}

int  STUD::CheckNumb(int ls)
{
	SNode *pTest = g_pHead;
	
	while(pTest)
	{
		if(pTest->data.nNumb == ls)
			return 0;
		pTest = pTest->pNext;
	}
	return 1;
}

void STUD::SearchMenu()
{
	system("cls");
	puts("***查找数据***");
	char Sel;
	puts("**************");
	puts("*1.按姓名查找*");
	puts("*2.按学号查找*");
	puts("**************");
	Sel = getch();
	
	switch(Sel)
	{
	case '1':
		SearchByName();
		system("pause");
		break;
	case '2':
		SearchByNumb();
		system("pause");
		break;
	default:
		puts("输入错误！");
		system("pause");
		return;
	}
}
SNode* STUD::SearchByName()
{	
	char SearchName[20];
	printf("请输入要查找的同学姓名：");
	scanf("%s",SearchName);
	
	SNode *p;
	p = FindByNameDispose(SearchName);
	
	if(p == NULL)
		puts("数据未找到！");
	else
	{
		puts("你要查找的数据已被找到：");
		printf("学号：%d\t姓名：%s\t成绩：%.1f\n",p->data.nNumb,p->data.sName,p->data.fMath);
	}
	return p;
}

SNode* STUD::FindByNameDispose(char SearchName[20])
{
	SNode *p = g_pHead;
	
	while(p)
	{
		if( strcmp(p->data.sName , SearchName) == 0 )
			break;
		p = p->pNext;
	}
	return p;
} 

SNode* STUD::SearchByNumb()
{
	int SearchNumb;
	
	printf("请输入要查找的同学学号：");
	scanf("%d",&SearchNumb);
	
	SNode *p;
	p = FindByNumbDispose(SearchNumb);
	
	if(p == NULL)
		puts("未找到此数据！");
	
	else
	{
		puts("你要查找的数据已被找到：");
		printf("学号：%d\t姓名：%s\t成绩：%.1f\n",p->data.nNumb,p->data.sName,p->data.fMath);
	}
	return p;
}

SNode* STUD::FindByNumbDispose(int SearchNumb)
{
	SNode *p = g_pHead;
	
	while(p)
	{
		if( p->data.nNumb == SearchNumb )
			break;
		p = p->pNext;
	}
	return p;
}

void STUD::ModifyMenu()
{
	system("cls");
	char Sel;
	puts("*****修改数据*****");
	puts("******************");
	puts("1.按姓名查找并修改");
	puts("2.按学号查找并修改");
	puts("******************");
	Sel = getch();
	
	SNode *p = NULL;
	switch(Sel)
	{
	case '1':
		p = SearchByName();
		ModifyMenu2(p);
		break;
	case '2':
		p = SearchByName();
		ModifyMenu2(p);
		break;
	default:
		puts("输入错误！");
		system("pause");
		return;
	}	
	
}

void STUD::ModifyMenu2(SNode* p)
{
	char Sel = 0;
	puts("******************");
	puts("请选择要修改的项目");
	puts(" ***1.修改学号***");
	puts(" ***2.修改姓名***");
	puts(" ***3.修改成绩***");
	Sel = getch();
	
	switch(Sel)
	{
	case '1':
		ModifyNumb(p);
		break;
	case '2':
		ModifyName(p);
		break;
	case '3':
		ModifyMath(p);
		break;
	default:
		puts("输入有误！");
		system("pause");
		return;
	}
}

void STUD::ModifyNumb(SNode* p)
{
	char Decision;
	int  NewNumb;
	
	printf("原学号为%d，请输入修改后的学号：",p->data.nNumb);
	scanf("%d",&NewNumb);
	
	printf("你确定把原学号为%d，姓名为%s的数据 学号改为%d吗？【按Y确认】",p->data.nNumb,p->data.sName,NewNumb);
	Decision = getch();
	
	if(Decision == 'y'  ||  Decision == 'Y')
	{
		p->data.nNumb = NewNumb;
		Save();
		puts("修改成功！");
	}
	else
		puts("取消修改！");
	system("pause");
	return;
}

void STUD::ModifyName(SNode* p)
{
	char NewName[20],Decision;
	
	printf("原姓名为%s，请输入修改后的姓名：",p->data.sName);
	scanf("%s",NewName);
	
	printf("你确定把学号为%d，原姓名为%s的数据 姓名改为%s吗？【按Y确认】",p->data.nNumb,p->data.sName,NewName);
	Decision = getch();
	
	if(Decision == 'y'  ||  Decision == 'Y')
	{
		strcpy( p->data.sName , NewName );
		Save();
		puts("修改成功！");
	}
	else
		puts("取消修改！");
	system("pause");
	return;	
}

void STUD::ModifyMath(SNode* p)
{
	char  Decision;
	float NewMath;
	
	printf("原成绩为%.1f，请输入修改后的成绩：",p->data.fMath);
	scanf("%f",&NewMath);
	
	printf("你确定把姓名为%s的数据 成绩改为%.1f吗？【按Y确认】",p->data.sName,NewMath);
	Decision = getch();
	
	if(Decision == 'y'  ||  Decision == 'Y')
	{
		p->data.fMath = NewMath;
		Save();
		puts("修改成功！");
	}
	else
		puts("取消修改！");
	system("pause");	
}

void STUD::DeleteMenu()
{	
	system("cls");
	char Sel;
	puts("******删除数据******");
	puts("********************");
	puts("1.按姓名删除");
	puts("2.按学号删除");
	puts("3.清空数据<管理员>");
	
	Sel = getch();
	
	switch(Sel)
	{
	case '1':
		DeleteFindByName();
		break;
	case '2':
		DeleteFindByNumb();
		break;
	case '3':
		DeleteAllApprove();
		break;
	default:
		puts("输入错误！");
		system("pause");
		return;
	}
	
}

void STUD::DeleteFindByName()
{
	char DName[20],Sel;
	printf("请输入要删除的数据的姓名：");
	scanf("%s",DName);
	
	SNode *p = g_pHead, *p1 = NULL;
	
	while(p)
	{
		if( strcmp(p->data.sName , DName) == 0 )
			break;
		p1= p;
		p = p->pNext;
	}
	
	if(p == NULL)
	{
		puts("未找到此数据！");
		system("pause");
		return;
	}
	
	printf("确定要删除学号为：%d 姓名为：%s 成绩为：%.1f 的数据吗？【按Y删除】",p->data.nNumb,p->data.sName,p->data.fMath);
	Sel = getch();
	
	if(Sel == 'y'  ||  Sel == 'Y')
	{
		if(p1 != NULL)
			p1->pNext = p->pNext;	
		else
			g_pHead = p->pNext;
		free(p);
		Save();
		puts("删除成功！");
		system("pause");
		return;
	}

	else
	{
		puts("取消删除！");
		system("pause");
		return;
	}
}

void STUD::DeleteFindByNumb()
{
	char Sel;
	int  DNumb;
	printf("请输入要删除的数据的学号：");
	scanf("%d",&DNumb);
	
	SNode *p = g_pHead, *p1 = NULL;
	
	while(p)
	{
		if( p->data.nNumb == DNumb )
			break;
		p1= p;
		p = p->pNext;
	}
	
	if(p == NULL)
	{
		puts("未找到此数据！");
		system("pause");
		return;
	}
	
	printf("确定要删除学号为：%d 姓名为：%s 成绩为：%.1f 的数据吗？【按Y删除】",p->data.nNumb,p->data.sName,p->data.fMath);
	Sel = getch();
	
	if(Sel == 'y'  ||  Sel == 'Y')
	{
		if(p1 != NULL)
			p1->pNext = p->pNext;	
		else
			g_pHead = p->pNext;
		free(p);
		Save();
		puts("删除成功！");
		system("pause");
		return;
	}
	else
	{
		puts("取消删除！");
		system("pause");
		return;
	}
}

void STUD::DeleteAllApprove()
{
	system("cls");

	int nRes ;
	
	char Passcode[32];
	printf("请输入管理员密码：");
	scanf("%s",Passcode);
	
	if( strcmp(Passcode , "Arsenal2") == 0 )
	{
		nRes = DeleteAllDispose();
		Save();
		if(nRes == 0)
		{
			puts("链表为空！");
			system("pause");
			return;
		}
		puts("清空成功！");
		system("pause");
		return;
	}	
	else
	{
		puts("密码错误！");
		system("pause");
		return;
	}
}


int  STUD::DeleteAllDispose()
{
	SNode *p = g_pHead, *p1 = NULL;
	
	if(g_pHead == NULL)
		return 0;
	
	while(p)
	{
		if(p1)
			free(p1);
		p1 = p;
		p = p->pNext;
	}
	free(p);
	g_pHead = NULL;
	
	return 1;
}

int  STUD::DATASum()
{
	if(g_pHead == NULL)
		return 0;
	SNode *p = g_pHead;
	int Sum = 0;

	while(p)
	{
		++Sum;
		p = p ->pNext;
	}
	return Sum;
}

void STUD::SayByeToUser()
{
	Save();
	DeleteAllDispose();
	system("cls");
	puts("\t\t天津科技出品");
	system("pause");
	exit(1);
}

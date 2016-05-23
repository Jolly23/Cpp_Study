struct 
{
	HBITMAP hbm;
	BITMAP bm;
}bmp[4][14],bmk,bkg;
HBITMAP Hbm;
struct Poker 
{
	int F;//标识是否有牌，1表示有牌
	int flag;//牌的状态,1表示正面
	int x;//牌的花色
	int y;//牌的点数
};
Poker pk1[10][11];//初始牌局
struct PokerState
{
	Poker pk[10][29];
	int num[10];//记录每一列的牌数
	POINT Pt[10][29];
	Poker pr[10][5];
	int T;
};//牌局记录
PokerState PS[50];
struct MovePoker
{
	int X,Y,sx,sy;
	int Num;
	POINT pm;
};
MovePoker MP;
struct WIN
{ 
	int x;
	int k;
};
WIN Win[8];
struct Mention
{
	int x;
	int y;
	int k;
};
Mention PT;
HPEN hp1,hp2;
HBRUSH hbr1,hbr2;
HFONT hf;
HDC hdcmem,hdcm;
POINT pt[10];
HINSTANCE hist;
HMENU hmenu;
HACCEL hac;
HWND hwnd;
int BFlag=0;//开始游戏标识
int LFlag=0;//级别标识
int YFlag=1;//是否的标识
int MFlag=0;//移动标识
int DFlag=0,Df;
int WFlag=0;
int MTFlag=0;
int Dnum=0;
int NUM;//计数
int Time;
LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,WPARAM wparam,LPARAM lparam);
BOOL CALLBACK DlgProc(HWND hdlg,UINT msg,WPARAM wparam,LPARAM lparam);
BOOL InitWindow(HINSTANCE hinstance,int cmd)
{
	hwnd=CreateWindow("Game","蜘蛛纸牌",WS_OVERLAPPEDWINDOW,31,0,1304,740,NULL,NULL,hinstance,NULL);
	if(!hwnd)
		return FALSE;
	ShowWindow(hwnd,cmd);
	UpdateWindow(hwnd);
	return TRUE;
}
BOOL InitWndClass(HINSTANCE hinstance)
{
	WNDCLASS wnd;
	wnd.style=0;
	wnd.lpfnWndProc=WndProc;
	wnd.cbClsExtra=0;
	wnd.cbWndExtra=0;
	wnd.hCursor=LoadCursor(NULL,IDC_ARROW);
	wnd.hIcon=LoadIcon(hinstance,"RD");
	wnd.hbrBackground=0;
	wnd.hInstance=hinstance;
	wnd.lpszMenuName="menu";
	wnd.lpszClassName="Game";
	return RegisterClass(&wnd);
}
void InitFuction(HINSTANCE hinstance)
{
	int i,j,k;
	char *str="BACK";
	char *str1[4]={"HT_","HX_","MH_","FK_"};
	char *str2[13]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
	char c[15];
	for(i=0;i<4;i++)
		for(j=0;j<13;j++)
		{
			for(k=0;str1[i][k]!='\0';k++)
				c[k]=str1[i][k];
			c[k]='\0';
			bmp[i][j+1].hbm=LoadBitmap(hinstance,strcat(c,str2[j]));
			GetObject(bmp[i][j+1].hbm,sizeof(BITMAP),(LPVOID)&bmp[i][j+1].bm);
		}
	bmk.hbm=LoadBitmap(hinstance,str);
	GetObject(bmk.hbm,sizeof(BITMAP),(LPVOID)&bmk.bm);
	bkg.hbm=LoadBitmap(hinstance,"BKG");
	GetObject(bkg.hbm,sizeof(BITMAP),(LPVOID)&bkg.bm);
	//加载位图
	hp1=CreatePen(PS_SOLID,0,RGB(0,153,51));
	hbr1=CreateSolidBrush(RGB(0,153,51));
	hp2=(HPEN)GetStockObject(BLACK_PEN);
	hbr2=CreateSolidBrush(RGB(0,127,0));
	hf=CreateFont(20,0,0,0,500,0,0,0,GB2312_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_DONTCARE,"楷体_GB2312");
	hac=LoadAccelerators(hinstance,"Amenu");
	hmenu=LoadMenu(hinstance,"menu");
	hist=hinstance;
	for(i=0;i<10;i++)
	{
		pt[i].x=54*(i+1)+71*i;
		pt[i].y=10;
	}	 
	srand((unsigned) time(NULL)); 
}
void InitPoker()
{//初始化
	int i,j,k;
	int x1,x2;
	for(i=0;i<10;i++)
		for(j=0;j<11;j++)
			pk1[i][j].F=0;	
	for(i=0;i<LFlag;i++)
		for(j=1;j<14;j++)
		{
			for(k=0;k<8/LFlag;k++)
			{
				while(1)
				{
					x1=rand()%10;
					if(x1<4)
						x2=rand()%11;
					else
						x2=rand()%10+1;
					if(pk1[x1][x2].F==0)
					{
						pk1[x1][x2].x=i;
						pk1[x1][x2].y=j;
						pk1[x1][x2].F=1;
						if(x2==5)
							pk1[x1][x2].flag=1;
						break;
					}
				}
			}
		}
}
void GetPoker()
{//获得牌局
	int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<29;j++)
			PS[0].pk[i][j].F=0;
	for(i=0;i<10;i++)
	{
		if(i<4)
		    PS[0].num[i]=6;
		else
			PS[0].num[i]=5;
		for(j=0;j<6;j++)
		{
			if(i<4)	
				PS[0].pk[i][j]=pk1[i][j];
			else if(j!=5)
				PS[0].pk[i][j]=pk1[i][j+1];
			PS[0].Pt[i][j].x=pt[i].x;
			PS[0].Pt[i][j].y=pt[i].y+8*j;
		}
		for(;j<11;j++)
			PS[0].pr[i][j-6]=pk1[i][j];
	}
	PS[0].T=5;
	BFlag=0;
	WFlag=0;
	MTFlag=0;
	Dnum=0;
	NUM=0;
	Time=0;
	PT.x=0;
	PT.y=-1;
}
int GameWin(int k)
{
	int i,t=2;
	i=PS[NUM].num[k]-1;
	if(PS[NUM].pk[k][i].y==1)
	{
		for(i--;i>=0;i--)
			if(PS[NUM].pk[k][i].x==PS[NUM].pk[k][i+1].x&&PS[NUM].pk[k][i].y==t)
				t++;
			else
				break;
		if(t==14)
		{
			i=PS[NUM].num[k]-1;
			Win[WFlag].x=PS[NUM].pk[k][i].x;
			Win[WFlag].k=k;
			return 13;
		}
		else
			return 0;
	}
	else 
		return 0;
}







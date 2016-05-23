#include <windows.h>
#include <stdio.h>  
#include <ddraw.h>
#include "graphics.h"
#include "globals.h"

extern int fullscreen;
extern int xres, yres;

static LPDIRECTDRAW lpDD_Init;
static LPDIRECTDRAW7 lpDD;
static LPDIRECTDRAWSURFACE7 lpDDS_Primary;
static LPDIRECTDRAWSURFACE7 lpDDS_Flip;
static LPDIRECTDRAWSURFACE7 lpDDS_Back;
static LPDIRECTDRAWCLIPPER lpDDC_Clipper;

int Flag_Clr_Scr = 0;

HRESULT RestoreGraphics();
int Clear_Primary_Screen(HWND hWnd);
int Clear_Back_Screen(HWND hWnd);

//释放DD对象, DD主页面及副页面(全屏VSync), 裁减器(窗口时), 及离屏页面
void End_DDraw(){
	if (lpDDC_Clipper){
		lpDDC_Clipper->Release();
		lpDDC_Clipper = NULL;
	}

	if (lpDDS_Back){
		lpDDS_Back->Release();
		lpDDS_Back = NULL;
	}

	if (lpDDS_Flip)
	{
		lpDDS_Flip->Release();
		lpDDS_Flip = NULL;
	}

	if (lpDDS_Primary){
		lpDDS_Primary->Release();
		lpDDS_Primary = NULL;
	}

	if (lpDD){
		lpDD->SetCooperativeLevel(g_hwnd, DDSCL_NORMAL);
		lpDD->Release();
		lpDD = NULL;
	}
}

//DD初始化
//(建立DD对象, DD主页面及副页面(全屏VSync), 裁减器(窗口时), 及离屏页面)
//出口: 0=失败  非0=成功
int Init_DDraw(HWND hWnd){
	HRESULT rval;
	DDSURFACEDESC2 ddsd;

	End_DDraw();
	
	//建立临时DD对象
	if (DirectDrawCreate(NULL, &lpDD_Init, NULL) != DD_OK)
		return 0;

	//DD对象使用DirectDraw7
	if (lpDD_Init->QueryInterface(IID_IDirectDraw7, (LPVOID *) &lpDD) != DD_OK)
		return 0;

	//临时DD对象释放
	lpDD_Init->Release();
	lpDD_Init = NULL;

	rval = lpDD->SetCooperativeLevel(hWnd, DDSCL_NORMAL);

	if (rval != DD_OK)
		return 0;

	//建立DD主页面
	memset(&ddsd, 0, sizeof(ddsd));
	ddsd.dwSize = sizeof(ddsd);

	ddsd.dwFlags = DDSD_CAPS;
	ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;

	if (lpDD->CreateSurface(&ddsd, &lpDDS_Primary, NULL ) != DD_OK)
		return 0;

	//需建立裁减器lpDDC_Clipper, 并设置到主页面
	if (lpDD->CreateClipper(0, &lpDDC_Clipper, NULL ) != DD_OK)
		return 0;

	if (lpDDC_Clipper->SetHWnd(0, hWnd) != DD_OK)
		return 0;

	if (lpDDS_Primary->SetClipper(lpDDC_Clipper) != DD_OK)
		return 0;

	//建立离屏页面lpDDS_Back
	memset(&ddsd, 0, sizeof(ddsd));
	ddsd.dwSize = sizeof(ddsd);
	ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;

	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
	ddsd.dwWidth = SCREEN_W;
	ddsd.dwHeight = SCREEN_H;

	if (lpDD->CreateSurface(&ddsd, &lpDDS_Back, NULL) != DD_OK)
		return 0;

	return 1;
}

//DD全屏初始化
//出口: 0=失败  非0=成功
int Init_DDraw_FS(HWND hWnd){
	HRESULT rval;
	DDSURFACEDESC2 ddsd;

	End_DDraw();
	
	//建立临时DD对象
	if (DirectDrawCreate(NULL, &lpDD_Init, NULL) != DD_OK)
		return 0;

	//DD对象使用DirectDraw7
	if (lpDD_Init->QueryInterface(IID_IDirectDraw7, (LPVOID *) &lpDD) != DD_OK)
		return 0;

	//临时DD对象释放
	lpDD_Init->Release();
	lpDD_Init = NULL;

	rval = lpDD->SetCooperativeLevel(hWnd, DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN);
	if (rval != DD_OK)
		return 0;

	if (lpDD->SetDisplayMode(640, 480, 16, 0, 0) != DD_OK)
		return 0;

	memset(&ddsd, 0, sizeof(ddsd));
	ddsd.dwSize = sizeof(ddsd);
	ddsd.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
	ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE | DDSCAPS_FLIP | DDSCAPS_COMPLEX;
	ddsd.dwBackBufferCount = 2;
	if (lpDD->CreateSurface(&ddsd, &lpDDS_Primary, NULL ) != DD_OK)
		return 0;

	ddsd.ddsCaps.dwCaps = DDSCAPS_BACKBUFFER;
	if (lpDDS_Primary->GetAttachedSurface(&ddsd.ddsCaps, &lpDDS_Flip) != DD_OK)
		return 0;

	memset(&ddsd, 0, sizeof(ddsd));
	ddsd.dwSize = sizeof(ddsd);
	ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
	ddsd.dwWidth = SCREEN_W;
	ddsd.dwHeight = SCREEN_H;
	if (lpDD->CreateSurface(&ddsd, &lpDDS_Back, NULL) != DD_OK)
		return 0;

	return 1;
}

//恢复DD主页面及离屏页面
HRESULT RestoreGraphics(){
	HRESULT rval;

	rval = lpDDS_Primary->Restore();
	rval = lpDDS_Back->Restore();
	//Clear_Primary_Screen(g_hwnd);
	//Clear_Back_Screen(g_hwnd);

	return rval;
}

//清屏 (清主页面(及2个副页面))
int Clear_Primary_Screen(HWND hWnd){
	DDBLTFX ddbltfx;	//用于blt
	RECT RD;
	POINT p;

	memset(&ddbltfx, 0, sizeof(ddbltfx));
	ddbltfx.dwSize = sizeof(ddbltfx);
	ddbltfx.dwFillColor = 0; //填充色=黑

	if (fullscreen){
		lpDDS_Flip->Blt(NULL, NULL, NULL, DDBLT_WAIT | DDBLT_COLORFILL, &ddbltfx);
		lpDDS_Primary->Flip(NULL, DDFLIP_WAIT);

		lpDDS_Flip->Blt(NULL, NULL, NULL, DDBLT_WAIT | DDBLT_COLORFILL, &ddbltfx);
		lpDDS_Primary->Flip(NULL, DDFLIP_WAIT);

		lpDDS_Flip->Blt(NULL, NULL, NULL, DDBLT_WAIT | DDBLT_COLORFILL, &ddbltfx);
		lpDDS_Primary->Flip(NULL, DDFLIP_WAIT);
	}else{
		//用填充方式的blt实现清屏
		p.x = p.y = 0;
		GetClientRect(hWnd, &RD);
		ClientToScreen(hWnd, &p);

		RD.left = p.x;
		RD.top = p.y;
		RD.right += p.x;
		RD.bottom += p.y;

		if (RD.top < RD.bottom)
			lpDDS_Primary->Blt(&RD, NULL, NULL, DDBLT_WAIT | DDBLT_COLORFILL, &ddbltfx);
	}

	return 1;
}

//清离屏页面
int Clear_Back_Screen(HWND hWnd){
	DDBLTFX ddbltfx;

	memset(&ddbltfx, 0, sizeof(ddbltfx));
	ddbltfx.dwSize = sizeof(ddbltfx);
	ddbltfx.dwFillColor = 0;

	lpDDS_Back->Blt(NULL, NULL, NULL, DDBLT_WAIT | DDBLT_COLORFILL, &ddbltfx);

	return 1;
}

int Flip(HWND hWnd){
	HRESULT rval;
	RECT RectDest, RectSrc;
	POINT p;
	DDSURFACEDESC2 ddsd;

	ddsd.dwSize = sizeof(ddsd);

	rval =lpDDS_Back->Lock(NULL, &ddsd, DDLOCK_WAIT, NULL);
	if (rval == DDERR_SURFACELOST)
		RestoreGraphics();

	nesBlit((unsigned char *) ddsd.lpSurface, ddsd.lPitch);
	lpDDS_Back->Unlock(NULL);

	RectSrc.left = 0;
	RectSrc.right = SCREEN_W;
	RectSrc.top = 0;
	RectSrc.bottom = SCREEN_H;

	if (fullscreen){
		RectDest.left = 0;
		RectDest.right = 640;

		RectDest.top = 0;
		RectDest.bottom = 480;

		rval=lpDDS_Flip->Blt(&RectDest, lpDDS_Back, &RectSrc, DDBLT_WAIT | DDBLT_ASYNC, NULL);
		if (rval == DDERR_SURFACELOST) rval = RestoreGraphics();
		lpDDS_Primary->Flip(NULL, DDFLIP_WAIT);
	}//if (fullscreen)
	else{
		p.x = p.y = 0;
		GetClientRect(hWnd, &RectDest);
		ClientToScreen(hWnd, &p);

		RectDest.left = p.x;
		RectDest.top = p.y;
		RectDest.right += p.x;
		RectDest.bottom += p.y;

		if (RectDest.left<0){
			RectSrc.left = (-RectDest.left)>>1;
			RectDest.left =0;
		}else if (RectDest.right>xres){
			RectSrc.right -= (RectDest.right-xres)>>1;
			RectDest.right =xres;
		}

		if (RectDest.top<0){
			RectSrc.top = (-RectDest.top)>>1;
			RectDest.top =0;
		}else if (RectDest.bottom>yres){
			RectSrc.bottom -= (RectDest.bottom-yres)>>1;
			RectDest.bottom =yres;
		}

		int vb;
		lpDD->GetVerticalBlankStatus(&vb);
		if (!vb) lpDD->WaitForVerticalBlank(DDWAITVB_BLOCKBEGIN, 0);

		rval = lpDDS_Primary->Blt(&RectDest, lpDDS_Back, &RectSrc, DDBLT_WAIT | DDBLT_ASYNC, NULL);
		if (rval == DDERR_SURFACELOST) rval = RestoreGraphics();
	}


	return 1;
}

static void getbitmask(unsigned val, int* pshift, int* pbits){
	*pshift = 0;
	while( !(val & (1<<*pshift)) && (*pshift<32) ) {
		(*pshift)++;
	}

	*pbits = 32;
	while( !(val & (1<<(*pbits-1))) && (*pbits>0) ) {
		(*pbits)--;
	}
	*pbits = *pbits - *pshift;
}

void get_loss_shift(int *rloss, int *rsft, int *gloss, int *gsft, int *bloss, int *bsft){
	DDSURFACEDESC2	ddsd;
	int sft, bit;

	memset( &ddsd, 0, sizeof(DDSURFACEDESC2) );
	ddsd.dwSize = sizeof(DDSURFACEDESC2);
	ddsd.dwFlags = DDSD_PIXELFORMAT;

	lpDDS_Primary->GetSurfaceDesc(&ddsd);
	getbitmask( ddsd.ddpfPixelFormat.dwRBitMask, &sft, &bit );
	*rloss =8-bit;
	*rsft =sft;
	getbitmask( ddsd.ddpfPixelFormat.dwGBitMask, &sft, &bit );
	*gloss =8-bit;
	*gsft =sft;
	getbitmask( ddsd.ddpfPixelFormat.dwBBitMask, &sft, &bit );
	*bloss =8-bit;
	*bsft =sft;
}

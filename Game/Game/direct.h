#pragma once
#include "DirectHeader.h"
#include "Defines.h"
#include "DirectHeader.h"


class CDirect
{
	DECLARE_SINGLETON(CDirect)

private:
	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pDevice;
	

	LPD3DXSPRITE m_pSprite;
	LPDIRECT3DTEXTURE9 m_pTexture;;

public:
	HRESULT InitD3D(HWND hWnd);

	void Render_Begin();
	void Render_End();
	void CleanUp();


	void DrawRectangle(RECT rc);

	void DrawLine(int a, int b, int x, int y);
	LPDIRECT3DDEVICE9 GetDevice();
	LPD3DXSPRITE GetSprite();
};

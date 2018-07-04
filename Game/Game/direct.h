#pragma once
#include <d3d9.h>
#include <d3dx9core.h>
class CDraw;
class CDirect
{
private:
	LPDIRECT3D9 pD3D;
	LPDIRECT3DDEVICE9 pDevice;
	CDraw* Draw;
	LPD3DXSPRITE pSprite;
	LPDIRECT3DTEXTURE9 pTexture;;

public:
	HRESULT InitD3D(HWND hWnd);
	void Render_Begin();
	void Render_End();
	void CleanUp();

	CDirect();
	~CDirect();

};

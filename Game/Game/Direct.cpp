
#include "stdafx.h"
#include "Direct.h"
#include<d3d9.h>
#include<d3dx9core.h>

IMPLEMENT_SINGLETON(CDirect)

HRESULT CDirect::InitD3D(HWND hWnd)
{

	pD3D = NULL;
	pDevice = NULL;

	pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (pD3D == NULL)
	{
		return E_FAIL;
	}


	D3DDISPLAYMODE d3ddm;
	if (FAILED(pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm)))
		return E_FAIL;


	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect=D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = d3ddm.Format;

	if (FAILED(pD3D->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&pDevice)))
		return E_FAIL;
	

	
	
	if(FAILED(D3DXCreateSprite(pDevice, &pSprite)))
		return E_FAIL;

	if (FAILED(D3DXCreateTextureFromFile(pDevice, L"../\\Sprite\\User_center.png", &pTexture)))
		return E_FAIL;

	



	return S_OK;
}

void CDirect::Render_Begin()
{
	pDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 1.f, 0);

	pDevice->BeginScene();


	{
		RECT rect = { 0,0,100,100 };
		D3DXVECTOR3 vecPos = { 400,400,0 };
		pSprite->Begin(D3DXSPRITE_ALPHABLEND);
		pSprite->Draw(pTexture, NULL, NULL, &vecPos, D3DCOLOR_ARGB(255, 255, 255, 255));
		pSprite->End();
	}
}
	


void CDirect::Render_End()
{
	pDevice->EndScene();

	pDevice->Present(NULL, NULL, NULL, NULL);
}

void CDirect::CleanUp()
{
	if (pDevice != NULL)
		delete pDevice;
	if (pD3D != NULL)
		delete pD3D;
}

LPDIRECT3DDEVICE9 CDirect::GetDevice()
{
	return pDevice;
}


CDirect::CDirect()
{

}

CDirect::~CDirect()
{
}
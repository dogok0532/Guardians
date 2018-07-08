

#include "Direct.h"

IMPLEMENT_SINGLETON(CDirect)

HRESULT CDirect::InitD3D(HWND hWnd)
{

	m_pD3D = NULL;
	m_pDevice = NULL;

	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (m_pD3D == NULL)
	{
		return E_FAIL;
	}


	D3DDISPLAYMODE d3ddm;
	if (FAILED(m_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm)))
		return E_FAIL;


	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect=D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = d3ddm.Format;

	if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&m_pDevice)))
		return E_FAIL;
	

	
	
	if(FAILED(D3DXCreateSprite(m_pDevice, &m_pSprite)))
		return E_FAIL;

	if (FAILED(D3DXCreateTextureFromFile(m_pDevice, L"../\\Sprite\\User_center.png", &m_pTexture)))
		return E_FAIL;

	



	return S_OK;
}

void CDirect::Render_Begin()
{
	m_pDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 1.f, 0);

	m_pDevice->BeginScene();
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
}
	


void CDirect::Render_End()
{
	m_pSprite->End();
	m_pDevice->EndScene();

	m_pDevice->Present(NULL, NULL, NULL, NULL);
}

void CDirect::CleanUp()
{
	if (m_pDevice != NULL)
		delete m_pDevice;
	if (m_pD3D != NULL)
		delete m_pD3D;
}

void CDirect::DrawRectangle(RECT rc)
{
	m_pSprite->End();

	HRESULT hr = CDirect::GetInstance()->GetDevice()->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
	struct Vertex {
		float x, y, z, w; // D3DFVF_XYZRHW 위치정보
		D3DCOLOR color = D3DCOLOR_ARGB(255,0,0,0); // D3DFVF_DIFFUSE 색깔
	};
	Vertex v[4] = { { rc.left, rc.top, 1.f},
	{ rc.right, rc.top, 1.f },
	{ rc.left, rc.bottom, 1.f },
	{ rc.right, rc.bottom, 1.f}
	};
	hr = CDirect::GetInstance()->GetDevice()->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, v, 20);
	if (FAILED(hr))
	{
		return;
	}
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);


		
}

LPDIRECT3DDEVICE9 CDirect::GetDevice()
{
	return m_pDevice;
}


LPD3DXSPRITE CDirect::GetSprite()
{
	return m_pSprite;
}

CDirect::CDirect()
{

}

CDirect::~CDirect()
{
	m_pD3D->Release();
	m_pDevice->Release();
}
#include "Texture.h"

#include "direct.h"





LPD3DXSPRITE CTexture::m_pSprite;

void CTexture::SetPos(D3DXVECTOR3 vecPos)
{
	m_vecPos = vecPos;
}

void CTexture::SetPos(float x, float y, float z/*=0*/)
{
	m_vecPos = { x,y,z };
}

void CTexture::SetRenderSizeRatio(D3DXVECTOR3 vecPos)
{

}

void CTexture::SetRenderSizeRatio(float x, float y, float z /*= 0*/)
{

}

void CTexture::SetRenderSize(D3DXVECTOR3 vecPos)
{

}

void CTexture::SetRenderSize(float x, float y, float z /*= 0*/)
{

}

D3DXVECTOR3 CTexture::GetSize()
{
	return m_vecSize;
}

void CTexture::Render()
{

	m_pSprite->Draw(m_pTexture, NULL, &(m_vecSize / 2), &m_vecPos, DEFAULT_COLOR);
	

	
}

void CTexture::Release()
{
	m_pTexture->Release();
}

CTexture::CTexture(wstring fileName)
{

	HRESULT hr;
	
	D3DXIMAGE_INFO ImageInfo;

	hr = D3DXGetImageInfoFromFile(fileName.c_str(), &ImageInfo);
	m_vecSize = { (float)ImageInfo.Width, (float)ImageInfo.Height, 0 };

	if (FAILED(hr))
	{
		return;
	}

	
	hr = D3DXCreateTextureFromFileEx(CDirect::GetInstance()->GetDevice(),
		fileName.c_str(),
		ImageInfo.Width,
		ImageInfo.Height,
		1,0,
		ImageInfo.Format,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_ARGB(255,255,255,255),
		NULL,
		NULL,
		&m_pTexture);

	if (FAILED(hr))
	{
		return;
	}

	m_pSprite = CDirect::GetInstance()->GetSprite();

}

CTexture::~CTexture()
{
}

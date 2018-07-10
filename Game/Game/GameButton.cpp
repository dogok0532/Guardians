#include "GameButton.h"
#include "SpriteResource.h"


void CGameButton::Update(float deltaTime)
{

}

void CGameButton::Render()
{
	LPDIRECT3DTEXTURE9 pTexture;

	if(m_bButtonState)
		pTexture = CSpriteResource::GetInstance()->GetTextureInfo(L"Button").pTexture;
	else
		pTexture = CSpriteResource::GetInstance()->GetTextureInfo(L"Button2").pTexture;

	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = m_vecImage[0].ImageInfo.Width;
	rc.bottom = m_vecImage[0].ImageInfo.Height;

	

	m_pSprite->Draw(pTexture, &rc, &m_vecCenter,&m_vecPos, D3DCOLOR_ARGB(255, 255, 255, 255));

}

void CGameButton::SetButtonName(wstring str)
{
	m_strButtonName = str;
}

CGameButton::CGameButton()
{
	m_vecImage.push_back(CSpriteResource::GetInstance()->GetTextureInfo(L"Button"));
	m_vecImage.push_back(CSpriteResource::GetInstance()->GetTextureInfo(L"Button2"));
	
	SetSizeToTextureSize();

}


CGameButton::~CGameButton()
{
}

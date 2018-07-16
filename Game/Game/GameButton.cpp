#include "GameButton.h"
#include "SpriteResource.h"
#include "TextManager.h"

#include "Mouse.h"

void CGameButton::Update(float deltaTime)
{
	
}

void CGameButton::Render()
{
	m_vecImage[m_iFrame]->SetPos(m_vecPos);
	m_vecImage[m_iFrame]->Render();


	CTextManager::GetInstance()->SetText(m_strButtonName);
	CTextManager::GetInstance()->SetTextRange(m_vecPos.x - m_vecSize.x / 2,
		m_vecPos.y - m_vecSize.y / 2,
		m_vecPos.x + m_vecSize.x / 2,
		m_vecPos.y + m_vecSize.y / 2);
	CTextManager::GetInstance()->SetColor(D3DCOLOR_ARGB(255, 0, 0, 0));
	CTextManager::GetInstance()->Render();
}

bool CGameButton::Destroy()
{
	return false;
}

void CGameButton::SetButtonName(wstring str)
{
	m_strButtonName = str;
}

void CGameButton::SetUIState(CMouse* mouse)
{
	D3DXVECTOR3 vecMouse = mouse->GetPos();

	RECT rc;
	rc.left = m_vecPos.x - m_vecSize.x / 2;
	rc.top = m_vecPos.y - m_vecSize.y / 2;
	rc.right = m_vecPos.x + m_vecSize.x / 2;
	rc.bottom = m_vecPos.y + m_vecSize.y / 2;

	if (vecMouse.x >= rc.left &&
		vecMouse.y >= rc.top &&
		vecMouse.x <= rc.right &&
		vecMouse.y <= rc.bottom)
	{
		m_iFrame = 1;

		{
			if (mouse->bClicked())
			{
				m_iButtonClicked = 1;
			}
		}
	}
	else
		m_iFrame = 0;



}

	

bool CGameButton::ButtonClicked()
{
	return m_iButtonClicked;
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

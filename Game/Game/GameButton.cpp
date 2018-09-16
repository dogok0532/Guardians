#include "GameButton.h"
#include "SpriteResource.h"
#include "Text.h"
#include "MainGame.h"
#include "Mouse.h"

void CGameButton::Update(float deltaTime)
{
	pText->SetText(m_strButtonName);
	pText->SetTextRange(
		m_GameInfo.vecPos.x - m_GameInfo.vecSize.x / 2,
		m_GameInfo.vecPos.y - m_GameInfo.vecSize.y / 2,
		m_GameInfo.vecPos.x + m_GameInfo.vecSize.x / 2,
		m_GameInfo.vecPos.y + m_GameInfo.vecSize.y / 2);
	pText->SetColor(D3DCOLOR_ARGB(255, 0, 0, 0));

	CGameObject::Update(deltaTime);
}

void CGameButton::Render()
{
	
	if (m_iFrame == 0)
		CMainGame::GetInstance()->GetSpriteResource()->RenderWholeTexture(L"Button", &m_GameInfo);
	else
		CMainGame::GetInstance()->GetSpriteResource()->RenderWholeTexture(L"Button2", &m_GameInfo);


	pText->Render();

	
}

bool CGameButton::Destroy()
{
	return false;
}

void CGameButton::SetButtonName(wstring str)
{
	m_strButtonName = str;
}

void CGameButton::SetUIState(CMouse* mouse)	// 마우스를 UI위에 두면 상태변경
{
	m_iButtonClicked = false;
	D3DXVECTOR3 vecMouse = mouse->GetPos();

	RECT rc;
	rc.left = m_GameInfo.vecPos.x - m_GameInfo.vecSize.x / 2;
	rc.top = m_GameInfo.vecPos.y - m_GameInfo.vecSize.y / 2;
	rc.right = m_GameInfo.vecPos.x + m_GameInfo.vecSize.x / 2;
	rc.bottom = m_GameInfo.vecPos.y + m_GameInfo.vecSize.y / 2;

	if (vecMouse.x >= rc.left &&
		vecMouse.y >= rc.top &&
		vecMouse.x <= rc.right &&
		vecMouse.y <= rc.bottom)		//마우스가 버튼안에 들어왔을떄
	{
		m_iFrame = 1;

		{
			if (mouse->bClicked())		//마우스가 클릭되었을때
			{
				m_iButtonClicked = 1;  // 옵저버 패턴 구현했을때 전달하는 시점
			}
		}
	}
	else
	{
		m_iFrame = 0;
		
	}


}

	

bool CGameButton::ButtonClicked()
{
	return m_iButtonClicked;
}

CGameButton::CGameButton()
{
	m_vecImage.push_back(CMainGame::GetInstance()->
		GetSpriteResource()->GetTextureInfo(L"Button"));

	m_vecImage.push_back(CMainGame::GetInstance()->
		GetSpriteResource()->GetTextureInfo(L"Button2"));
	
	SetInfoToTexture();

	pText = new CText;
	pText->Init();
	pText->SetText(m_strButtonName);
	

}


CGameButton::~CGameButton()
{
	if (pText)
	{
		pText->Release();
	}
}


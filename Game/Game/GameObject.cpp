
#include "GameObject.h"
#include "direct.h"
#include "MainGame.h"






void CGameObject::Draw(wstring textureName, wstring spriteName, int Frame)
{
	CMainGame::GetInstance()->GetSpriteResource()->Draw(textureName,spriteName, Frame);
}

void CGameObject::Update(float deltaTime)
{
	
	
}


void CGameObject::Render()
{
	if (!m_vecImage.empty())
	{
		m_vecImage[m_iFrame]->SetInfo(&m_GameInfo);
		m_vecImage[m_iFrame]->Render();
	}
		
}

void CGameObject::SetInfoToTexture()	//게임오브젝트의 크기를 텍스처 크기에 맞춘다.
{

	if (!m_vecImage.empty())
	{
		m_GameInfo.vecSize = m_vecImage[0]->GetSize();
	}
	
}

void CGameObject::SetPos(D3DXVECTOR3 vecPos)
{
	m_GameInfo.vecPos = vecPos;
}

void CGameObject::SetPos(float x, float y,float z)
{
	m_GameInfo.vecPos.x = x;
	m_GameInfo.vecPos.y = y;
	m_GameInfo.vecPos.z = z;
}


D3DXVECTOR3 CGameObject::GetPos()
{
	return m_GameInfo.vecPos;
}

RECT CGameObject::GetRect()
{
	RECT rc = { m_GameInfo.vecPos.x -m_GameInfo.vecSize.x / 2,
		m_GameInfo.vecPos.y - m_GameInfo.vecSize.y / 2,
		m_GameInfo.vecPos.x + m_GameInfo.vecSize.x / 2,
		m_GameInfo.vecPos.y + m_GameInfo.vecSize.y / 2 };

	return rc;
}

void CGameObject::SetAngle(float Angle)
{
	m_GameInfo.fDirection = Angle;
}

CGameObject::CGameObject()
{
	SetInfoToTexture();
	
}


CGameObject::~CGameObject()
{
	
	m_vecImage.clear();

}

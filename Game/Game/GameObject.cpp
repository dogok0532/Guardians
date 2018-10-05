
#include "GameObject.h"
#include "direct.h"
#include "MainGame.h"






void CGameObject::DrawFrame()
{
	CMainGame::GetInstance()->GetSpriteResource()->Render(m_strTextureName, m_strSpriteName, m_iFrame, &m_GameInfo);
}

void CGameObject::DrawSprite()
{
	CMainGame::GetInstance()->GetSpriteResource()->RenderWholeSprite(m_strTextureName, m_strSpriteName,&m_GameInfo);
}

void CGameObject::DrawTexture()
{
	CMainGame::GetInstance()->GetSpriteResource()->RenderWholeTexture(m_strTextureName, &m_GameInfo);
}


void CGameObject::SetSizeAsSprite(wstring textureName, wstring spriteName)
{
		m_GameInfo.vecSize = CMainGame::GetInstance()->
			GetSpriteResource()->
			GetSpriteSize(textureName, spriteName);

}

void CGameObject::SetSizeAsSprite()
{
	m_GameInfo.vecSize = CMainGame::GetInstance()->GetSpriteResource()->GetSpriteSize(m_strTextureName, m_strSpriteName);
}

void CGameObject::Update(float deltaTime)
{
	
	
}


void CGameObject::Render()
{
	DrawFrame();
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
	RECT rc = { m_GameInfo.vecPos.x -m_GameInfo.vecSize.x / 2.f,
		m_GameInfo.vecPos.y - m_GameInfo.vecSize.y / 2.f,
		m_GameInfo.vecPos.x + m_GameInfo.vecSize.x / 2.f,
		m_GameInfo.vecPos.y + m_GameInfo.vecSize.y / 2.f };

	return rc;
}

void CGameObject::SetAngle(float Angle)
{
	m_GameInfo.fRenderDirection = Angle;
}









CGameObject::CGameObject()
{

	
}


CGameObject::~CGameObject()
{
	


}

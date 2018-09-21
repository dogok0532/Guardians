
#include "GameObject.h"
#include "direct.h"
#include "MainGame.h"






void CGameObject::Draw(wstring textureName, wstring spriteName, int Frame)
{
	CMainGame::GetInstance()->GetSpriteResource()->Render(textureName,spriteName, Frame,&m_GameInfo);
}

void CGameObject::Draw(wstring textureName, wstring spriteName)
{
	CMainGame::GetInstance()->GetSpriteResource()->Render(textureName, spriteName, m_iFrame, &m_GameInfo);

}

void CGameObject::Draw(int iFrame)
{
	CMainGame::GetInstance()->GetSpriteResource()->Render(m_strTextureName, m_strSpriteName, m_iFrame, &m_GameInfo);
}

void CGameObject::Draw()
{
	CMainGame::GetInstance()->GetSpriteResource()->Render(m_strTextureName, m_strSpriteName, m_iFrame, &m_GameInfo);
}

void CGameObject::DrawWholeTexture(wstring textureName)
{
	CMainGame::GetInstance()->GetSpriteResource()->RenderWholeTexture(textureName, &m_GameInfo);
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

bool CGameObject::isOutOfScreen()
{

	if (m_GameInfo.vecPos.x < -200 || m_GameInfo.vecPos.y <-200 || m_GameInfo.vecPos.x > WINCX + 200 || m_GameInfo.vecPos.y > WINCY + 200)
		return true;
	else
		return false;
}

void CGameObject::SetAdjustIngame()
{
	m_GameInfo.vecPos.x += (WINCX - GAMESIZE_X) / 2;
} 

void CGameObject::ResetAdjustIngame()
{
	m_GameInfo.vecPos.x -= (WINCX - GAMESIZE_X) / 2;
}

bool CGameObject::Spawn(float fTimePassed)
{
	if (m_fSpawnTime <= fTimePassed * 10)
	{
		return true;
	}
	return false;
}




void CGameObject::SetSpawnInformation(float fX, float fY, float SpawnTime, float fRenderDirection, float fMovingDirection, int iPattern, float fSpeed, bool bMoveByGround)
{
	m_GameInfo.vecPos = { fX,fY,0 };
	m_fSpawnTime = m_fSpawnTime;
	m_fMovingDirection = fMovingDirection;
	m_fSpeed = fSpeed;
	m_bMoveByBackground = bMoveByGround;
	m_GameInfo.fRenderDirection = fRenderDirection;
}

CGameObject::CGameObject()
{

	
}


CGameObject::~CGameObject()
{
	


}

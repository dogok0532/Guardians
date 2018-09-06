#include "EnemyPlane.h"

#include "MainGame.h"



void CEnemyPlane::Update(float deltaTime)
{
	
	
	m_GameInfo.vecPos.y += 100 * deltaTime;

	CEnemy::Update(deltaTime);
	
}

void CEnemyPlane::Render()
{
	CEnemy::Render();
}

bool CEnemyPlane::Destroy()
{
	if (m_GameInfo.vecPos.x < -200 || m_GameInfo.vecPos.y <-200 || m_GameInfo.vecPos.x > WINCX + 200 || m_GameInfo.vecPos.y > WINCY + 200)
		return true;
	
	
	return false;
}

CEnemyPlane::CEnemyPlane()
{
	
	m_vecImage.push_back(
		CMainGame::GetInstance()->
		GetSpriteResource()->GetTextureInfo(L"Enemy_Helicpoter_Clear"));
	
	SetInfoToTexture();
}


CEnemyPlane::~CEnemyPlane()
{
}


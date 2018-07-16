#include "Enemy.h"





void CEnemy::Update(float deltaTime)
{
	
	m_vecPos.y += 100 * deltaTime;
	
}

void CEnemy::Render()
{
	UpdatePos();
	m_vecImage[m_iFrame]->Render();
}

bool CEnemy::Destroy()
{
	return false;
}

CEnemy::CEnemy()
{
	
	m_vecImage.push_back(CSpriteResource::GetInstance()->GetTextureInfo(L"Enemy_Helicpoter_Clear"));
	
	SetSizeToTextureSize();
}


CEnemy::~CEnemy()
{
}

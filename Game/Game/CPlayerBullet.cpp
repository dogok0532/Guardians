#include "CPlayerBullet.h"
#include "SpriteResource.h"


void CPlayerBullet::Update(float deltaTime)
{
	
	m_vecPos += vecSpeed*deltaTime;

	
}

void CPlayerBullet::Render()
{
	UpdatePos();
	m_vecImage[0]->Render();
}


bool CPlayerBullet::Destroy()
{
	if (m_vecPos.x < -200 || m_vecPos.y <-200 || m_vecPos.x > WINCX + 200 || m_vecPos.y > WINCY + 200)
		return true;

	else
		return false;
}

CPlayerBullet::CPlayerBullet()
{

	m_vecImage.push_back(CSpriteResource::GetInstance()->GetTextureInfo(L"User_Missile"));
	vecSpeed = { 0,-500,0 };

	UpdateTextureInfo();
	
	SetSizeToTextureSize();
}


CPlayerBullet::~CPlayerBullet()
{
	
}

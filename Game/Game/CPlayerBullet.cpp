#include "CPlayerBullet.h"
#include "SpriteResource.h"


void CPlayerBullet::Update(float deltaTime)
{
	m_vecPos += vecSpeed*deltaTime;
}

void CPlayerBullet::Render()
{
	m_pSprite->Draw(m_vecImage[0], NULL, NULL, &m_vecPos, D3DCOLOR_ARGB(255, 255, 255, 255));

}


bool CPlayerBullet::Destroy()
{
	if (m_vecPos.x < -200 || m_vecPos.y <-200 || m_vecPos.x > WINCX +200 || m_vecPos.y > WINCY +200)
		return true;

	else
		return false;
}

CPlayerBullet::CPlayerBullet()
{

	m_vecImage.push_back(CSpriteResource::GetInstance()->GetImage(L"User_Missile"));
	vecSpeed = { 0,-500,0 };
}


CPlayerBullet::~CPlayerBullet()
{
	
}

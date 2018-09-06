#include "PlayerBullet.h"
#include "SpriteResource.h"
#include <math.h>
#include <D3dx9math.h>
#include "MainGame.h"

void CPlayerBullet::Update(float deltaTime)
{
	D3DXVECTOR3 MoveMent = {0,-1000,0};
	
	D3DXMATRIX mat;
	D3DXMatrixRotationZ(&mat, m_GameInfo.fDirection * DEGREE_TO_RADIAN);

	D3DXVec3TransformCoord(&MoveMent, &MoveMent, &mat);

	m_GameInfo.vecPos += MoveMent *deltaTime;

	CGameObject::Update(deltaTime);
}

void CPlayerBullet::Render()
{
	CGameObject::Render();
}


bool CPlayerBullet::Destroy()
{
	if (m_GameInfo.vecPos.x < -200 ||
		m_GameInfo.vecPos.y <-200 ||
		m_GameInfo.vecPos.x > WINCX + 200 ||
		m_GameInfo.vecPos.y > WINCY + 200)
		return true;

	else
		return false;
}




CPlayerBullet::CPlayerBullet()
{

	m_vecImage.push_back(CMainGame::GetInstance()->
		GetSpriteResource()->GetTextureInfo(L"User_Missile"));

	
	SetInfoToTexture();
	m_fSpeed = 1000;
}


CPlayerBullet::~CPlayerBullet()
{
	
}

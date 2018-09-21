#include "PlayerBullet.h"
#include "SpriteResource.h"
#include <math.h>
#include <D3dx9math.h>
#include "MainGame.h"
#include "GameObject.h"

void CPlayerBullet::Update(float deltaTime)
{
	D3DXVECTOR3 MoveMent = {0,-100,0};
	
	//--MoveMent의 기본속도를 100으로 맞추고 각도에 따라 이동벡터 변환
	D3DXMATRIX mat;
	D3DXMatrixRotationZ(&mat, m_GameInfo.fRenderDirection * DEGREE_TO_RADIAN);
	D3DXVec3TransformCoord(&MoveMent, &MoveMent, &mat);



	m_GameInfo.vecPos += MoveMent *deltaTime;

	CGameObject::Update(deltaTime);
}

void CPlayerBullet::Render()
{
	Draw(L"Player", L"Bullet_1",0 );
	
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

	
	m_GameInfo.vecSize = { 5,5,0 };

	m_fSpeed = 1000;
}


CPlayerBullet::~CPlayerBullet()
{
	
}

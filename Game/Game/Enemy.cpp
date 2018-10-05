#include "Enemy.h"
#include "MainGame.h"
#include "EnemyBullet.h"

CEnemy::CEnemy()
{
}


CEnemy::~CEnemy()
{
}

void CEnemy::Update(float deltaTime)
{
	CGameObject::Update(deltaTime);
}

CEnemyBullet* CEnemy::CreateBullet()
{
	CEnemyBullet* pBullet = new CEnemyBullet;
	pBullet->SetPos(m_GameInfo.vecPos);
	pBullet->SetAngle(0);
	

	return pBullet;

	return NULL;
}


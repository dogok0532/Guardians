#include "EnemyFighter.h"

#include "MainGame.h"



void CEnemyFighter::Update(float deltaTime)
{

	
	D3DXMATRIX matRot;
	D3DXMatrixRotationZ(&matRot, m_fMovingDirection * DEGREE_TO_RADIAN);
	D3DXVECTOR3 vecSpeed = {1,0,0};
	D3DXVec3TransformCoord(&vecSpeed, &vecSpeed, &matRot);
	vecSpeed *= (m_fSpeed * deltaTime);
	m_GameInfo.vecPos += vecSpeed;

	CEnemy::Update(deltaTime);
	
}

void CEnemyFighter::Render()
{
	
	Draw();


}



CEnemyFighter::CEnemyFighter()
{
	

	m_strTextureName = L"Enemy_Fighter";
	m_strSpriteName = L"F_18";
	SetSizeAsSprite();

	m_GameInfo.vecPos = { WINCX / 2,500,0 };

	
	m_fSpeed = 100;
	m_fMovingDirection = 90;
}


CEnemyFighter::~CEnemyFighter()
{
}


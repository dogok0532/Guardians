#include "BulletComponent.h"
#include "CircleComponent.h"
#include "2DSpriteComponent.h"
#include "GameObject.h"

CBulletComponent::CBulletComponent()
{
}


CBulletComponent::~CBulletComponent()
{
}

void CBulletComponent::Render()
{
	if(m_pSpriteComonent)
		m_pSpriteComonent->SetDrawFrame();
}

void CBulletComponent::Update(float deltaTime)
{
	D3DXMATRIX matRotate;
	D3DXVECTOR3 vecMovement = {m_fVelocity,0,1};

	D3DXMatrixRotationZ(&matRotate, m_fAngle / 180 * 3.141592);
	D3DXVec3TransformCoord(&vecMovement, &vecMovement, &matRotate);

	m_vecPos += vecMovement;
	m_fCurrentDistance +=D3DXVec3Length(&vecMovement);

	//발사방향에 따른 속도/벡터 조정 및 좌표 최신화

	if (m_fCurrentDistance > m_fMaxDistance)		//최대사거리에 도달할경우
	{
		m_pOwner->SetDead();	
	}

	if (m_pSpriteComonent)						
	{
		m_pSpriteComonent->SetPos(m_vecPos);
		m_pSpriteComonent->SetFrame(0);
	}
	else
	{
		m_pSpriteComonent = m_pOwner->getComponent<C2DSpriteComponent>();
		m_pSpriteComonent->SetTexture(L"Effect");
		m_pSpriteComonent->SetSprite(L"Effect1");
	}


	if (m_pCircleComponent)
	{
		m_pCircleComponent->SetPos(m_vecPos.x, m_vecPos.y);
	}
	else
	{
		m_pCircleComponent = m_pOwner->getComponent<CCircleComponent>();
		m_pCircleComponent->SetCircle(m_vecPos.x, m_vecPos.y, 5);
	}


	
}


void CBulletComponent::SetBulletInfo(float fX, float fY,float fAngle, float fVelocity,bool isEnemy,float fMaxDistance)
{
	m_vecPos.x = fX;
	m_vecPos.y = fY;
	m_vecPos.z = 1;

	m_fAngle = fAngle;
	m_fVelocity = fVelocity;
	m_isEnemy = isEnemy;
	m_fMaxDistance = fMaxDistance;
}

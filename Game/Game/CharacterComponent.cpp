#include "CharacterComponent.h"

#include "GameObject.h"
#include "MainGame.h"
#include "CharacterRenderComponent.h"
#include "BulletComponent.h"
#include <windows.h>
#include "2DSpriteComponent.h"
#include "CircleComponent.h"


CCharacterComponent::CCharacterComponent()
{
	m_fX = 300;
	m_fY = 300;
	m_Status = STOP_IDLE;
	m_CurrentWay = WAY_DOWN;
	m_fAngle = 0;
}

CCharacterComponent::~CCharacterComponent()
{
}


void CCharacterComponent::Update(float deltaTime)
{
	
	if (m_pRenderComponent)
	{
		UpdateStatus();

		

		
	}
	else
	{
		m_pRenderComponent = m_pOwner->getComponent<CCharacterRenderComponent>();
	}


	
}

void CCharacterComponent::Render()
{
	
}

void CCharacterComponent::CreateBullet()
{
	CGameObject* pGameObject = new CGameObject;
	pGameObject->AddComponent<CBulletComponent>();
	pGameObject->AddComponent<CCircleComponent>();
	pGameObject->AddComponent<C2DSpriteComponent>();

	pGameObject->getComponent<CBulletComponent>()->SetBulletInfo(m_fX, m_fY,m_fAngle,10,false,1000);

	//~~~~~ CBullet 추가정보~~//

	CMainGame::GetInstance()->CreateObject(pGameObject);
}

void CCharacterComponent::UpdateStatus()
{

	m_pRenderComponent->m_CurrentWay = m_CurrentWay;
	m_pRenderComponent->m_CurrentStatus = m_Status;

	m_pRenderComponent->m_vecPos.x = m_fX;
	m_pRenderComponent->m_vecPos.y = m_fY;
}

void CCharacterComponent::Move(eWay way, float fDistance)
{
	m_Status = WALK;
	switch (way)
	{
	case WAY_LEFT:
		m_fX -= fDistance;
		break;
	case WAY_RIGHT:
		m_fX += fDistance;
		break;
	case WAY_RIGHT_DOWN:
		m_fX += fDistance * pow(0.5, 0.5);
		m_fY += fDistance * pow(0.5, 0.5);
		break;
	case WAY_DOWN:
		m_fY += fDistance;
		break;
	case WAY_LEFT_DOWN:
		m_fX -= fDistance * pow(0.5, 0.5);
		m_fY += fDistance * pow(0.5, 0.5);
		break;
	case WAY_LEFT_UP:
		m_fX -= fDistance * pow(0.5, 0.5);
		m_fY -= fDistance * pow(0.5, 0.5);
		break;
	case WAY_UP:
		m_fY -= fDistance;
		break;
	case WAY_RIGHT_UP:
		m_fX += fDistance * pow(0.5, 0.5);
		m_fY -= fDistance * pow(0.5, 0.5);
		break;
	case WAY_END:
		break;
	default:
		m_Status = eStatus::STOP_IDLE;
		break;
	}
}

void CCharacterComponent::SetWay(eWay way)
{
	m_CurrentWay = way;
}
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
	m_Status = CROUCH;
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
	switch (m_Status)
	{
	case STOP_IDLE:
		m_pRenderComponent->m_strStatus = L"Stop Idle";
		break;
	case STOP_AIM:
		m_pRenderComponent->m_strStatus = L"Stop Aim";
		break;
	case STOP_FIRE:
		m_pRenderComponent->m_strStatus = L"Stop Fire";
		break;
	case CROUCH:
		m_pRenderComponent->m_strStatus = L"Crouch";
		break;
	case CROUCH_AIM:
		m_pRenderComponent->m_strStatus = L"Crouch Aim";
		break;
	case CROUCH_FIRE:
		m_pRenderComponent->m_strStatus = L"Crouch Fire";
		break;
	case WALK:
		m_pRenderComponent->m_strStatus = L"Walk";
		break;
	case WALK_AIM:
		m_pRenderComponent->m_strStatus = L"Walk Aim";
		break;
	case WALK_FIRE:
		m_pRenderComponent->m_strStatus = L"Walk Fire";
		break;
	case THROW_GRANADE:
		m_pRenderComponent->m_strStatus = L"Throw Granade";
		break;
	case HIT:
		m_pRenderComponent->m_strStatus = L"Hit 0";
		break;
	case HIT_BLOOD:
		m_pRenderComponent->m_strStatus = L"Hit Blood 0";
		break;
	case HIT_EXPLODE:
		m_pRenderComponent->m_strStatus = L"Hit Explo Blood";
		break;
	default:
		break;
	}

	m_pRenderComponent->m_CurrentWay = m_CurrentWay;
	m_pRenderComponent->m_vecPos.x = m_fX;
	m_pRenderComponent->m_vecPos.y = m_fY;
}

void CCharacterComponent::Move(eWay way, float fDistance)
{
	m_Status = WALK;
	m_CurrentWay = way;
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
	default:
		break;
	case WAY_RIGHT_UP:
		m_fX += fDistance * pow(0.5, 0.5);
		m_fY -= fDistance * pow(0.5, 0.5);
		break;
	case WAY_END:
		break;
	}
}

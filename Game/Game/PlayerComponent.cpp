#include "PlayerComponent.h"

#include "GameObject.h"
#include "MainGame.h"
#include "2DSpriteComponent.h"

CPlayerComponent::CPlayerComponent()
{
	
}


CPlayerComponent::~CPlayerComponent()
{
}

const std::wstring CPlayerComponent::GetComponentID()
{
	return L"Player";
}

const std::wstring CPlayerComponent::GetFamilyID()
{
	return L"Actor";
}

void CPlayerComponent::SetSprite()
{
	
}

void CPlayerComponent::Update(float deltaTime)
{


	C2DSpriteComponent* com = dynamic_cast<C2DSpriteComponent*>(m_pOwner->GetComponent(L"2DSprite"));
	com->SetTexture(L"Enemy_BattleShip");
	com->SetSprite(L"Body");
	com->SetPos(300, 400);
	com->SetFrame(0);
}

void CPlayerComponent::Render()
{
	
}


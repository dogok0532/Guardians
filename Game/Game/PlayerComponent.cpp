#include "PlayerComponent.h"
#include <windows.h>
#include "CharacterComponent.h"
#include "GameObject.h"
CPlayerComponent::CPlayerComponent()
{
}


CPlayerComponent::~CPlayerComponent()
{
}

void CPlayerComponent::Update(float deltaTime)
{
	if (m_pCharacterComponent)
	{
		if (GetAsyncKeyState(VK_SPACE))
		{
			m_pCharacterComponent->CreateBullet();
		}

		Move();
		

	}
	else
	{
		m_pCharacterComponent = m_pOwner->getComponent<CCharacterComponent>();
	}

}

void CPlayerComponent::Render()
{
	
}

void CPlayerComponent::Move()
{
	char cKeyBit=0x00;

	

	if (GetAsyncKeyState(VK_LEFT))
	{
		cKeyBit = cKeyBit | KEY_LEFT;
		
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		cKeyBit = cKeyBit | KEY_RIGHT;
		
	}
	if (GetAsyncKeyState(VK_UP))
	{
		cKeyBit = cKeyBit | KEY_UP;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		cKeyBit = cKeyBit | KEY_DOWN;
	}


	if (cKeyBit == (char)(KEY_UP | KEY_DOWN))
	{
		cKeyBit = cKeyBit ^ (KEY_UP | KEY_DOWN);
	}

	if (cKeyBit == (char)(KEY_LEFT | KEY_RIGHT))
	{
		cKeyBit=cKeyBit ^ (KEY_LEFT | KEY_RIGHT);
	}


	if (cKeyBit == (char)(KEY_LEFT | KEY_DOWN))
		m_pCharacterComponent->Move(WAY_LEFT_DOWN, 3);
	if (cKeyBit == (char)(KEY_RIGHT | KEY_UP))
		m_pCharacterComponent->Move(WAY_RIGHT_UP, 3);
	if (cKeyBit == (char)(KEY_LEFT | KEY_UP))
		m_pCharacterComponent->Move(WAY_LEFT_UP, 3);
	if (cKeyBit == (char)(KEY_RIGHT | KEY_DOWN))
		m_pCharacterComponent->Move(WAY_RIGHT_DOWN, 3);
	
	
	if(cKeyBit == KEY_LEFT)
		m_pCharacterComponent->Move(WAY_LEFT, 3);
	if (cKeyBit == KEY_RIGHT)
		m_pCharacterComponent->Move(WAY_RIGHT, 3);
	if (cKeyBit == KEY_UP)
		m_pCharacterComponent->Move(WAY_UP, 3);
	if (cKeyBit == KEY_DOWN)
		m_pCharacterComponent->Move(WAY_DOWN, 3);

	
}
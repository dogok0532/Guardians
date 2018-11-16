#include "PlayerComponent.h"
#include <windows.h>
#include "CharacterComponent.h"
#include "GameObject.h"
#include "DirectHeader.h"
#include <math.h>
#include <D3DX10math.h>
#include "Defines.h"
#include "MainGame.h"
#include "SoundResource.h"
 
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
		fCurrentTime += deltaTime;

		if (GetAsyncKeyState(VK_LBUTTON))
		{

			
			if(fCurrentTime >= fBulletCycle)
			{	
				m_pCharacterComponent->CreateBullet();
				CMainGame::GetInstance()->GetSound()->PlayEffect(L"9mm");
				fCurrentTime = 0;
			}
		}

		SetWay();
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
	if(cKeyBit == (char)KEY_LEFT)
		m_pCharacterComponent->Move(WAY_LEFT, 3);
	if (cKeyBit == (char)KEY_RIGHT)
		m_pCharacterComponent->Move(WAY_RIGHT, 3);
	if (cKeyBit == (char)KEY_UP)
		m_pCharacterComponent->Move(WAY_UP, 3);
	if (cKeyBit == (char)KEY_DOWN)
		m_pCharacterComponent->Move(WAY_DOWN, 3);

	
	if (!(cKeyBit & 0x000F))
		m_pCharacterComponent->SetStatus( STOP_IDLE);
}


void CPlayerComponent::SetWay()
{
	//1200 900
	POINT MousePos;
	GetCursorPos(&MousePos);
	ScreenToClient(g_hWnd, &MousePos);

	D3DXVECTOR3 vecMouse;
	vecMouse.x = MousePos.x;
	vecMouse.y = MousePos.y;
	vecMouse.z = 0;


	

	D3DXVECTOR3 vecCenter = m_pCharacterComponent->GetPos();

	D3DXVECTOR3 vecWay = vecMouse - vecCenter;


	float fDegree = D3DXToDegree(atan(vecWay.y / vecWay.x));
	
	if (vecWay.x <= 0)
	{
		fDegree += 180;
	}
	
	float fAdjust = fDegree - 22.5;
	if (fAdjust < 0)
	{
		fAdjust += 360;
	}

	int way = ((int)fAdjust / 45) +1;
	
	while (way < 0)
	{
		way += 8;
	}
	way %= 8;

	m_pCharacterComponent->SetWay((eWay)way);
	
}
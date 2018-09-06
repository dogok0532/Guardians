
#include "Player.h"
#include "SpriteResource.h"
#include "direct.h"
#include "Text.h"
#include "PlayerBullet.h"
#include "MainGame.h"

void CPlayer::Update(float deltaTime)
{
	
	Move(deltaTime);
	
	CGameObject::Update(deltaTime);


	


}

void CPlayer::Render()
{
	
	CGameObject::Render();
	
}

bool CPlayer::Destroy()
{
	return false;
}

int CPlayer::Fire(float deltaTime)
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		if (bFired == false)
		{
			bFired = true;
			return iBulletState;
		}
  		if (fCurrentCycle >= fFireCycle)
		{
			fCurrentCycle =0;
			bFired = true;
          	return iBulletState;
		}


		fCurrentCycle += deltaTime;

   		return false;
		
	}
	else
	{
		bFired = false;
	}



	fCurrentCycle = 0;
	return false;
}

void CPlayer::Move(float deltaTime)
{
	m_iFrame = 0;
	{		//이동관련 알고리즘
		if (GetAsyncKeyState(VK_LEFT))
		{
			m_GameInfo.vecPos.x -= 500 * deltaTime;
			m_iFrame = 1;
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			m_GameInfo.vecPos.x += 500 * deltaTime;
			m_iFrame = 2;
		}
		if (GetAsyncKeyState(VK_UP))
			m_GameInfo.vecPos.y -= 500 * deltaTime;
		if (GetAsyncKeyState(VK_DOWN))
			m_GameInfo.vecPos.y += 500 * deltaTime;
	}

	//범위 넘지 못하게 막기
	if (m_GameInfo.vecPos.x > WINCX/2 + GAMESIZE_X/2)
		m_GameInfo.vecPos.x = WINCX / 2 + GAMESIZE_X / 2;

	if (m_GameInfo.vecPos.y > GAMESIZE_Y)
		m_GameInfo.vecPos.y = GAMESIZE_Y;

	if (m_GameInfo.vecPos.x <  WINCX / 2 - GAMESIZE_X / 2)
		m_GameInfo.vecPos.x = WINCX / 2 - GAMESIZE_X / 2;

	if (m_GameInfo.vecPos.y < 0)
		m_GameInfo.vecPos.y = 0;
}


CGameObject* CPlayer::MakeBullet(float fAngle)	//팩토리 메서드를 통해 Player의 메서드로 PlayerBullet 생성
{
	CPlayerBullet* pBullet;
	pBullet = new CPlayerBullet;


	pBullet->SetAngle(fAngle);
	pBullet->SetPos(m_GameInfo.vecPos);

	return pBullet;
}

CPlayer::CPlayer()
{
	m_vecImage.push_back(CMainGame::GetInstance()->
		GetSpriteResource()->GetTextureInfo(L"User_Center"));
	m_vecImage.push_back(CMainGame::GetInstance()->
		GetSpriteResource()->GetTextureInfo(L"User_Left"));
	m_vecImage.push_back(CMainGame::GetInstance()->
		GetSpriteResource()->GetTextureInfo(L"User_Right"));

	if(m_vecImage.size()!=0)
		SetInfoToTexture();
	
	m_GameInfo.vecPos = { 400,400,0 };

	fFireCycle = 0.1f;
	fCurrentCycle = 0;

	iBulletState = 3;
	bFired = false;

	
	
}


CPlayer::~CPlayer()
{
	
}

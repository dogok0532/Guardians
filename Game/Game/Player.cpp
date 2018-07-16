
#include "Player.h"
#include "SpriteResource.h"
#include "direct.h"


void CPlayer::Update(float deltaTime)
{
	
	Move(deltaTime);
	

}

void CPlayer::Render()
{
	
	
	UpdatePos();
	m_vecImage[0]->Render();
	
}

bool CPlayer::Destroy()
{
	return false;
}

bool CPlayer::Fire(float deltaTime)
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		if (bFired == false)
		{
			bFired = true;
			return true;
		}
  		if (fCurrentCycle >= fFireCycle)
		{
			fCurrentCycle =0;
			bFired = true;
          	return true;
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
	{		//이동관련 알고리즘
		if (GetAsyncKeyState(VK_LEFT))
			m_vecPos.x -= 500 * deltaTime;
		if (GetAsyncKeyState(VK_RIGHT))
			m_vecPos.x += 500 * deltaTime;
		if (GetAsyncKeyState(VK_UP))
			m_vecPos.y -= 500 * deltaTime;
		if (GetAsyncKeyState(VK_DOWN))
			m_vecPos.y += 500 * deltaTime;
	}

	//범위 넘지 못하게 막기
	if (m_vecPos.x > WINCX/2 + GAMESIZE_X/2)
		m_vecPos.x = WINCX / 2 + GAMESIZE_X / 2;

	if (m_vecPos.y > GAMESIZE_Y)
		m_vecPos.y = GAMESIZE_Y;

	if (m_vecPos.x <  WINCX / 2 - GAMESIZE_X / 2)
		m_vecPos.x = WINCX / 2 - GAMESIZE_X / 2;

	if (m_vecPos.y < 0)
		m_vecPos.y = 0;
}

CPlayer::CPlayer()
{
	m_vecImage.push_back(CSpriteResource::GetInstance()->GetTextureInfo(L"User_Center"));
	m_vecImage.push_back(CSpriteResource::GetInstance()->GetTextureInfo(L"User_Left"));
	m_vecImage.push_back(CSpriteResource::GetInstance()->GetTextureInfo(L"User_Right"));

	if(m_vecImage.size()!=0)
		SetSizeToTextureSize();
	
	m_vecPos = { 400,400,0 };

	fFireCycle = 0.1f;
	fCurrentCycle = 0;
	bFired = false;

	UpdateTextureInfo();
}


CPlayer::~CPlayer()
{
	
}

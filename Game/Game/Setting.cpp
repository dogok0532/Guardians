#include "Setting.h"
#include "GameObject.h"
#include "MainGame.h"

CSetting::CSetting()
{

}



CSetting::~CSetting()
{
}

void CSetting::Update(float fDeltaTime)
{
	DeltaTime += fDeltaTime;
	
	if (DeltaTime >= 0.1)
	{
		DeltaTime = 0;
		Frame++;;
	}
	
}

void CSetting::Render()
{
	ObjectInfo m_GameInfo;
	m_GameInfo.fDirection = 0;
	m_GameInfo.vecPos = { 600,300,0 };
	m_GameInfo.vecRenderRatio = { 1,1,1 };
	m_GameInfo.vecSize = { 32,32,0 };

	CMainGame::GetInstance()->GetSpriteResource()->Render(L"Effect",L"Effect32",Frame, &m_GameInfo);
}

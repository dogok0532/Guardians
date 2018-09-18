#include "Setting.h"
#include "GameObject.h"
#include "MainGame.h"


CSetting::CSetting()
{
	strTexture = L"Effect";
	strSprite = L"Effect1";
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
	
	if (GetAsyncKeyState(VK_F5))
	{
		bEditTextModePressed = true;

		char strInput[32];
		string strName;

		printf("Texture:");
		scanf_s("%s", strInput,sizeof(strInput));
		strName = strInput;

		strTexture.assign(strName.begin(), strName.end());

		printf("strSprite:");
		scanf_s("%s", strInput, sizeof(strInput));
		strName = strInput;

		strSprite.assign(strName.begin(), strName.end());

		bEditTextModePressed = false;
	}

	if (GetAsyncKeyState(VK_F6) && !bEditTextModePressed)
	{
		bEditTextModePressed = true;

		CMainGame::GetInstance()->ResetSprite();
		
	}

	if (!GetAsyncKeyState(VK_F6) && bEditTextModePressed)
	{
		bEditTextModePressed = false;
	}

}

void CSetting::Render()
{
	ObjectInfo m_GameInfo;
	m_GameInfo.fDirection = 0;
	m_GameInfo.vecPos = { 600,300,0 };
	m_GameInfo.vecRenderRatio = { 1,1,1 };
	m_GameInfo.vecSize = { 32,32,0 };

	CMainGame::GetInstance()->GetSpriteResource()->Render(strTexture, strSprite, Frame, &m_GameInfo);


	
}

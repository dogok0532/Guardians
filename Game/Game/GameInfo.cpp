#include "GameInfo.h"
#include "Text.h"
#include "direct.h"
#include "MainGame.h"

void CGameInfo::Update(float deltaTime)
{
	CGameObject::Update(deltaTime);
}

void CGameInfo::Render()
{

	

	
	

	if (GetAsyncKeyState(VK_SPACE))
	{
		pText->SetText(L"Fire");
		pText->Render();
	}
	if (GetAsyncKeyState(VK_UP))
	{

		pText->SetText(L"¡è");
		pText->Render();
	}
	if (GetAsyncKeyState(VK_DOWN))
	{

		pText->SetText(L"¡é");
		pText->Render();
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{

		pText->SetText(L"¡æ");
		pText->Render();
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		pText->SetText(L"¡ç");
		pText->Render();
	}
	
}

bool CGameInfo::Destroy()
{
	return false;
}



CGameInfo::CGameInfo()
{
	pText = new CText();

	pText->Init();
	pText->SetText(L"Ã¼·Â:");
	pText->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	pText->SetTextRange(0, 0, WINCX / 2 - GAMESIZE_X / 2, WINCY);
	pText->Render();
	pText->SetTextRange(0, 0, 50, 50);
}


CGameInfo::~CGameInfo()
{
	if (pText)
	{
		pText->Release();
	}
}

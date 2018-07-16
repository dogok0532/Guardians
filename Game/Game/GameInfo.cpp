#include "GameInfo.h"
#include "TextManager.h"
#include "direct.h"

void CGameInfo::Update(float deltaTime)
{

}

void CGameInfo::Render()
{

	RECT rc ={0,0, WINCX / 2 - GAMESIZE_X / 2 ,WINCY +200};
	CDirect::GetInstance()->DrawRectangle(rc);

	rc = { WINCX / 2 + GAMESIZE_X / 2,0,WINCX,WINCY + 200 };
	CDirect::GetInstance()->DrawRectangle(rc);

	

	CTextManager::GetInstance()->SetText(L"ü��:");
	CTextManager::GetInstance()->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	CTextManager::GetInstance()->SetTextRange(0, 0, WINCX / 2 - GAMESIZE_X / 2, WINCY);
	CTextManager::GetInstance()->Render();
}

bool CGameInfo::Destroy()
{
	return false;
}

CGameInfo::CGameInfo()
{
}


CGameInfo::~CGameInfo()
{
}

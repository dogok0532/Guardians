#include "stdafx.h"
#include "Player.h"
#include "SpriteResource.h"
#include "direct.h"

void CPlayer::Update(float deltaTime)
{
	if (GetAsyncKeyState(VK_LEFT))
		vecPos.x -= 500*deltaTime;

	if (GetAsyncKeyState(VK_RIGHT))
		vecPos.x += 500* deltaTime;

	if (GetAsyncKeyState(VK_UP))
		vecPos.y -= 500* deltaTime;

	if (GetAsyncKeyState(VK_DOWN))
		vecPos.y += 500* deltaTime;
	

}

void CPlayer::Render()
{

		
		
		pSprite->Draw(vecImage[0], NULL, NULL, &vecPos, D3DCOLOR_ARGB(255, 255, 255, 255));
		
	
}

CPlayer::CPlayer()
{
	vecImage.push_back(CSpriteResource::GetInstance()->GetImage(L"User_Center"));
	vecImage.push_back(CSpriteResource::GetInstance()->GetImage(L"User_Left"));
	vecImage.push_back(CSpriteResource::GetInstance()->GetImage(L"User_Right"));

	pSprite = CDirect::GetInstance()->GetSprite();

	vecPos = { 400,400,0 };
}


CPlayer::~CPlayer()
{
}

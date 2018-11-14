#include "MainGame.h"
#include "Scene.h"
#include "MainMenu.h"
#include "Defines.h"
#include "Stage.h"
#include <windows.h>

#include "Text.h"
#include "SoundResource.h"
#include "SpriteResource.h"
#include <stdio.h>


IMPLEMENT_SINGLETON(CMainGame)






void CMainGame::ChangeScene(int Scene)
{
	switch (Scene)
	{

	case 100:

		if (MessageBox(g_hWnd, L"게임을 종료하시겠습니까?", L"", MB_OKCANCEL) == IDOK)
			ExitProcess(0);
	else
	{
		SAFE_DELETE(m_pCurrentScene);
		m_pCurrentScene = new CMainMenu;
	}
		 break;
	default:
		break;
	}
}

void CMainGame::Init()
{
	pSoundResource = new CSoundResource;
	pSoundResource->Init();
	pSpriteResource = new CSpriteResource;
	m_pCurrentScene = new CStage;

	
}

void CMainGame::Update(float deltaTime)
{
	m_pCurrentScene->Update(deltaTime);





	
}

void CMainGame::Render()
{
	m_pCurrentScene->Render();
}

void CMainGame::ResetSprite()
{
	SAFE_DELETE(pSpriteResource);
	pSpriteResource = new CSpriteResource;
}

void CMainGame::CreateObject(CGameObject* pGameObject)
{
	m_pCurrentScene->CreateObject(pGameObject);
}

CMainGame::CMainGame()
{
	/*
	AllocConsole();                 

	FILE* pFile;

	freopen_s(&pFile,"CONOUT$", "a", stderr); 
	freopen_s(&pFile, "CONOUT$", "a", stdout);
	freopen_s(&pFile, "CONIN$", "r", stdin);
	SetConsoleTitleA("Test v.1.0");


	*/

}


CMainGame::~CMainGame()
{
	
	
	delete pSoundResource;
	delete pSpriteResource;
	delete m_pCurrentScene;
}

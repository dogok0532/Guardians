#include "MainGame.h"
#include "Scene.h"
#include "MainMenu.h"

void CMainGame::Update(float deltaTime)
{
	m_pCurrentScene->Update(deltaTime);
}

void CMainGame::Render()
{
	m_pCurrentScene->Render();
}

CMainGame::CMainGame()
{
	m_pCurrentScene = new CMainMenu;
}


CMainGame::~CMainGame()
{
}

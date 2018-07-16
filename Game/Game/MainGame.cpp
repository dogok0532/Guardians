#include "MainGame.h"
#include "Scene.h"
#include "MainMenu.h"
#include "Defines.h"
#include "Stage.h"

void CMainGame::ChangeScene(int Scene)
{
	switch (Scene)
	{
	case 0:
		SAFE_DELETE(m_pCurrentScene);			
		m_pCurrentScene = new CStage;
		break;
	
	
	/*		//Change after adding CSetting, CScore, ...etc
	case 3:
		SAFE_DELETE(m_pCurrentScene);
		m_pCurrentScene = new CSetting;
		break;
	case 4:
		SAFE_DELETE(m_pCurrentScene);
		m_pCurrentScene = new CMainMenu;
		break;
	case 5:
		SAFE_DELETE(m_pCurrentScene);
		m_pCurrentScene = new CMainMenu;
		break;

	*/
	default:
		break;
	}
}

void CMainGame::Update(float deltaTime)
{
	m_pCurrentScene->Update(deltaTime);

	ChangeScene(m_pCurrentScene->StageChangeMessage());
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

#include "MainMenu.h"
#include "GameButton.h"
#include "Defines.h"
#include "Mouse.h"
#include "Scene.h"

void CMainMenu::Update(float deltaTime)
{

	m_pMouse->Update(deltaTime);
	for (int i = 0; i < m_pVecUI.size(); i++)
	{
		dynamic_cast<CGameButton*>(m_pVecUI[i])->SetUIState(m_pMouse);
		m_pVecUI[i]->Update(deltaTime);

		if (dynamic_cast<CGameButton*>(m_pVecUI[i])->ButtonClicked())
		{
			m_iStageChange = i;	
			
		}
	}
	
	
	

}

void CMainMenu::Render()
{
	for (int i = 0; i < m_pVecUI.size(); i++)
	{
		m_pVecUI[i]->Render();
	}

	
	m_pMouse->Render();
}

CMainMenu::CMainMenu()
{
	CGameObject* pUI;

	pUI = new CGameButton;
	pUI->SetPos(WINCX / 2, WINCY / 6 * 1, 0);
	(dynamic_cast<CGameButton*>(pUI))->SetButtonName(L"Start");

	m_pVecUI.push_back(pUI);

	pUI = new CGameButton;
	pUI->SetPos(WINCX / 2, WINCY / 6 * 2, 0);
	(dynamic_cast<CGameButton*>(pUI))->SetButtonName(L"Option");
	m_pVecUI.push_back(pUI);

	pUI = new CGameButton;
	pUI->SetPos(WINCX / 2, WINCY / 6 * 3, 0);
	(dynamic_cast<CGameButton*>(pUI))->SetButtonName(L"End");
	m_pVecUI.push_back(pUI);


	m_pMouse = new CMouse;

}


CMainMenu::~CMainMenu()
{
	for (int i = 0; i < m_pVecUI.size(); i++)
		delete m_pVecUI[i];
		
		
	delete m_pMouse;

}

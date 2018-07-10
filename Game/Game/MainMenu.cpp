#include "MainMenu.h"
#include "GameButton.h"
#include "Defines.h"

void CMainMenu::Update(float deltaTime)
{
	for (int i = 0; i < m_pVecUI.size(); i++)
	{
		m_pVecUI[i]->Update(deltaTime);
	}

}

void CMainMenu::Render()
{
	for (int i = 0; i < m_pVecUI.size(); i++)
	{
		m_pVecUI[i]->Render();
	}
}

CMainMenu::CMainMenu()
{
	CGameObject* pUI;

	pUI = new CGameButton;
	pUI->SetPos(WINCX / 2, WINCY / 6 * 1, 0);
	((CGameButton*)pUI)->SetButtonName(L"Start");
	m_pVecUI.push_back(pUI);

	pUI = new CGameButton;
	pUI->SetPos(WINCX / 2, WINCY / 6 * 3, 0);
	((CGameButton*)pUI)->SetButtonName(L"Start");
	m_pVecUI.push_back(pUI);

	pUI = new CGameButton;
	pUI->SetPos(WINCX / 2, WINCY / 6 * 5, 0);
	((CGameButton*)pUI)->SetButtonName(L"Start");
	m_pVecUI.push_back(pUI);



	m_pVecUI.push_back(pUI);
}


CMainMenu::~CMainMenu()
{
	

}

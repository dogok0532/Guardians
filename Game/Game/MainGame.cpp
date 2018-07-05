#include "stdafx.h"
#include "MainGame.h"

#include "Player.h"


void CMainGame::Update(float deltaTime)
{
	m_pPlayer[0]->Update(deltaTime);
}

void CMainGame::Render()
{
	m_pPlayer[0]->Render();
	
}



CMainGame::CMainGame()
{
	m_pPlayer[0] = new CPlayer;

	
	

}


CMainGame::~CMainGame()
{
	SAFE_DELETE(m_pPlayer[0]);
	SAFE_DELETE(m_pPlayer[1]);


	for (list<CGameObject*>::iterator iter = m_pMonsterList.begin();
		iter != m_pMonsterList.end(); iter++)
	{
		SAFE_DELETE(*iter);
	}

	for (list<CGameObject*>::iterator iter = m_pBulletList.begin();
		iter != m_pBulletList.end(); iter++)
	{
		SAFE_DELETE(*iter);
	}
}

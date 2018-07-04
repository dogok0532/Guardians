#pragma once
#include <list>
class CGameObject;
class CMainGame
{
private:
	CGameObject * m_pPlayer[2];
	list<CGameObject*> m_pMonsterList;
	list<CGameObject*> m_pBulletList;


public:
	void Update();
	void Render();


public:
	CMainGame();
	virtual ~CMainGame();
};


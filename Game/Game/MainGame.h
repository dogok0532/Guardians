#pragma once
#include <list>
#include "Scene.h"
class CGameObject;
class CMainGame :public CScene
{
private:
	CGameObject * m_pPlayer[2] = { NULL, NULL};
	list<CGameObject*> m_pMonsterList;
	list<CGameObject*> m_pBulletList;


public:
	virtual void Update(float deltaTime);
	virtual void Render();


public:
	CMainGame();
	virtual ~CMainGame();
};


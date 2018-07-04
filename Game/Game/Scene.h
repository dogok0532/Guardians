#pragma once
#include "stdafx.h"

class CGameObject;
class CScene
{
private:
	CGameObject* m_pPlayer[2];
	list<CGameObject*> m_pMonsterList;
	list<CGameObject*> m_pUIList;
	list<CGameObject*> m_pBulletList;
public:
	virtual void Update()=0;
	virtual void Render()=0;

public:
	CScene();
	virtual ~CScene();
};


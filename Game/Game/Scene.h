#pragma once
#include "stdafx.h"

class CGameObject;
class CScene
{
private:
	list<CGameObject*> m_pUIList;

public:
	virtual void Update()=0;
	virtual void Render()=0;

public:
	CScene();
	virtual ~CScene();
};


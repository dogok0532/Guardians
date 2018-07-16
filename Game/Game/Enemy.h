#pragma once
#include "GameObject.h"
class CEnemy :
	public CGameObject
{
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual bool Destroy();

public:
	CEnemy();
	virtual ~CEnemy();
};


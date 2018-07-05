#pragma once
#include "GameObject.h"
class CPlayer :
	public CGameObject
{
private:
	
public:
	virtual void Update(float deltaTime);
	virtual void Render();

public:
	CPlayer();
	virtual ~CPlayer();
};


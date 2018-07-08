#pragma once
#include "UI.h"
class CGameInfo :
	public CUI
{
public:
	virtual void Update(float deltaTime);
	virtual void Render();



public:
	CGameInfo();
	virtual ~CGameInfo();
};


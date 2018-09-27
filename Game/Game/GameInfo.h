#pragma once
#include "UI.h"

class CText;
class CGameInfo :
	public CUI
{
private:
	CText * pText;

public:
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual bool Destroy();



public:
	CGameInfo();
	virtual ~CGameInfo();
};


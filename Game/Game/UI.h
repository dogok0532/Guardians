#pragma once
#include "GameObject.h"
class CUI :
	public CGameObject
{
	virtual void Update(float deltaTime)=0;
	virtual void Render() = 0;

public:
	CUI();
	virtual ~CUI();
};


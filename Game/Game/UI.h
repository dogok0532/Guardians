#pragma once
#include "GameObject.h"
class CUI :
	public CGameObject
{
public:
	virtual void Update(float deltaTime)=0;
	virtual void Render() = 0;
	virtual bool Destroy() = 0;

public:
	CUI();
	virtual ~CUI();
};


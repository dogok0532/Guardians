#pragma once
#include "GameObject.h"
class CPlayer :
	public CGameObject
{
private:
	float fFireCycle;
	float fCurrentCycle;

	bool bFired;
	
public:
	virtual void Update(float deltaTime);
	virtual void Render();


	bool Fire(float deltaTim);
	void Move(float deltaTime);


public:
	CPlayer();
	virtual ~CPlayer();
};


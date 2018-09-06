#pragma once
#include "GameObject.h"
class CPlayer :
	public CGameObject
{
private:
	float fFireCycle;
	float fCurrentCycle;

	bool bFired;

	int iBulletState;
	
public:
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual bool Destroy();


	int Fire(float deltaTim);
	void Move(float deltaTime);

	CGameObject* MakeBullet(float fAngle);

	
public:
	CPlayer();
	virtual ~CPlayer();
};


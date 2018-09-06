#pragma once
#include "GameObject.h"
class CPlayerBullet :
	public CGameObject
{
	float m_fSpeed;

	virtual void Update(float deltaTime);
	virtual void Render();
	virtual bool Destroy();

	

public:

	





public:
	CPlayerBullet();
	virtual ~CPlayerBullet();
};


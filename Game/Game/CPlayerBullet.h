#pragma once
#include "GameObject.h"
class CPlayerBullet :
	public CGameObject
{
	D3DXVECTOR3 vecSpeed;

	virtual void Update(float deltaTime);
	virtual void Render();



public:


	bool Destroy();	//메모리에서 제거해야할떄 true 값 반환

public:
	CPlayerBullet();
	virtual ~CPlayerBullet();
};


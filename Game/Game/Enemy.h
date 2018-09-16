#pragma once
#include "GameObject.h"
class CEnemy :public CGameObject
{
public:
	CEnemy();
	~CEnemy();

	virtual void Update(float deltaTime);


	virtual void Render();


	virtual bool Destroy() =0;

	//virtual void Attack()=0;

};


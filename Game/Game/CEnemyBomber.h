#pragma once
#include "Enemy.h"
class CEnemyBomber : CEnemy
{
public:
	CEnemyBomber();
	virtual ~CEnemyBomber();

public:
	virtual void Update(float deltaTime);
	virtual void Render();
};


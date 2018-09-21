#pragma once
#include "Enemy.h"
class CEnemyFighter :
	public CEnemy
{
	virtual void Update(float deltaTime) override ;
	virtual void Render() override;

public:
	CEnemyFighter();
	virtual ~CEnemyFighter();


};


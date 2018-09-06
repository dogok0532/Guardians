#pragma once
#include "Enemy.h"
class CEnemyPlane :
	public CEnemy
{
	virtual void Update(float deltaTime) override ;
	virtual void Render() override;
	virtual bool Destroy() override;

public:
	CEnemyPlane();
	virtual ~CEnemyPlane();


};


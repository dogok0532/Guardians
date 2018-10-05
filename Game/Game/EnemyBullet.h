#pragma once
#include "GameObject.h"
class CEnemyBullet :
	public CGameObject
{
public:
	CEnemyBullet();
	virtual ~CEnemyBullet();

	virtual void Update(float deltaTime) override;


	virtual void Render() override;




};


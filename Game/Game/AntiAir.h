#pragma once
#include "Enemy.h"
class CAntiAir :
	public CEnemy
{
public:
	CAntiAir();
	virtual ~CAntiAir();

	virtual void Update(float deltaTime) override;


	virtual void Render() override;


	

};


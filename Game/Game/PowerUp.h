#pragma once
#include "Item.h"
class CPowerUp :
	public CItem
{
public:
	CPowerUp();
	virtual ~CPowerUp();

	virtual void Update(float deltaTime);


	virtual void Render();

};


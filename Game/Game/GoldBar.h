#pragma once
#include "Item.h"
class CGoldBar :
	public CItem
{
public:
	CGoldBar();
	virtual ~CGoldBar();

	virtual void Update(float deltaTime) override;


	virtual void Render() override;

};


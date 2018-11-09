#pragma once
#include "IComponent.h"
class CPlayerComponent :
	public IComponent
{



public:
	CPlayerComponent();
	virtual ~CPlayerComponent();

	



	virtual void Update(float deltaTime) override;
	virtual void Render() override;



};


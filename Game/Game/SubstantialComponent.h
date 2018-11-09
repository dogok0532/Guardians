#pragma once

#include "IComponent.h"
class CSubstantialComponent : public IComponent
{
public:
	CSubstantialComponent();
	~CSubstantialComponent();

	virtual void Update(float deltaTime)=0;


	virtual const wstring GetComponentID()=0;


	

};


#pragma once
#include "IComponent.h"
class CPlayerComponent :
	public IComponent
{
public:
	CPlayerComponent();
	virtual ~CPlayerComponent();

	virtual const wstring GetComponentID();
	virtual const wstring GetFamilyID();

	void SetSprite();

	virtual void Update(float deltaTime) override;


	virtual void Render() override;

};


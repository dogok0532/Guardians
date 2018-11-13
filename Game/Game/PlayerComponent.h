#pragma once
#include "IComponent.h"
class CCharacterComponent;
class CPlayerComponent :
	public IComponent
{
private:
	CCharacterComponent* m_pCharacterComponent= nullptr;

public:
	CPlayerComponent();
	virtual ~CPlayerComponent();

	virtual void Update(float deltaTime) override;
	virtual void Render() override;

	void Move();
};


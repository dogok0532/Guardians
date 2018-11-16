#pragma once
#include "IComponent.h"
class CCharacterComponent;
class CPlayerComponent :
	public IComponent
{
private:
	CCharacterComponent* m_pCharacterComponent= nullptr;


	float fBulletCycle=0.1;
	float fCurrentTime = 0;

public:
	CPlayerComponent();
	virtual ~CPlayerComponent();

	virtual void Update(float deltaTime) override;
	virtual void Render() override;

	void Move();
	void SetWay();
};


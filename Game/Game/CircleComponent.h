#pragma once
#include "IComponent.h"
class CCircleComponent :
	public IComponent
{
private:
	float m_fX;
	float m_fY;
	float m_fRadius;

public:
	void SetCircle(float fX, float fY, float fRadius);

public:
	CCircleComponent();
	virtual ~CCircleComponent();
	void SetPos(float x, float y);
};


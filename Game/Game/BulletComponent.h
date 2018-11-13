#pragma once
#include "IComponent.h"
#include "DirectHeader.h"
class CCircleComponent;
class C2DSpriteComponent;
class CBulletComponent :
	public IComponent
{
private:
	CCircleComponent*  m_pCircleComponent = nullptr;
	C2DSpriteComponent*  m_pSpriteComonent=nullptr;
	
private:
	D3DXVECTOR3 m_vecPos;
	float m_fAngle;
	float m_fVelocity;
	bool m_isEnemy;

	float m_fMaxDistance=300;
	float m_fCurrentDistance=0;

public:
	virtual void Update(float deltaTime) override;
	void SetBulletInfo(float fX, float fY, float fAngle, float fVelocity, bool isEnemy,float fMaxDistance);

	CBulletComponent();
	virtual ~CBulletComponent();

	


	virtual void Render() override;

};


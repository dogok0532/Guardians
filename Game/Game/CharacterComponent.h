#pragma once
#include "IComponent.h"
#include "CharacterEnum.h"
#include "DirectHeader.h"


class CRectangleComponent;
class CCharacterRenderComponent;

class CCharacterComponent :public IComponent
{
private:
	CCharacterRenderComponent* m_pRenderComponent=nullptr;
	IComponent* m_pTextComponent=nullptr;
	CRectangleComponent* m_pRectangleComponent=nullptr;

private:
	float m_fPrevX;
	float m_fPrevY;

private:
	float m_fX;
	float m_fY;
	eStatus m_Status;
	eWay m_CurrentWay;
	float m_fAngle;

	bool b_isRendering;

public:
	CCharacterComponent();
	virtual ~CCharacterComponent();

	


	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	void UpdateStatus();


	void Move(eWay way, float fDistance);
	void SetWay(eWay way);
	void SetStatus(eStatus status) { m_Status = status; }
	void CreateBullet();

	
	D3DXVECTOR3 GetPos() { return D3DXVECTOR3(m_fX,m_fY,1); }

	
};

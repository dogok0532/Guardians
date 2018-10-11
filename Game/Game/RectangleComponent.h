#pragma once
#include "SubstantialComponent.h"
#include <windows.h>
class CRectangleComponent :
	public CSubstantialComponent
{
private:
	float m_fX;
	float m_fY;
	float m_fWidth;
	float m_fHeight;

	RECT m_rc;

	void UpdateFromRECT();// RECT로부터 XYWH로 업데이트
	void UpdateToRECT();	//XYWH로부터 RECT로 업데이트

public:
	CRectangleComponent();
	CRectangleComponent(float x, float y, float width, float height);
	CRectangleComponent(RECT rc);

	virtual ~CRectangleComponent();


	void Set(RECT rc);
	void Set(float x, float y, float width, float height);
	void SetPos(float x, float y);
	void SetWidth(float width);
	void SetHeight(float height);

	virtual void Update(float deltaTime) override;
	virtual const wstring GetComponentID() override;

	bool CheckCollision(RECT rc);
	bool CheckCollisionCircle(float fRadius,float fX,float fY);
	
};


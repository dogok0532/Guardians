#pragma once
#include "IComponent.h"
#include "DirectHeader.h"
#include "RectangleComponent.h"

class C2DSpriteComponent;
class CTileComponent :
	public IComponent
{
private:
	const int m_iMaxX;
	const int m_iMaxY;

private:
	const int m_iIndexX;
	const int m_iIndexY;

	float m_fX;
	float m_fY;

public:
	D3DXVECTOR3 GetPos() { return D3DXVECTOR3(m_fX, m_fY,0); }


private:
	bool m_bBlocked;




private:
	C2DSpriteComponent* m_pSpriteComponent = nullptr;

public:
	CTileComponent(int indexX, int indexY,int maxX, int maxY);
	virtual ~CTileComponent();

	virtual void Update(float deltaTime) override;


	virtual void Render() override;

};

bool isCollide(CTileComponent* tileComponent, CRectangleComponent* rectComponent)
{
	
	RECT rc= rectComponent->GetRect();

	float xCoord = rc.left;
	float yCoord = rc.top;

	float newCoordX = xCoord / (float)64 - yCoord / (float)32;
	float newCoordY = xCoord / (float)64 + yCoord / (float)32;

	
	if (newCoordX < 0 || newCoordY < 0 || newCoordX >1 || newCoordY >1)
		return true;

	xCoord = rc.left;
	yCoord = rc.bottom;

	if (newCoordX < 0 || newCoordY < 0 || newCoordX >1 || newCoordY >1)
		return true;

	xCoord = rc.right;
	yCoord = rc.bottom;

	if (newCoordX < 0 || newCoordY < 0 || newCoordX >1 || newCoordY >1)
		return true;

	xCoord = rc.left;
	yCoord = rc.bottom;

	if (newCoordX < 0 || newCoordY < 0 || newCoordX >1 || newCoordY >1)
		return true;



	return false;
}
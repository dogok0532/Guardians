#include "RectangleComponent.h"



CRectangleComponent::CRectangleComponent()
{
}


CRectangleComponent::CRectangleComponent(float x, float y, float width, float height)
{
	Set(x, y, width, height);
}

CRectangleComponent::CRectangleComponent(RECT rc)
{
	Set(rc);
}

CRectangleComponent::~CRectangleComponent()
{
}

void CRectangleComponent::Set(RECT rc)
{
	m_rc = rc;
	UpdateFromRECT;
}

void CRectangleComponent::Set(float x, float y, float width, float height)
{
	m_fX = x;
	m_fY = y;
	m_fWidth = width;
	m_fHeight = height;
	UpdateToRECT();

}

void CRectangleComponent::SetPos(float x, float y)
{
	m_fX = x;
	m_fY = y;
	
	UpdateToRECT();
}

void CRectangleComponent::SetWidth(float width)
{

	m_fWidth = width;

	UpdateToRECT();
}

void CRectangleComponent::SetHeight(float height)
{

	m_fHeight = height;
	UpdateToRECT();
}

void CRectangleComponent::Update(float deltaTime)
{
	
}

const std::wstring CRectangleComponent::GetComponentID()
{
	return L"Rectangle";
}

bool CRectangleComponent::CheckCollision(RECT rc)
{

}

bool CRectangleComponent::CheckCollisionCircle(float fRadius, float fX, float fY)
{

}

void CRectangleComponent::UpdateFromRECT()
{
	m_fX = m_rc.right - m_rc.left;
	m_fY = m_rc.bottom - m_rc.top;
}

void CRectangleComponent::UpdateToRECT()
{
	m_rc.left = m_fX - m_fWidth / 2;
	m_rc.top = m_fY - m_fHeight / 2;
	m_rc.right = m_fX + m_fWidth / 2;
	m_rc.bottom = m_fY + m_fHeight / 2;
}

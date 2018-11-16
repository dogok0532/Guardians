#include "TileComponent.h"
#include "2DSpriteComponent.h"

#include "GameObject.h"
#include "direct.h"

CTileComponent::CTileComponent(int indexX, int indexY, int maxX, int maxY) :
	m_iIndexX(indexX),
	m_iIndexY(indexY),
	m_iMaxX(maxX),
	m_iMaxY(maxY)
{

}

CTileComponent::~CTileComponent()
{
}

void CTileComponent::Update(float deltaTime)
{
	if (m_pSpriteComponent)
	{
		

	}
	else
	{
		m_pSpriteComponent = GetOwner()->getComponent<C2DSpriteComponent>();
		

		m_fX = (m_iIndexX + m_iIndexY) * 32;
		m_fY = (m_iMaxY  - m_iIndexX + m_iIndexY) * 16;


		m_pSpriteComponent->SetPos(m_fX, m_fY,0);
		m_pSpriteComponent->SetTexture(L"Tile");
	}
}

void CTileComponent::Render()
{
	if (m_pSpriteComponent)
	{
		m_pSpriteComponent->SetDrawTexture();
	}
}



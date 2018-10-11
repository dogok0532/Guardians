#include "2DSpriteComponent.h"

#include "MainGame.h"
#include "SpriteResource.h"

void C2DSpriteComponent::SetSizeAsFrame()
{
	m_RenderInfo.vecSize = CMainGame::GetInstance()->
		GetSpriteResource()->
		GetSpriteSize(m_strTextureName, m_strSpriteName);
}

void C2DSpriteComponent::SetTexture(wstring texture)
{
	m_strTextureName = texture;
}

void C2DSpriteComponent::SetSprite(wstring sprite)
{
	m_strSpriteName = sprite;
}

void C2DSpriteComponent::SetFrame(int frame)
{
	m_iFrame = frame;
}

void C2DSpriteComponent::SetAngle(float fAngle)
{
	m_RenderInfo.fRenderDirection = fAngle;

}

void C2DSpriteComponent::SetPos(D3DXVECTOR3 vecPos)
{

}

void C2DSpriteComponent::SetPos(float x, float y, float z /*= 0*/)
{

}

void C2DSpriteComponent::SetRatio(float XRatio, float YRatio)
{

}

void C2DSpriteComponent::SetSize(float width, float height)
{

}

void C2DSpriteComponent::DrawFrame()
{
	CMainGame::GetInstance()->GetSpriteResource()->Render(m_strTextureName, m_strSpriteName, m_iFrame, &m_RenderInfo);

}

void C2DSpriteComponent::DrawSprite()
{
	CMainGame::GetInstance()->GetSpriteResource()->RenderWholeSprite(m_strTextureName, m_strSpriteName, &m_RenderInfo);

}

void C2DSpriteComponent::DrawTexture()
{
	CMainGame::GetInstance()->GetSpriteResource()->RenderWholeTexture(m_strTextureName, &m_RenderInfo);
}

const std::wstring C2DSpriteComponent::GetComponentID()
{
	throw std::logic_error("The method or operation is not implemented.");
}

const std::wstring C2DSpriteComponent::GetFamilyID()
{
	throw std::logic_error("The method or operation is not implemented.");
}

C2DSpriteComponent::C2DSpriteComponent()
{
	SetSizeAsFrame();
}


C2DSpriteComponent::~C2DSpriteComponent()
{
}

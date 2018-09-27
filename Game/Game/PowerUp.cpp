#include "PowerUp.h"



CPowerUp::CPowerUp()
{
	m_strTextureName = L"Item";
	m_strSpriteName = L"PowerUp";
}


CPowerUp::~CPowerUp()
{
}

void CPowerUp::Update(float deltaTime)
{
	
}

void CPowerUp::Render()
{
	Draw();
}

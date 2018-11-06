#include "IComponent.h"



void IComponent::Update(float deltaTime)
{

}

void IComponent::Render()
{

}

void IComponent::SetOwner(CGameObject* pGameObject)
{
	m_pOwner = pGameObject;
}

const CGameObject* IComponent::GetOwner()
{
	return m_pOwner;
}



IComponent::IComponent()
{
	m_pOwner = NULL;
}


IComponent::~IComponent()
{
}

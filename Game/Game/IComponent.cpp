#include "IComponent.h"



void IComponent::Update(float deltaTime)
{

}

void IComponent::Render()
{

}

void IComponent::SetOwner(const CGameObject* pGameObject)
{
	m_pOwner = pGameObject;
}

const CGameObject* IComponent::GetOwner()
{
	return m_pOwner;
}





IComponent::IComponent()
{

}

IComponent::~IComponent()
{
}

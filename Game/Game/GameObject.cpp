
#include "GameObject.h"
#include "direct.h"
#include "MainGame.h"

#include "IComponent.h"


CGameObject* CGameObject::CreateObject()
{
	return new CGameObject;
}

void CGameObject::Update(float deltaTime)
{
	for ( auto iter = componentArray.begin(); iter != componentArray.end() ;iter++)
	{
		if(*iter)
			(*iter)->Update(deltaTime);
	}
}

void CGameObject::Render()
{
	for (auto iter = componentArray.begin(); iter != componentArray.end(); iter++)
	{
		if (*iter)
			(*iter)->Render();
	}

	
}



bool CGameObject::isDead()
{
	return m_isDead;
}

void CGameObject::SetDead()
{
	m_isDead = true;
}

CGameObject::CGameObject()
{
	componentArray.fill(NULL);
}

CGameObject::~CGameObject()
{
	


}

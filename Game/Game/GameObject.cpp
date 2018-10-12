
#include "GameObject.h"
#include "direct.h"
#include "MainGame.h"

#include "IComponent.h"


void CGameObject::Update(float deltaTime)
{
	unordered_map<wstring, IComponent*>::iterator iter = m_mapComponent.begin();

	for (; iter != m_mapComponent.end(); iter++)
	{
		iter->second->Update(deltaTime);
	}
	
}



void CGameObject::Add_Component(IComponent* pComponent)
{
	pComponent->SetOwner(this);
	m_mapComponent.insert(make_pair(pComponent->GetComponentID(), pComponent));
}

void CGameObject::Remove_Component(wstring componentName)
{
	SAFE_DELETE(m_mapComponent[componentName]);
	m_mapComponent.erase(componentName);

}

CGameObject::CGameObject()
{
	
}


CGameObject::~CGameObject()
{
	


}

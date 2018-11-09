
#include "GameObject.h"
#include "direct.h"
#include "MainGame.h"

#include "IComponent.h"


void CGameObject::Update(float deltaTime)
{
	
	
}



void CGameObject::Render()
{

	
}


void CGameObject::AddGroup(GROUP group)
{

	groupBitSet[group] = true;
}

void CGameObject::RemoveGroup(GROUP group)
{
	groupBitSet[group] = false;
	
}









CGameObject::CGameObject()
{
	componentArray.fill(NULL);
}

CGameObject::~CGameObject()
{
	


}

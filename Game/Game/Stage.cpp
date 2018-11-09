#include "Stage.h"
#include <algorithm>
#include "GameObject.h"
#include "PlayerComponent.h"
#include "2DSpriteComponent.h"
#include "RectangleComponent.h"
//#include "TextComponent.h"




CStage::CStage()
{
	CGameObject* pPlayer = new CGameObject();

	pPlayer->AddComponent<C2DSpriteComponent>();
	pPlayer->AddComponent<CPlayerComponent>();
	pPlayer->getComponent<C2DSpriteComponent>()->Render();

	pPlayer->removeComponent< CPlayerComponent> ();

	objectList.push_back(pPlayer);

	
}


CStage::~CStage()
{
}

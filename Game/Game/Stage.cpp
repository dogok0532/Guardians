#include "Stage.h"
#include <algorithm>
#include "GameObject.h"
#include "CharacterComponent.h"
#include "2DSpriteComponent.h"
#include "RectangleComponent.h"
#include "CharacterRenderComponent.h"
#include "PlayerComponent.h"

void CStage::Update(float fDeltaTime)
{
	CScene::Update(fDeltaTime);


	
}

//#include "TextComponent.h"




CStage::CStage()
{
	CGameObject* pPlayer = new CGameObject();

	pPlayer->AddComponent<CCharacterRenderComponent>();
	pPlayer->AddComponent<CCharacterComponent>();
	pPlayer->AddComponent<CPlayerComponent>();
	

	objectList.push_back(pPlayer);

	
}


CStage::~CStage()
{
}

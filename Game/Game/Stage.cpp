#include "Stage.h"
#include <algorithm>
#include "GameObject.h"
#include "CharacterComponent.h"
#include "2DSpriteComponent.h"
#include "RectangleComponent.h"
#include "CharacterRenderComponent.h"
#include "PlayerComponent.h"
#include "TileComponent.h"

void CStage::Update(float fDeltaTime)
{
	CScene::Update(fDeltaTime);


	for (int i = 0; i < vecTile.size(); i++)
	{
		for (int j = 0; j < vecTile.size(); j++)
		{

			vecTile[j][i]->getComponent<CTileComponent>()->Update(fDeltaTime);


			isCollide(vecTile[j][i]->, objectList.front().getComponent<CRectangleComponent>())
		}
	}

	


}

void CStage::Render()
{


	for (int i= vecTile.size()-1;i>=0;i--)
	{
		for (int j = vecTile[i].size()-1; j>=0; j--)
		{
			
			vecTile[j][i]->Render();
		}
	}
	CScene::Render();
}

//#include "TextComponent.h"




CStage::CStage()
{
	CGameObject* pPlayer = new CGameObject();

	pPlayer->AddComponent<CCharacterRenderComponent>();
	pPlayer->AddComponent<CCharacterComponent>();
	pPlayer->AddComponent<CPlayerComponent>();
	
	objectList.push_back(pPlayer);


	//--------------반복--------------->파싱으로 변경//


	for (int i = 0; i < 10; i++)
	{
		vector<CGameObject*> tileRow;
		for (int j = 0; j < 10; j++)
		{
			CGameObject* pTile = new CGameObject();
			pTile->AddComponent<CTileComponent>(i, j,10,10);
			pTile->AddComponent<C2DSpriteComponent>();
			
			

			tileRow.push_back(pTile);
			
		}

		vecTile.push_back(tileRow);
	}

	//-------------------------------//
}


CStage::~CStage()
{
}

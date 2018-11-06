#include "Stage.h"
#include <algorithm>
#include "GameObject.h"
#include "PlayerComponent.h"
#include "2DSpriteComponent.h"
#include "RectangleComponent.h"
//#include "TextComponent.h"

void CStage::Update(float fDeltaTime)
{
	for (auto iter = m_pGaneObjectList.begin(); iter != m_pGaneObjectList.end();iter++)
	{
		(*iter)->Update(fDeltaTime);
	}

}

void CStage::Render()
{
	for (auto iter = m_pGaneObjectList.begin(); iter != m_pGaneObjectList.end(); iter++)
	{
		(*iter)->Render();
	}
}

CStage::CStage()
{
	CGameObject* pPlayer = new CGameObject(L"Player");

	IComponent* component = new CPlayerComponent;
	pPlayer->Add_Component(component);		//플레이어 속성추가
	

	component = new CRectangleComponent;
	pPlayer->Add_Component(component);		//사각형판정 속성 추가
	

	component = new C2DSpriteComponent;	
	pPlayer->Add_Component(component);		//이미지속성 추가
	
	 
	m_pGaneObjectList.push_back(pPlayer);

}


CStage::~CStage()
{
}

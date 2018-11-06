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
	pPlayer->Add_Component(component);		//�÷��̾� �Ӽ��߰�
	

	component = new CRectangleComponent;
	pPlayer->Add_Component(component);		//�簢������ �Ӽ� �߰�
	

	component = new C2DSpriteComponent;	
	pPlayer->Add_Component(component);		//�̹����Ӽ� �߰�
	
	 
	m_pGaneObjectList.push_back(pPlayer);

}


CStage::~CStage()
{
}

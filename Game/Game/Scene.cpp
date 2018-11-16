

#include "Scene.h"
#include "GameObject.h"

void CScene::CreateObject(CGameObject* pGameObject)
{
	objectList.push_back(pGameObject);
}



int CScene::GetSceneChange()
{

	return m_iStageChange;
}




void CScene::Update(float fDeltaTime)
{
	for (auto iter = objectList.begin(); iter != objectList.end();)
	{
		
		(*iter)->Update(fDeltaTime);
		if ((*iter)->isDead())
		{
			delete(*iter);
			objectList.erase(iter++);
		}
		else
			iter++;
	}
}

void CScene::Render()
{
	for (auto iter = objectList.begin(); iter != objectList.end(); iter++)
	{
		(*iter)->Render();
	}
}

CScene::CScene()
{
}


CScene::~CScene()
{
}

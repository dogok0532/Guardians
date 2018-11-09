

#include "Scene.h"
#include "GameObject.h"



int CScene::GetSceneChange()
{


	return m_iStageChange;
}




void CScene::Update(float fDeltaTime)
{
	for (auto iter = objectList.begin(); iter != objectList.end(); iter++)
	{
		(*iter)->Update(fDeltaTime);
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

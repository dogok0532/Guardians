

#include "Scene.h"
#include "GameObject.h"
#include "Observer.h"

int CScene::GetSceneChange()
{
	m_iStageChange;

	
	return m_iStageChange;
}

void CScene::Attach(CObserver* ob)
{
	SceneObserver = ob;
}

void CScene::Detach(CObserver* ob)
{
	delete ob;
	ob = NULL;
}

void CScene::Notify()
{
	SceneObserver->Update();
}

CScene::CScene()
{
}


CScene::~CScene()
{
}

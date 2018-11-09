#pragma once
#include <list>
#include <vector>
#include <array>
#include "IComponent.h"
using namespace std;

class CGameObject;
class CMouse;
class CScene
{

protected:
	list <CGameObject*> objectList;
	array<list<CGameObject*>, maxGroups> groupObjectList;

	
	int m_iStageChange = -1;

public:
	void ProcessMessage();

public:
	int GetSceneChange();
	void Update(float fDeltaTime);
	void Render();
	CScene();
	~CScene();
};
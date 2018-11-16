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


	
	int m_iStageChange = -1;

public:

	void CreateObject(CGameObject* pGameObject);
public:
	int GetSceneChange();
	virtual void Update(float fDeltaTime);
	virtual void Render();
	CScene();
	~CScene();
};
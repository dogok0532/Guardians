#pragma once
#include <list>
using namespace std;

class CGameObject;
class CMouse;
class CScene
{

protected:
	list<CGameObject*> m_pGaneObjectList;

	
	int m_iStageChange = -1;

public:
	void ProcessMessage();

public:
	int GetSceneChange();
	virtual void Update(float fDeltaTime) = 0;
	virtual void Render()=0;
	CScene();
	~CScene();
};
#pragma once
#include <vector>
class CGameObject;
class CMouse;
class CScene
{
protected:
	CMouse* m_pMouse;
	std::vector<CGameObject*> m_pVecUI;
	
	int m_iStageChange = -1;

public:
	int GetSceneChange();
	virtual void Update(float fDeltaTime) = 0;
	virtual void Render()=0;
	CScene();
	~CScene();
};
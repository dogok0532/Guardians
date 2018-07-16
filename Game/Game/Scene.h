#pragma once

#include <vector>
using namespace std;


class CGameObject;
class CMouse;
class CScene
{
protected:
	vector<CGameObject*> m_pVecUI;
	CMouse* m_pMouse;
	int m_iStageChange=-1;

public:
	virtual void Update(float fDeltaTime)=0;
	virtual void Render()=0;

	int StageChangeMessage();

public:
	CScene();
	virtual ~CScene();
};


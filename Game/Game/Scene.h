#pragma once

#include <vector>
using namespace std;


class CGameObject;
class CScene
{
protected:
	vector<CGameObject*> m_pVecUI;

public:
	virtual void Update(float fDeltaTime)=0;
	virtual void Render()=0;

public:
	CScene();
	virtual ~CScene();
};


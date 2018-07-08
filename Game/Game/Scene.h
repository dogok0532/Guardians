#pragma once

#include <list>
using namespace std;


class CGameObject;
class CScene
{
protected:
	list<CGameObject*> m_pUIList;

public:
	virtual void Update(float fDeltaTime)=0;
	virtual void Render()=0;

public:
	CScene();
	virtual ~CScene();
};


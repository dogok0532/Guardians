#pragma once

#include <vector>



#include "mouse.h"
#include "Observer.h"
#include "GameObject.h"

class CScene
{
protected:
	std::vector<CGameObject*> m_pVecUI;
	CMouse* m_pMouse;
	int m_iStageChange=-1;


private:
	CObserver * SceneObserver;
public:
	void Attach(CObserver* ob);
	void Detach(CObserver* ob);
	void Notify();



public:
	virtual void Update(float fDeltaTime)=0;
	virtual void Render()=0;

	int GetSceneChange();

	

public:
	CScene();
	virtual ~CScene();
};


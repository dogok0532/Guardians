#pragma once
#include "Observer.h"

class CScene;
class CSceneOb :
	public CObserver
{
private:
	CScene * pScene;
	int iScene;
public:
	virtual void Update();

public:
	CSceneOb(CScene* pScene);
	virtual ~CSceneOb();
};


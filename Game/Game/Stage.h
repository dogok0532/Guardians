#pragma once
#include "Scene.h"
#include "List"
using namespace std;
class CStage :
	public CScene
{
private:
	vector<vector<CGameObject*>> vecTile;

public:
	virtual void Update(float fDeltaTime);
	virtual void Render();




public:
	CStage();
	virtual ~CStage();
};


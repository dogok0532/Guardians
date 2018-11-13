#pragma once
#include "Scene.h"
#include "List"
using namespace std;
class CStage :
	public CScene
{


public:
	virtual void Update(float fDeltaTime);





public:
	CStage();
	virtual ~CStage();
};


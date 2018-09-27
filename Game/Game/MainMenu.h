#pragma once
#include "Scene.h"
class CMainMenu :
	public CScene
{
public:
	virtual void Update(float deltaTime);
	virtual void Render();

	

public:
	CMainMenu();
	virtual ~CMainMenu();
};


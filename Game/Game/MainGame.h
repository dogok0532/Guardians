#pragma once
#include <vector>
using namespace std;

class CScene;
class CGameObject;
class CMainGame
{
private:
	CScene* m_pCurrentScene=NULL;

	CGameObject* m_pMouse;
	
	

public:
	void Update(float deltaTime);
	void Render();

public:
	CMainGame();
	~CMainGame();
};


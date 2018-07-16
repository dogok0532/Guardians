#pragma once
#include <vector>
using namespace std;

class CScene;
class CGameObject;
class CMainGame
{
private:
	CScene* m_pCurrentScene=NULL;

	
	


public:
	void ChangeScene(int Scene);


	void Update(float deltaTime);
	void Render();

public:
	CMainGame();
	~CMainGame();
};


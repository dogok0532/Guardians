#pragma once
#include <list>
#include <vector>
#include "Scene.h"

using namespace std;

class CGameObject;
class CStage :public CScene
{
private:
	CGameObject * m_pPlayer[2] = { NULL, NULL};
	list<CGameObject*> m_pEnemyList;
	list<CGameObject*> m_pPlayerBulletList;
	list<CGameObject*> m_pEnmeyBulletList;


	int m_iCurrentStage;

	void DestroyCheck();


	float fTimePassed=0;

	

public:
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual bool Destroy();

	void PlayerFire(float deltaTime);
	

public:
	CStage();
	virtual ~CStage();
};


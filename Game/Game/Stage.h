#pragma once
#include <list>
#include <vector>
#include <queue>
#include "Scene.h"

using namespace std;

class CEnemy;
class CItem;
class CGameObject;
class CStage :public CScene
{
private:
	CGameObject * m_pPlayer[2] = { NULL, NULL};
	list<CEnemy*> m_pEnemyList;
	list<CGameObject*> m_pPlayerBulletList;
	list<CGameObject*> m_pEnemeyBulletList;
	list<CItem*> m_pItemList;

	queue<CItem*> m_pItemSpawnQueue;
	queue<CEnemy*> m_pEnemySpawnQueue;

	int m_iCurrentStage;

	void DestroyCheck();


	float fTimePassed=0;

	

public:
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual bool Destroy();

	void PlayerFire(float deltaTime);
	void EnemyFire(float deltaTime);

	
	void RenderIngame(); //�ΰ��ӻ� ��ǥ �����ϸ鼭 �׸���
	void RenderBlackBox();	//���� ���α׷����� �¿�� ĭ�и�


public:
	CStage();
	virtual ~CStage();
};


#pragma once
#include "GameObject.h"

class CEnemyBullet;

class BulletPattern
{

private:
	int iBulletRate; // 단발과 단발사이의 시간차
	int iBulletPerCircle; // 한 사이클당 발사되는 총알수
	
	int iCircleRate; // 사이클과 사이클간 시간차
	
};


class CEnemy :public CGameObject
{
private:
	float m_fBulletPatternTime;


public:
	CEnemy();
	~CEnemy();

	virtual void Update(float deltaTime);


	virtual void Render()=0;

	virtual CEnemyBullet* CreateBullet();
};


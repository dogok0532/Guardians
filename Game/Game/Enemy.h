#pragma once
#include "GameObject.h"

class CEnemyBullet;

class BulletPattern
{

private:
	int iBulletRate; // �ܹ߰� �ܹ߻����� �ð���
	int iBulletPerCircle; // �� ����Ŭ�� �߻�Ǵ� �Ѿ˼�
	
	int iCircleRate; // ����Ŭ�� ����Ŭ�� �ð���
	
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


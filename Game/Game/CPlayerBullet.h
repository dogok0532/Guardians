#pragma once
#include "GameObject.h"
class CPlayerBullet :
	public CGameObject
{
	D3DXVECTOR3 vecSpeed;

	virtual void Update(float deltaTime);
	virtual void Render();



public:


	bool Destroy();	//�޸𸮿��� �����ؾ��ҋ� true �� ��ȯ

public:
	CPlayerBullet();
	virtual ~CPlayerBullet();
};


#pragma once
#include "GameObject.h"
class CItem :
	public CGameObject
{
public:
	CItem();
	virtual ~CItem();

	virtual void Update(float deltaTime);


	virtual void Render()=0;

	void Flying(float deltaTime);	// �밢������ �Դٰ��� �ϴ� �˰���
};


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

	void Flying(float deltaTime);	// 대각선으로 왔다갔다 하는 알고리즘
};


#pragma once
#include "DirectHeader.h"
#include <vector>
#include "SpriteResource.h"
#include <unordered_map>
#include "Sprite.h"

using namespace std;


class IComponent;
class CGameObject
{

protected:  // Render 정보


	wstring m_strGameObjectID;
	unordered_map<wstring, IComponent*> m_mapComponent;


public:


	virtual void Update(float deltaTime);
	
	void HandleMessage();
	
	void Add_Component(IComponent* pComponent); // 컴포넌트 추가
	void Remove_Component(wstring componentName); // 컴포넌트 삭제



	




public:
	CGameObject();
	virtual ~CGameObject();
};




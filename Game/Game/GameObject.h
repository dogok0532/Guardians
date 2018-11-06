#pragma once
#include "DirectHeader.h"
#include <vector>
#include "SpriteResource.h"
#include <unordered_map>
#include "Sprite.h"
#include "Message.h"

using namespace std;


class IComponent;
class CGameObject
{

protected:  // Render 정보


	wstring m_strGameObjectID;
	unordered_map<wstring, IComponent*> m_mapComponent;


public:


	virtual void Update(float deltaTime);
	virtual void Render();
	
	
	void Add_Component(IComponent* pComponent); // 컴포넌트 추가
	void Remove_Component(wstring componentName); // 컴포넌트 삭제
	IComponent* GetComponent(wstring ComponentID);
	
	
	




public:
	CGameObject(wstring m_strGameObjectID);
	virtual ~CGameObject();
};




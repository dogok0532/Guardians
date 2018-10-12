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

protected:  // Render ����


	wstring m_strGameObjectID;
	unordered_map<wstring, IComponent*> m_mapComponent;


public:


	virtual void Update(float deltaTime);
	
	void HandleMessage();
	
	void Add_Component(IComponent* pComponent); // ������Ʈ �߰�
	void Remove_Component(wstring componentName); // ������Ʈ ����



	




public:
	CGameObject();
	virtual ~CGameObject();
};




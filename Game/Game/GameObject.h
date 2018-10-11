#pragma once
#include "DirectHeader.h"
#include <vector>
#include "SpriteResource.h"
#include <map>
#include "Sprite.h"

using namespace std;


class IComponent;
class CGameObject
{

protected:  // Render Á¤º¸


	wstring m_strGameObjectID;
	map<wstring, IComponent*> m_mapComponent;


public:


	virtual void Update(float deltaTime);





public:
	CGameObject();
	virtual ~CGameObject();
};




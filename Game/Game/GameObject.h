#pragma once

#include <list>


#include "IComponent.h"
using namespace std;


class IComponent;
class CGameObject
{

protected:  
	ComponentArray componentArray;
	ComponentBitSet componentBitSet;

	

public:
	CGameObject* CreateObject();

	virtual void Update(float deltaTime);
	virtual void Render();

	
	template <typename T> 
	T& AddComponent()
	{
		T* newComponent = new T();
		newComponent->SetOwner(this);
		componentArray[getComponentID<T>()] = newComponent;
		componentBitSet[getComponentID<T>()]=true;

		return *newComponent;
	}

	template <typename T> void removeComponent()
	{
		delete componentArray[getComponentID <T>() ];
		componentArray[getComponentID <T>()] = NULL;
		componentBitSet[getComponentID <T>() ] = false;
	}
	

	template<typename T> T* getComponent() const //has기능도 가능
	{
		auto ptr = componentArray[getComponentID<T>()];
		return static_cast<T*>(ptr);
	}


private:
	bool m_isDead = false;
public:
	bool isDead();
	void SetDead();

public:
	CGameObject();
	virtual ~CGameObject();
};




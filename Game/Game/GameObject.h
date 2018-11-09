#pragma once

#include <list>


#include "Message.h"
#include "IComponent.h"
using namespace std;


class IComponent;
class CGameObject
{

protected:  
	ComponentArray componentArray;
	ComponentBitSet componentBitSet;
	GroupBitset groupBitSet;

	

public:


	virtual void Update(float deltaTime);
	virtual void Render();
	
	void AddGroup(GROUP group);
	void RemoveGroup(GROUP group);

	
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
	

	template<typename T> T* getComponent() const
	{
		auto ptr = componentArray[getComponentID<T>()];
		return static_cast<T*>(ptr);
	}


public:
	CGameObject();
	virtual ~CGameObject();
};




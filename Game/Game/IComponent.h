#pragma once


#include <string>
using namespace std;


#include "Message.h"
#include <bitset>
#include <array>


using ComponentID = std::size_t;
using GROUP = std::size_t;


inline ComponentID getNewComponentID()
{
	static ComponentID lastID = 0u;
	return lastID++;
}

template <typename T> inline ComponentID getComponentID() noexcept
{
	static_assert(std::is_base_of<IComponent, T>::value, "");
	static ComponentID typeID = getNewComponentID();
	return typeID;
}

const std::size_t maxComponents = 32;
const std::size_t maxGroups = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using GroupBitset = std::bitset<maxGroups>;
using ComponentArray = std::array<IComponent*, maxComponents>;




class CGameObject;
class IComponent
{
	

protected:
	const CGameObject* m_pOwner;
	

public:
	virtual void Update(float deltaTime);
	virtual void Render();

	void SetOwner(const CGameObject* pGameObject);
	const CGameObject* GetOwner();



public:
	IComponent();
	virtual ~IComponent()=0;
};


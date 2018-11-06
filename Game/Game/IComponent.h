#pragma once


#include <string>
using namespace std;

class CGameObject;
class CEntity;
#include "Message.h"
class IComponent
{
	

protected:
	wstring strComponentID;
	CGameObject* m_pOwner;

	

public:
	virtual void Update(float deltaTime);
	virtual void Render();

	void SetOwner(CGameObject* pGameObject);
	const CGameObject* GetOwner();

	virtual const wstring GetComponentID()=0;
	virtual const wstring GetFamilyID()=0;

public:
	void Process(CMessage msg);

public:
	IComponent();
	virtual ~IComponent()=0;
};


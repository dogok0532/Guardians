#pragma once
class CGameObject
{
private:
	float m_fX;
	float m_fY;
	
	
public:
	virtual void Update();
	virtual void Render();

public:
	CGameObject();
	virtual ~CGameObject();
};


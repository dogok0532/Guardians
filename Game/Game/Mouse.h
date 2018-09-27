#pragma once
#include "UI.h"
class CMouse :
	public CUI
{
public:

	bool m_bDown;
	bool m_bClicked;
	

	bool bRender = true;


	virtual void Update(float deltaTime);
	virtual void Render();
	virtual bool Destroy();

	bool bClicked();


public:
	CMouse();
	virtual ~CMouse();
};


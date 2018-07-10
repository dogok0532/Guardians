#pragma once
#include "UI.h"
class CGameButton :
	public CUI
{
private:
	wstring m_strButtonName;
	bool m_bButtonState=false;

	bool m_bClicked = false;

public:
	virtual void Update(float deltaTime);
	virtual void Render();

	void SetButtonName(wstring str);
	

public:
	CGameButton();
	virtual ~CGameButton();
};


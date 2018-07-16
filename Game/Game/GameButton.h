#pragma once
#include "UI.h"

class CMouse;
class CGameButton :
	public CUI
{
private:
	wstring m_strButtonName;
	bool m_bButtonState=false;

	bool m_iButtonClicked = 0;

	
	

public:
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual bool Destroy();

	void SetButtonName(wstring str);
	void SetUIState(CMouse* mouse);
	bool ButtonClicked();

public:
	CGameButton();
	virtual ~CGameButton();
};


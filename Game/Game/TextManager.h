#pragma once
#include "Defines.h"
#include "DirectHeader.h"
#include <string>
using namespace std;

class CTextManager
{
private:
	wstring m_strText = L"";
	UINT32 m_iTextLength = 0;

	ID3DXFont* m_pFont;


	RECT m_rcTextRange;

	D3DCOLOR m_Color = DEFAULT_COLOR;

public:
	void Init();
	void Release();

public:


	void Render();



	void SetTextRange(RECT rc);
	void SetTextRange(int left, int top, int right, int bottom);

	void SetText(wstring);
	void SetFormat();
	void SetColor(D3DCOLOR color);


	DECLARE_SINGLETON(CTextManager)
};


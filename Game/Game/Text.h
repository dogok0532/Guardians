#pragma once
#include "Defines.h"
#include "DirectHeader.h"
#include <string>
using namespace std;

class IDWriteTextLayout;
class CText
{
private:
	IDWriteTextLayout* pTextLayout_;



	wstring m_strText = L"";
	UINT32 m_iTextLength = 0;

	ID3DXFont* m_pFont;


	RECT m_rcTextRange;

	D3DCOLOR m_Color = DEFAULT_COLOR;

	
	D3DXFONT_DESC DXFont_DESC;
	DWORD DTFormat;

private:
	D3DXMATRIX m_MatWorld;

public:
	void Init();
	void Reset();
	void Release();

public:


	void Render();



	void SetTextRange(RECT rc);
	void SetTextRange(int left, int top, int right, int bottom);

	void SetText(wstring);
	void SetFormat();
	void SetColor(D3DCOLOR color);
	void SetSize(int size);
	void SetOption(DWORD format);	//중앙,좌측,우측,위,아래 등 설정

	CText();
	~CText();
};


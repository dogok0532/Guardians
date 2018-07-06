#pragma once
#include "Defines.h"
#include <DWrite.h>
#include <d2d1.h>

class CTextManager
{
private:
	IDWriteFactory* m_pDWriteFactory;
	IDWriteTextFormat* m_pTextFormat;
	
	
	wstring m_strText;
	UINT32 m_iTextLength;

	ID2D1Factory* m_pD2DFactory;
	ID2D1HwndRenderTarget* m_pRT;
	ID2D1SolidColorBrush* m_pBlackBrush;


public:
	void SetText(wstring);
	void SetFormat();


	DECLARE_SINGLETON(CTextManager)
};


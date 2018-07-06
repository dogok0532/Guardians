#include "stdafx.h"
#include "TextManager.h"

IMPLEMENT_SINGLETON(CTextManager)

CTextManager::CTextManager()
{
	HRESULT hr = D2D1CreateFactory(
		D2D1_FACTORY_TYPE_SINGLE_THREADED,
		&m_pD2DFactory
	);

	if (SUCCEEDED(hr))
	{
		hr = DWriteCreateFactory(
			DWRITE_FACTORY_TYPE_SHARED,
			__uuidof(IDWriteFactory),
			reinterpret_cast<IUnknown**>( &m_pDWriteFactory)
		);
	}

	HRESULT hr = m_pDWriteFactory->CreateTextFormat(
		L"Gabriola",                // Font family name.
		NULL,                       // Font collection (NULL sets it to use the system font collection).
		DWRITE_FONT_WEIGHT_REGULAR,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		72.0f,
		L"en-us",
		&m_pTextFormat
	);

	if (SUCCEEDED(hr))
	{
		hr = m_pTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
	}

}


CTextManager::~CTextManager()
{
}

void CTextManager::SetText(wstring strText)
{
	m_strText = strText;
	m_iTextLength = strText.length();
}

void CTextManager::SetFormat()
{

}


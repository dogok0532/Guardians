
#include "TextManager.h"
#include "direct.h"

using namespace std;

IMPLEMENT_SINGLETON(CTextManager)



void CTextManager::Init()
{
	D3DXFONT_DESC DXFont_DESC;
	ZeroMemory(&DXFont_DESC, sizeof(DXFont_DESC));

	DXFont_DESC.Height = 40;
	DXFont_DESC.Width = 20;
	DXFont_DESC.Weight = FW_NORMAL;
	DXFont_DESC.MipLevels = D3DX_DEFAULT;
	DXFont_DESC.Italic = false;
	DXFont_DESC.CharSet = DEFAULT_CHARSET;
	DXFont_DESC.OutputPrecision=OUT_DEFAULT_PRECIS;
	DXFont_DESC.Quality= ANTIALIASED_QUALITY;
	DXFont_DESC.PitchAndFamily = DEFAULT_PITCH;
	wcscpy_s(DXFont_DESC.FaceName, sizeof(L"µ¸¿òÃ¼"), L"µ¸¿òÃ¼");
	

	HRESULT hr;
	hr = D3DXCreateFontIndirect(CDirect::GetInstance()->GetDevice(),
		&DXFont_DESC,
		&m_pFont);

	if (FAILED(hr))
	{
		return;
	}

}

void CTextManager::Release()
{
	
}



void CTextManager::Render()
{

	m_pFont->DrawTextW(NULL,
		m_strText.c_str(), m_iTextLength, &m_rcTextRange, DT_LEFT|DT_TOP, D3DCOLOR_ARGB(255, 255, 255, 255));

}


void CTextManager::SetTextRange(RECT rc)
{
	m_rcTextRange = rc;
}

void CTextManager::SetTextRange(int left, int top, int right, int bottom)
{
	m_rcTextRange.left=left;
	m_rcTextRange.top=top;
	m_rcTextRange.right=right;
	m_rcTextRange.bottom=bottom;
}

void CTextManager::SetText(wstring strText)
{
	m_strText = strText;
	m_iTextLength = strText.length();
}

void CTextManager::SetFormat()
{

}

CTextManager::CTextManager()
{

}


CTextManager::~CTextManager()
{
}
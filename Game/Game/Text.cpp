
#include "Text.h"
#include "direct.h"

using namespace std;



void CText::Init()
{
	
	
	ZeroMemory(&DXFont_DESC, sizeof(DXFont_DESC));

	DXFont_DESC.Height = 20;
	DXFont_DESC.Width = 10;
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

void CText::Reset()
{
	if (m_pFont)
		m_pFont->Release();
	Init();
}

void CText::Release()
{
	if (m_pFont)
		m_pFont->Release();
}



void CText::Render()
{	
	m_pFont->DrawTextW(CDirect::GetInstance()->GetSprite(),
		m_strText.c_str(), m_iTextLength, &m_rcTextRange,
		DTFormat, m_Color);
}


void CText::SetTextRange(RECT rc)
{
	m_rcTextRange = rc;
}

void CText::SetTextRange(int left, int top, int right, int bottom)
{
	m_rcTextRange.left=left;
	m_rcTextRange.top=top;
	m_rcTextRange.right=right;
	m_rcTextRange.bottom=bottom;
}

void CText::SetText(wstring strText)
{
	m_strText = strText;
	m_iTextLength = strText.length();
}

void CText::SetFormat()
{
}

void CText::SetColor(D3DCOLOR color)
{
	m_Color = color;
}

void CText::SetSize(int size)
{
	DXFont_DESC.Width = size;
	DXFont_DESC.Height = size * 2;
	Reset();
}

void CText::SetOption(DWORD format)
{
	DTFormat = format;
}

CText::CText()
{
	m_pFont = NULL;
	DTFormat = DT_CENTER | DT_VCENTER;
}


CText::~CText()
{
}
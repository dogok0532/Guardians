#include "Mouse.h"
#include <windows.h>
#include "Defines.h"

extern HWND g_hWnd;

void CMouse::Update(float deltaTime)
{
	POINT Point;

	GetCursorPos(&Point);
	ScreenToClient(g_hWnd, &Point);

	m_GameInfo.vecPos.x = Point.x;
	m_GameInfo.vecPos.y = Point.y;

	if(GetAsyncKeyState(VK_LBUTTON))
	{
		m_bDown = true;
	}
	else
	{
		if (m_bDown)
		{
			m_bClicked = true;
		}
		else
		{
			m_bClicked = false;
		}

		m_bDown = false;
	}
	CGameObject::Update(deltaTime);
}


void CMouse::Render()
{
	ShowCursor(bRender);
	
}

bool CMouse::Destroy()
{
	return false;
}

bool CMouse::bClicked()
{
	return m_bClicked;

}



CMouse::CMouse()
{
}


CMouse::~CMouse()
{
}

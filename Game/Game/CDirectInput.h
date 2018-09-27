#pragma once
#pragma comment(lib, "dinput8.lib") 
#pragma comment(lib, "dxguid.lib")


#include <dinput.h>


class CDirectInput
{
	

private:
	IDirectInput8* m_directInput;
	IDirectInputDevice8* m_keyboard;
	IDirectInputDevice8* m_mouse;


public:
	unsigned char m_keyboardState[256];



public:
	HRESULT Init(HINSTANCE hInstance, HWND hWnd, int wincx, int wincy);


	bool GetKeyInput();

public:
	CDirectInput();
	virtual ~CDirectInput();
};


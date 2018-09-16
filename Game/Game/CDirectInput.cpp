#include "CDirectInput.h"



HRESULT CDirectInput::Init(HINSTANCE hInstance, HWND hWnd, int wincx, int wincy)
{
	HRESULT result;

	result = DirectInput8Create(hInstance,
		DIRECTINPUT_VERSION, IID_IDirectInput8,
		(void**)&m_directInput, NULL);
	if (FAILED(result))
	{
		return result;
	}

	result = m_directInput->CreateDevice(GUID_SysKeyboard, &m_keyboard, NULL);
	if (FAILED(result))
	{
		return result;
	}


	result = m_keyboard->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(result))
	{
		return result;
	}


	
	result = m_keyboard->SetCooperativeLevel(hWnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(result))
	{
		return result;
	}
	result = m_keyboard->Acquire();
	if (FAILED(result))
	{
		return result;
	}

	return S_OK;

}

bool CDirectInput::GetKeyInput()
{
	HRESULT result; // Read the keyboard device.
	result = m_keyboard->GetDeviceState(sizeof(m_keyboardState),
		(LPVOID)&m_keyboardState);
	if (FAILED(result))
	{
		// If the keyboard lost focus or was not acquired then try to get control back.
		if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED)) 
		{ 
			m_keyboard->Acquire(); 
			m_keyboardState;
			int a = 0;
		}
		else
		{
			return false;
		}
	} return true;


}

CDirectInput::CDirectInput()
{
}


CDirectInput::~CDirectInput()
{
}

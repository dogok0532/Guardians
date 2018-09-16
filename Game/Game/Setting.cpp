#include "Setting.h"

#include <Windows.h>
#include "TextBox.h"
CSetting::CSetting()
{

	pTextBox = new CTextBox;
}



CSetting::~CSetting()
{
}

void CSetting::Update(float fDeltaTime)
{
	pTextBox->Update(fDeltaTime);
	
}

void CSetting::Render()
{
	
}

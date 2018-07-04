#pragma once
#include <list>
class CMainGame
{
private:

public:
	void Update();
	void Render();


public:
	CMainGame(HDC hdc, HINSTANCE Instance);
	virtual ~CMainGame();
};


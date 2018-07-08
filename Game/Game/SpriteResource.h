#pragma once
#include "Defines.h"
#include <Map>
#include "DirectHeader.h"
using namespace std;

class CSpriteResource
{
private:
	map<wstring,LPDIRECT3DTEXTURE9> mapTexture;

public:
	void AddImageFile(wstring);
	LPDIRECT3DTEXTURE9 GetImage(wstring);

	DECLARE_SINGLETON(CSpriteResource)
};


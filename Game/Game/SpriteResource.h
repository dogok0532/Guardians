#pragma once
#include "Defines.h"
class CSpriteResource
{
private:
	map<string,LPDIRECT3DTEXTURE9> mapTexture;

public:
	void AddImageFile(wstring);

	DECLARE_SINGLETON(CSpriteResource)
};


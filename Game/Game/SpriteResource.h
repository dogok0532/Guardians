#pragma once
#include "Defines.h"
#include <Map>
#include "DirectHeader.h"
#include "Texture.h"

using namespace std;


class CSpriteResource
{
private:
	map<wstring, CTexture*> mapTexture;

public:
	void AddImageFile(wstring);
	CTexture* GetTextureInfo(wstring);
	

	DECLARE_SINGLETON(CSpriteResource)
};


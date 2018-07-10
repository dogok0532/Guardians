#pragma once
#include "Defines.h"
#include <Map>
#include "DirectHeader.h"
using namespace std;

struct TextureInfo
{
	LPDIRECT3DTEXTURE9 pTexture;
	D3DXIMAGE_INFO ImageInfo;
};

class CSpriteResource
{
private:
	map<wstring, TextureInfo> mapTexture;

public:
	void AddImageFile(wstring);
	TextureInfo GetTextureInfo(wstring);
	

	DECLARE_SINGLETON(CSpriteResource)
};


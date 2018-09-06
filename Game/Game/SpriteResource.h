#pragma once
#include "Defines.h"
#include <Map>
#include "DirectHeader.h"
#include "Texture.h"
#include "Sprite.h"
using namespace std;


class CSpriteResource
{
private:
	map<wstring, Texture*> mapTexture;

public:
	void AddImageFile(wstring, int FrameX,int FrameY);
	Texture* GetTextureInfo(wstring);
	
	void Draw(wstring, wstring,int);

public:
	CSpriteResource();
	~CSpriteResource();
};


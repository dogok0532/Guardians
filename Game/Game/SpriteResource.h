#pragma once
#include "Defines.h"
#include <Map>
#include "DirectHeader.h"
#include "CTexture.h"
#include "Sprite.h"
using namespace std;


class CSpriteResource
{
private:
	map<wstring, CTexture*> mapTexture;

	map<wstring, CTexture*> mapTextureFix;//������ �ؽ�ó ��

public:
	void AddImageFile(wstring, int FrameX,int FrameY);


	CTexture* GetTextureInfo(wstring);
	
	void Draw(wstring, wstring,int);

public:
	CSpriteResource();
	~CSpriteResource();
};


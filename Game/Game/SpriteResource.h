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

	map<wstring, CTexture*> mapTextureFix;//수정된 텍스처 맵


public:
	void AddImageFile(wstring, int FrameX,int FrameY);


	CTexture* GetTextureInfo(wstring);
	
	void Render(wstring Texture, wstring Sprite, int Frame, ObjectInfo* pGameInfo);

	void RenderWholeTexture(wstring Texture, ObjectInfo* pGameInfo);
public:
	CSpriteResource();
	~CSpriteResource();

};


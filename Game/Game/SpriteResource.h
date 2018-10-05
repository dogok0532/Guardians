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

	map<wstring, CTexture*> mapTextureFix;//수정된 텍스처 맵


public:

	void Render(wstring Texture, wstring Sprite, int Frame, RenderInfo* pGameInfo);
	void RenderWholeSprite(wstring Texture, wstring Sprite, RenderInfo* pGameInfo);
	void RenderWholeTexture(wstring Texture, RenderInfo* pGameInfo);

	D3DXVECTOR3 GetTextureSize(wstring Texture);
	D3DXVECTOR3 GetSpriteSize(wstring Texture, wstring Sprite);

public:
	CSpriteResource();
	~CSpriteResource();

};


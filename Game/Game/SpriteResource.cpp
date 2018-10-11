
#include "SpriteResource.h"
#include "direct.h"
#include "CTexture.h"
#include "CGameObject.h"

#include "tinyxml.h"
#include "SpriteParser.h"

#include <iostream>






void CSpriteResource::Render(wstring Texture, wstring Sprite, int Frame, RenderInfo* pGameInfo)
{
	if(mapTextureFix[Texture] !=NULL)
		mapTextureFix[Texture]->Draw(Sprite, Frame,pGameInfo);
}

void CSpriteResource::RenderWholeSprite(wstring Texture, wstring Sprite, RenderInfo* pGameInfo)
{
	mapTextureFix[Texture]->DrawWholeSprite(Sprite,pGameInfo);
}

void CSpriteResource::RenderWholeTexture(wstring Texture, RenderInfo* pGameInfo)
{
	mapTextureFix[Texture]->DrawWholeTexture(pGameInfo);
}

D3DXVECTOR3 CSpriteResource::GetTextureSize(wstring Texture)
{
	return mapTextureFix[Texture]->GetSize();
}

D3DXVECTOR3 CSpriteResource::GetSpriteSize(wstring Texture, wstring Sprite)
{
	return mapTextureFix[Texture]->GetSpriteSize(Sprite);
}

CSpriteResource::CSpriteResource()
{
	CSpriteParser parser;

	

	while (1)//Texture가 끝날때까지
	{
		wstring textureName = parser.GetTextureName();
		if (parser.ParseEnd())
			break;

		CTexture* pTexture = parser.GetTexture();
		

		mapTextureFix.insert(make_pair(textureName, pTexture));
	}



	
}

CSpriteResource::~CSpriteResource()
{
	map<wstring, CTexture*>::iterator iter = mapTextureFix.begin();

	for (; iter != mapTextureFix.end();)
	{
		
		if (iter->second)
		{
			iter->second->Release();
			delete iter->second;
		}
		iter++;
	}
}
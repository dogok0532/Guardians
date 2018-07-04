#include "stdafx.h"
#include "SpriteResource.h"
#include "direct.h"

IMPLEMENT_SINGLETON(CSpriteResource)

void CSpriteResource::AddImageFile(wstring fileName)
{
	LPDIRECT3DTEXTURE9 pTexture=NULL;


	wstring strPath= L"../\\Sprite\\." + fileName + L".png";

	D3DXCreateTextureFromFile(CDirect::GetInstance()->GetDevice(),
		strPath.c_str(),
		&pTexture);
}

CSpriteResource::CSpriteResource()
{

}

CSpriteResource::~CSpriteResource()
{

}
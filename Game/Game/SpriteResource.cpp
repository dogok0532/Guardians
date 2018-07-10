
#include "SpriteResource.h"
#include "direct.h"

IMPLEMENT_SINGLETON(CSpriteResource)

void CSpriteResource::AddImageFile(wstring fileName)
{
	LPDIRECT3DTEXTURE9 pTexture=NULL;
	D3DXIMAGE_INFO ImageInfo;
	
	

	wstring strPath= L"../\\Resource\\Sprite\\" + fileName + L".png";
	D3DXGetImageInfoFromFile(strPath.c_str(), &ImageInfo);


	D3DXCreateTextureFromFile(CDirect::GetInstance()->GetDevice(),
		strPath.c_str(),
		&pTexture);

	TextureInfo textureInfo;
	textureInfo.pTexture = pTexture;
	textureInfo.ImageInfo = ImageInfo;

	mapTexture.insert(make_pair(fileName, textureInfo));

	
}

TextureInfo CSpriteResource::GetTextureInfo(wstring fileName)
{
	map<wstring, TextureInfo>::iterator iter;
	iter = mapTexture.find(fileName);
	return iter->second;
}





CSpriteResource::CSpriteResource()
{
	//json 스크립트 파일로 다시 만들것

	AddImageFile(L"Enemy_Bullet");
	AddImageFile(L"Enemy_Helicpoter_Clear");
	AddImageFile(L"Enemy_Helicpoter_Crushed");
	AddImageFile(L"Enemy_SpaceShip_Clear");
	AddImageFile(L"Enemy_SpaceShip_Crushed");
	AddImageFile(L"Enemy_Tank_Clear");
	AddImageFile(L"Enemy_Tank_Crushed");
	AddImageFile(L"Stage_Land");
	AddImageFile(L"Stage_Sky");
	AddImageFile(L"Stage_Space");
	AddImageFile(L"User_Center");
	AddImageFile(L"User_Left");
	AddImageFile(L"User_Missile");
	AddImageFile(L"User_Right");


	AddImageFile(L"Button");
	AddImageFile(L"Button2");


}

CSpriteResource::~CSpriteResource()
{

}
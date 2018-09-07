
#include "SpriteResource.h"
#include "direct.h"
#include "CTexture.h"
#include "GameObject.h"

#include "tinyxml.h"
#include "Parser.h"

#include <iostream>





void CSpriteResource::AddImageFile(wstring fileName, int FrameX=1, int FrameY=1)
{

	wstring strPath = L"../\\Resource\\Sprite\\" + fileName + L".png";
	CTexture* pTexture = new CTexture(strPath.c_str());
	
	

	mapTexture.insert(make_pair(fileName, pTexture));

	
}

CTexture* CSpriteResource::GetTextureInfo(wstring fileName)
{
	
	map<wstring, CTexture*>::iterator iter;
	iter = mapTexture.find(fileName);
	return iter->second;
}





void CSpriteResource::Draw(wstring Texture, wstring Sprite,int Frame)
{
	mapTexture[Texture]->Draw(Sprite,Frame);
}

CSpriteResource::CSpriteResource()
{
	CParser parser;

	

	while (1)//Texture가 끝날때까지
	{
		wstring textureName = parser.GetTextureName();
		if (parser.ParseEnd())
			break;

		CTexture* pTexture = parser.GetTexture();

		mapTextureFix.insert(make_pair(textureName, pTexture));
	}

	AddImageFile(L"Enemy_Bullet");
	AddImageFile(L"Enemy_Helicpoter_Clear",2,1);
	AddImageFile(L"Enemy_Helicpoter_Crushed",2,1);
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
	map<wstring, CTexture*>::iterator iter = mapTexture.begin();

	for (; iter != mapTexture.end();)
	{
		
		if (iter->second)
		{
			iter->second->Release();
			delete iter->second;
		}
		iter++;
	}
}
#pragma once
#include <string>
#include <windows.h>
#include "Sprite.h"
#include "tinyxml.h"
using namespace std;

class CTexture;

class CSpriteParser
{
private:
	TiXmlDocument XmlFile;



	TiXmlElement* XmlRoot=NULL;
	TiXmlElement* XmlTexture = NULL;


	TiXmlElement* XmlName = NULL;
	TiXmlElement* XmlPath = NULL;
	TiXmlElement* XmlBackground = NULL;
	TiXmlElement* XmlSprite = NULL;

public:
	CTexture* GetTexture();

public:
	wstring GetTextureName();
	wstring GetTexturePath();
	DWORD GetBackgroundRGB();
	spriteInfo GetSpriteInfo();

public:
	bool ParseEnd();

public:
	CSpriteParser();
	~CSpriteParser();

};


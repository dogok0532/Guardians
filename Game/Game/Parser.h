#pragma once
#include <string>
#include <windows.h>
#include "Sprite.h"
#include "tinyxml.h"
using namespace std;

class CTexture;

class CParser
{
private:
	TiXmlDocument XmlFile;



	TiXmlElement* XmlRoot;
	TiXmlElement* XmlTexture;


	TiXmlElement* XmlName;
	TiXmlElement* XmlPath;
	TiXmlElement* XmlBackground;
	TiXmlElement* XmlSprite;

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
	CParser();
	~CParser();

};


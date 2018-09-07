
#include "Parser.h"
#include "CTexture.h"

CTexture* CParser::GetTexture()
{

	wstring path = GetTexturePath();
	CTexture* pTexture = new CTexture(path);
	pTexture->SetColorKey(GetBackgroundRGB());
	
	while (XmlSprite !=NULL && !XmlSprite->NoChildren())
	{
		string strName= XmlSprite->FirstChildElement("Name")->GetText();
		wstring wstrName;
		wstrName.assign(strName.begin(), strName.end());
		spriteInfo SpriteInfo = GetSpriteInfo();
		XmlSprite =XmlSprite->NextSiblingElement();
		pTexture->SetSprite(wstrName,
			&SpriteInfo);
	
	}
	
	
	XmlTexture=XmlTexture->NextSiblingElement();
	if (XmlTexture)
	{
		XmlName = XmlTexture->FirstChildElement("Name");
		XmlPath = XmlTexture->FirstChildElement("Path");
		XmlBackground = XmlTexture->FirstChildElement("BackgroundRGB");
		XmlSprite = XmlTexture->FirstChildElement("Sprite");

	}

	return pTexture;
}

std::wstring CParser::GetTextureName()
{
	string name = XmlName->GetText();
	if (XmlName == NULL)
	{
		return L"";
	}


	wstring returnName;
	returnName.assign(name.begin(), name.end());
	return returnName;
	
}
	

std::wstring CParser::GetTexturePath()
{
	

	string name = XmlPath->GetText();
	wchar_t returnName[128];
	MultiByteToWideChar(CP_UTF8, 0, name.c_str(), strlen(name.c_str())+1, returnName, strlen(name.c_str())+1);


	return returnName;
}

DWORD CParser::GetBackgroundRGB()
{
	if (XmlBackground == NULL || XmlBackground->NoChildren())
	{
		return D3DCOLOR_ARGB(255, 255, 255, 255);
	}


	

	return 0;
}

spriteInfo CParser::GetSpriteInfo()
{
	
	char strValue[32];
	strcpy_s(strValue, XmlSprite->FirstChildElement("XBegin")->GetText());

	strcpy_s(strValue, XmlSprite->FirstChildElement("YBegin")->GetText());

	strcpy_s(strValue, XmlSprite->FirstChildElement("isLine")->GetText());

	strcpy_s(strValue, XmlSprite->FirstChildElement("FrameCount")->GetText());

	strcpy_s(strValue, XmlSprite->FirstChildElement("XFrame")->GetText());

	strcpy_s(strValue, XmlSprite->FirstChildElement("YFrame")->GetText());

	strcpy_s(strValue, XmlSprite->FirstChildElement("XSize")->GetText());

	strcpy_s(strValue, XmlSprite->FirstChildElement("YSize")->GetText());



	spriteInfo SpriteInfo;
	SpriteInfo.iFrameCount = 0;
	SpriteInfo.iIsLine = 0;
	SpriteInfo.iXBegin = 0;
	SpriteInfo.iXFrame = 0;
	SpriteInfo.iXSize = 0;
	SpriteInfo.iYBegin = 0;
	SpriteInfo.iYFrame = 0;
	SpriteInfo.iYSize = 0;

	return SpriteInfo;
}

bool CParser::ParseEnd()
{
	return !XmlTexture;
}

CParser::CParser()
{
	
	//스크립트로 'Texture'생성 및 추가 AddImageFile();
	//스크립트로 'Texture' 내부 Sprite추가


	XmlFile.LoadFile("..\\script\\TextureList.xml");
	XmlRoot = XmlFile.FirstChildElement("TextureList");
	XmlTexture = XmlRoot->FirstChildElement("Texture");


	XmlName = XmlTexture->FirstChildElement("Name");
	XmlPath = XmlTexture->FirstChildElement("Path");
	XmlBackground = XmlTexture->FirstChildElement("BackgroundRGB");
	XmlSprite = XmlTexture->FirstChildElement("Sprite");


	
}


CParser::~CParser()
{
}

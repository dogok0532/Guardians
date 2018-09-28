
#include "SpriteParser.h"
#include "CTexture.h"
#include "Defines.h"

CTexture* CSpriteParser::GetTexture()
{

	wstring path = GetTexturePath();
	D3DCOLOR color = GetBackgroundRGB();
	CTexture* pTexture = new CTexture();
	pTexture->SetDevice(path, color);
	
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

std::wstring CSpriteParser::GetTextureName()
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
	

std::wstring CSpriteParser::GetTexturePath()
{
	

	string name = XmlPath->GetText();
	wchar_t returnName[128];
	MultiByteToWideChar(CP_UTF8, 0, name.c_str(), strlen(name.c_str())+1, returnName, strlen(name.c_str())+1);


	return returnName;
}

DWORD CSpriteParser::GetBackgroundRGB()
{
	if (XmlBackground == NULL || XmlBackground->NoChildren())
	{
		return D3DCOLOR_ARGB( 255,255, 255, 255);
	}
	string r = XmlBackground->FirstChildElement("R")->GetText();
	string g = XmlBackground->FirstChildElement("G")->GetText();
	string b = XmlBackground->FirstChildElement("B")->GetText();

	int iR=atoi(r.c_str());
	int iG=atoi(g.c_str());
	int iB=atoi(b.c_str());

	
	return D3DCOLOR_ARGB(255,iR, iG, iB);


}

spriteInfo CSpriteParser::GetSpriteInfo()
{
	spriteInfo SpriteInfo;
	

	CSprite* pSprite = new CSprite;

	char strValue[32];
	int iValue;

	strcpy_s(strValue, XmlSprite->FirstChildElement("XBegin")->GetText());
	iValue =atoi(strValue);
	SpriteInfo.iXBegin = iValue;

	strcpy_s(strValue, XmlSprite->FirstChildElement("YBegin")->GetText());
	iValue = atoi(strValue);
	SpriteInfo.iYBegin = iValue;


	strcpy_s(strValue, XmlSprite->FirstChildElement("isLine")->GetText());
	iValue = atoi(strValue);
	SpriteInfo.iIsLine = iValue;


	strcpy_s(strValue, XmlSprite->FirstChildElement("FrameCount")->GetText());
	iValue = atoi(strValue);
	SpriteInfo.iFrameCount = iValue;

	strcpy_s(strValue, XmlSprite->FirstChildElement("XFrame")->GetText());
	iValue = atoi(strValue);
	SpriteInfo.iXFrame = iValue;

	strcpy_s(strValue, XmlSprite->FirstChildElement("YFrame")->GetText());
	iValue = atoi(strValue);
	SpriteInfo.iYFrame = iValue;

	strcpy_s(strValue, XmlSprite->FirstChildElement("XSize")->GetText());
	iValue = atoi(strValue);
	SpriteInfo.iXSize = iValue;

	strcpy_s(strValue, XmlSprite->FirstChildElement("YSize")->GetText());
	iValue = atoi(strValue);
	SpriteInfo.iYSize = iValue;

	pSprite->SetSpriteInfo(&SpriteInfo);

	
	return SpriteInfo;
}

bool CSpriteParser::ParseEnd()
{
	return !XmlTexture;
}

CSpriteParser::CSpriteParser()
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


CSpriteParser::~CSpriteParser()
{

	XmlFile.Clear();
}

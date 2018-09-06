
#include "SpriteResource.h"
#include "direct.h"
#include "Texture.h"
#include "GameObject.h"

#include "tinyxml.h"


#include <iostream>





void CSpriteResource::AddImageFile(wstring fileName, int FrameX=1, int FrameY=1)
{

	wstring strPath = L"../\\Resource\\Sprite\\" + fileName + L".png";
	Texture* pTexture = new Texture(strPath.c_str());
	
	

	mapTexture.insert(make_pair(fileName, pTexture));

	
}

Texture* CSpriteResource::GetTextureInfo(wstring fileName)
{
	
	map<wstring, Texture*>::iterator iter;
	iter = mapTexture.find(fileName);
	return iter->second;
}





void CSpriteResource::Draw(wstring Texture, wstring Sprite,int Frame)
{
	mapTexture[Texture]->Draw(Sprite,Frame);
}

CSpriteResource::CSpriteResource()
{
	
	/*  -- 예제----
	int main()
	{
		TiXmlDocument ReadDoc;
		ReadDoc.LoadFile("Test.xml");// xml 파일 로드
			//"DB"라는 노드를 찾는다
		TiXmlElement* ReadRoot = ReadDoc.FirstChildElement("DB");
		//ReadRoot("DB")노드 하위의 "class1",의 하위 "Teacher"라는 노드를 찾는다.
		TiXmlElement* sub = ReadRoot->FirstChildElement("class1")->FirstChildElement("Teacher");
		TiXmlHandle handle(0);// 노드를 다루기 위한 핸들
		handle = TiXmlHandle(sub);
		//ReadRoot->Value() ReadRoot의 노드 명을 반환한다 "DB"
		std::cout << ReadRoot->Value() << std::endl;
		//핸들에 저장된 노드 하위에 존재하는 노드를 찾는다. 그 노드명을 반환한다.
		TiXmlElement* tmp = handle.FirstChildElement().Element();
		std::cout << tmp->Value() << std::endl;

		sub = ReadRoot->FirstChildElement("class1")->FirstChildElement("English");
		//sub(class1->english의 속성을 읽어온다.
		TiXmlAttribute *pAttrib;
		pAttrib = sub->FirstAttribute();
		while (pAttrib)
		{
			std::cout << pAttrib->Name() << "  " << pAttrib->Value() << std::endl;
			pAttrib = pAttrib->Next();
		}
	}
	*/
	
		//스크립트로 'Texture'생성 및 추가 AddImageFile();
		//스크립트로 'Texture' 내부 Sprite추가
		

	


	TiXmlDocument XmlFile;
	XmlFile.LoadFile("TextureList.xml");
		
	TiXmlElement* XmlRoot = XmlFile.FirstChildElement("TextureList");
	
	TiXmlElement* XmlTexture = XmlRoot->FirstChildElement("Texture")->FirstChildElement("Name");

	TiXmlHandle handle(0);// 노드를 다루기 위한 핸들
	handle = TiXmlHandle(XmlTexture);
	TiXmlElement* element = handle.Element();
	string a = element->GetText();


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
	map<wstring, Texture*>::iterator iter = mapTexture.begin();

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
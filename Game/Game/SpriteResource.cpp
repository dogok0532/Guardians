
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
	
	/*  -- ����----
	int main()
	{
		TiXmlDocument ReadDoc;
		ReadDoc.LoadFile("Test.xml");// xml ���� �ε�
			//"DB"��� ��带 ã�´�
		TiXmlElement* ReadRoot = ReadDoc.FirstChildElement("DB");
		//ReadRoot("DB")��� ������ "class1",�� ���� "Teacher"��� ��带 ã�´�.
		TiXmlElement* sub = ReadRoot->FirstChildElement("class1")->FirstChildElement("Teacher");
		TiXmlHandle handle(0);// ��带 �ٷ�� ���� �ڵ�
		handle = TiXmlHandle(sub);
		//ReadRoot->Value() ReadRoot�� ��� ���� ��ȯ�Ѵ� "DB"
		std::cout << ReadRoot->Value() << std::endl;
		//�ڵ鿡 ����� ��� ������ �����ϴ� ��带 ã�´�. �� ������ ��ȯ�Ѵ�.
		TiXmlElement* tmp = handle.FirstChildElement().Element();
		std::cout << tmp->Value() << std::endl;

		sub = ReadRoot->FirstChildElement("class1")->FirstChildElement("English");
		//sub(class1->english�� �Ӽ��� �о�´�.
		TiXmlAttribute *pAttrib;
		pAttrib = sub->FirstAttribute();
		while (pAttrib)
		{
			std::cout << pAttrib->Name() << "  " << pAttrib->Value() << std::endl;
			pAttrib = pAttrib->Next();
		}
	}
	*/
	
		//��ũ��Ʈ�� 'Texture'���� �� �߰� AddImageFile();
		//��ũ��Ʈ�� 'Texture' ���� Sprite�߰�
		

	


	TiXmlDocument XmlFile;
	XmlFile.LoadFile("TextureList.xml");
		
	TiXmlElement* XmlRoot = XmlFile.FirstChildElement("TextureList");
	
	TiXmlElement* XmlTexture = XmlRoot->FirstChildElement("Texture")->FirstChildElement("Name");

	TiXmlHandle handle(0);// ��带 �ٷ�� ���� �ڵ�
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
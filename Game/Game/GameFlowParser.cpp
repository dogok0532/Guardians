#include "GameFlowParser.h"


#include "EnemyFighter.h"
#include "PowerUp.h"


CEnemy* CGameFlowParser::GetEnemy()
{
	string strType = XmlEnemy->FirstChildElement("Type")->GetText();
	int Time = atoi (XmlEnemy->FirstChildElement("Time")->GetText());
	int X = atoi(XmlEnemy->FirstChildElement("Coordinate")->FirstChildElement("X")->GetText());
	int Y = atoi(XmlEnemy->FirstChildElement("Coordinate")->FirstChildElement("Y")->GetText());
	int RenderDirection = atoi(XmlEnemy->FirstChildElement("RenderDirection")->GetText());


	int Speed = 0;
	int MoveDirection = 0;

	bool MoveByBackground = atoi(XmlEnemy->FirstChildElement("MoveByBackground")->GetText());
	if (!MoveByBackground)
	{
		MoveDirection = atoi(XmlEnemy->FirstChildElement("MoveDirection")->GetText());
		Speed = atoi(XmlEnemy->FirstChildElement("Speed")->GetText());
	}
	

	int Pattern = atoi(XmlEnemy->FirstChildElement("Pattern")->GetText());
	

	

	CEnemy* pEnemy= NULL;

	if (strType == "Fighter")
	{
		pEnemy = new CEnemyFighter;
	}

	if(pEnemy)
		pEnemy->SetSpawnInformation(X, Y, Time, RenderDirection,MoveDirection, Pattern, Speed, MoveByBackground);

	XmlEnemy =XmlEnemy->NextSiblingElement("Enemy");

	return pEnemy;
}

CItem* CGameFlowParser::GetItem()
{

	string strType = XmlItem->FirstChildElement("Type")->GetText();
	int Time = atoi(XmlItem->FirstChildElement("Time")->GetText());
	int X = atoi(XmlItem->FirstChildElement("Coordinate")->FirstChildElement("X")->GetText());
	int Y = atoi(XmlItem->FirstChildElement("Coordinate")->FirstChildElement("Y")->GetText());
	int RenderDirection = atoi(XmlItem->FirstChildElement("RenderDirection")->GetText());

	bool MoveByBackground = atoi(XmlItem->FirstChildElement("MoveByBackground")->GetText());
	
	int Speed = 0;
	int MoveDirection = 0;
	if (!MoveByBackground)
	{
		MoveDirection = atoi(XmlItem->FirstChildElement("MoveDirection")->GetText());
		Speed = atoi(XmlItem->FirstChildElement("Speed")->GetText());
	}
	

	int Pattern = atoi(XmlItem->FirstChildElement("Pattern")->GetText());

	CItem* pItem = NULL;

	if (strType == "PowerUp")
	{
		pItem = new CPowerUp;
	}

	if (pItem)
		pItem->SetSpawnInformation(X, Y, Time,RenderDirection, MoveDirection, Pattern, Speed, MoveByBackground);

	XmlItem = XmlItem->NextSiblingElement("Item");

	return pItem;

}



bool CGameFlowParser::EnemyParseEnd()
{
	return !XmlEnemy;
}

bool CGameFlowParser::ItemParseEnd()
{
	return !XmlItem;
}

CGameFlowParser::CGameFlowParser()
{

	XmlFile.LoadFile("..\\script\\Stage1.xml");
	XmlRoot = XmlFile.FirstChildElement("List");
	XmlEnemy = XmlRoot->FirstChildElement("Enemy");
	XmlItem = XmlRoot->FirstChildElement("Item");


}


CGameFlowParser::~CGameFlowParser()
{
}

#pragma once
#include "tinyxml.h"
using namespace std;


class CGameObject;
class CEnemy;
class CItem;
class CGameFlowParser
{
	TiXmlDocument XmlFile;
	TiXmlElement* XmlRoot = NULL;

	TiXmlElement* XmlEnemy=NULL;
	TiXmlElement* XmlItem = NULL;

	

public:
	CEnemy* GetEnemy();
	CItem* GetItem();
	bool EnemyParseEnd();
	bool ItemParseEnd();

	

public:
	CGameFlowParser();
	~CGameFlowParser();
};


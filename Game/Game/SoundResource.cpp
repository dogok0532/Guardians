
#include "SoundResource.h"
#include "tinyxml.h"



void CSoundResource::Init()
{
	m_pEngine = createIrrKlangDevice();

	//TiXmlDocument xmlDoc;
	//xmlDoc.LoadFile("~~~~");;	//xml���� �ε�


	
	m_pEngine->addSoundSourceFromFile("../Resource/Sound/233.mp3");
	m_pEngine->addSoundSourceFromFile("../Resource/Sound/901.mp3");
	m_pEngine->addSoundSourceAlias(,)
	auto sound =m_pEngine->getSoundSource("../Resource/Sound/901.mp3");
	m_pEngine->play2D(sound);
}


CSoundResource::CSoundResource()
{

}

CSoundResource::~CSoundResource()
{

}
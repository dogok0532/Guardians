
#include "SoundResource.h"
#include "tinyxml.h"



void CSoundResource::AddSound()
{
	TiXmlDocument xmlDoc;
	xmlDoc.LoadFile("../Script/SoundList.xml");

	TiXmlElement* xmlRoot = xmlDoc.FirstChildElement("SoundList");
	string route = xmlRoot->FirstChildElement("Route")->GetText();
	
	TiXmlElement* xmlSound = xmlRoot->FirstChildElement("Sound");
	while (xmlSound)
	{
		string name= xmlSound->FirstChildElement("Name")->GetText();
		string format= xmlSound ->FirstChildElement("Format")->GetText();
		

		if ( strcmp( xmlSound->FirstChildElement("Type")->GetText(), "Effect") == 0)
		{
			auto sound = m_pEffectSoundEngine->addSoundSourceFromFile((route + name +'.'+ format).c_str());
			m_pEffectSoundEngine->addSoundSourceAlias(sound, name.c_str());
		}

		else if (strcmp(xmlSound->FirstChildElement("Type")->GetText(), "Music") == 0)
		{
			auto sound = m_pEffectSoundEngine->addSoundSourceFromFile((route + name + '.' + format).c_str());
			m_pMusicSoundEngine->addSoundSourceAlias(sound, name.c_str());
		}


		xmlSound = xmlSound->NextSiblingElement("Sound");
	}

	xmlDoc.Clear();
	
}

void CSoundResource::PlayMusic(wstring wFileName)
{
	

	string fileName;
	fileName.append(wFileName.begin(), wFileName.end());

	if (m_strCurrentMusic == wFileName)
	{
		return;
	}
	else
	{
		if (m_pCurrentMusic)
		{
			m_pCurrentMusic->stop();
			
		}
		m_pCurrentMusic = m_pMusicSoundEngine->play2D(fileName.c_str(), true, false, true);
		m_strCurrentMusic = wFileName;
	}
	
}

void CSoundResource::PlayEffect(wstring wFileName)
{
	string fileName;
	fileName.append(wFileName.begin(), wFileName.end());

  	ISound* pSound = m_pEffectSoundEngine->play2D(fileName.c_str(),false,false,true);
}

void CSoundResource::Init()
{
	m_pEffectSoundEngine = createIrrKlangDevice();
	m_pMusicSoundEngine = createIrrKlangDevice();
	//TiXmlDocument xmlDoc;
	//xmlDoc.LoadFile("~~~~");;	//xml파일 로드
	
	AddSound();



	
}


CSoundResource::CSoundResource()
{
	
}

CSoundResource::~CSoundResource()
{
	//m_pEffectSoundEngine->drop();

}
#pragma once


#pragma comment(lib,"dsound.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")


#include "Defines.h"
#include <windows.h>
#include <mmsystem.h>
#include <dsound.h>
#include <iostream>

#include <map>

#include <irrKlang.h>


using namespace irrklang;
using namespace std;


#pragma comment(lib,"irrKlang.lib")

class CSoundResource
{

private:
	ISoundEngine* m_pEffectSoundEngine;
	ISoundEngine* m_pMusicSoundEngine;

private:
	ISound* m_pCurrentMusic=nullptr;
	wstring m_strCurrentMusic;


public:
	void PlayMusic(wstring wFileName);
	void StopMusic();

	void PlayEffect(wstring wFileName);
	


	


public:

	void Init();
	void AddSound();

public:
	CSoundResource();
	~CSoundResource();

};

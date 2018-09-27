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
public:
	CSoundResource();
	~CSoundResource();

private:
	ISoundEngine* m_pEngine;

public:
	void Init();
	void Play(wstring fileName);

};

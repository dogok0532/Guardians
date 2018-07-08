#pragma once


#pragma comment(lib,"dsound.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")


#include "Defines.h"
#include <windows.h>
#include <mmsystem.h>
#include <dsound.h>
#include <stdio.h>

#include <map>
using namespace std;



class CSoundResource
{
	DECLARE_SINGLETON(CSoundResource)

private:
	IDirectSound8 * m_pDirectSound=NULL;
	IDirectSoundBuffer* m_pMainBuffer=NULL;
	map<wstring,IDirectSoundBuffer8*> m_mapSubBuffer;

public:
	bool Init(HWND hWnd, wstring fileName);
	void Release();
	bool InsertFile(wstring fileName);

	void PlayBuffer(wstring fileName);

private:
	bool InitSoundEngine(HWND);
	
};

struct sOGGFormat
{
	__int32 CapturePattern; //4πŸ¿Ã∆Æ
	__int8 Version;
	__int8 HeaderType;
	__int64 GranulePosition;
	__int32 BitstreamSerialNum;
	__int32 PageSequenceNum;
	__int32 CheckSum;
	__int8 PageSegments;

};
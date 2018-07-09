
#include "SoundResource.h"


IMPLEMENT_SINGLETON(CSoundResource)

void CSoundResource::Init()
{
	m_pEngine = createIrrKlangDevice();

	
}

void CSoundResource::Play(wstring fileName)
{
	char cFileName[STR_MAX];
	wcstombs_s(NULL, cFileName, sizeof(cFileName), fileName.c_str(), STR_MAX);

	m_pEngine->play2D(cFileName,true,false,false, ESM_AUTO_DETECT,true);
}

CSoundResource::CSoundResource()
{

}

CSoundResource::~CSoundResource()
{

}

#include "SoundResource.h"




void CSoundResource::Init()
{
	m_pEngine = createIrrKlangDevice();

	
}

void CSoundResource::Play(wstring fileName)
{
	char cFileName[STR_DEFAULT];
	wcstombs_s(NULL, cFileName, sizeof(cFileName), fileName.c_str(), STR_DEFAULT);

	m_pEngine->play2D(cFileName,true,false,false, ESM_AUTO_DETECT,true);
}

CSoundResource::CSoundResource()
{

}

CSoundResource::~CSoundResource()
{

}
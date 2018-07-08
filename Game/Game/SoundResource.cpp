
#include "SoundResource.h"


IMPLEMENT_SINGLETON(CSoundResource)


CSoundResource::CSoundResource()
{
	
}


CSoundResource::~CSoundResource()
{

}

bool CSoundResource::Init(HWND hWnd,wstring fileName)
{
	bool Result = InitSoundEngine(hWnd);

	if (Result == false)
		return false;

	Result = InsertFile(fileName);

	if (Result == false)
		return false;


	return true;
}

void CSoundResource::Release()
{
	SAFE_RELEASE(m_pDirectSound);
	SAFE_RELEASE(m_pMainBuffer);

	//SAFE_DELETE( m_pDirectSound);
	//SAFE_DELETE (m_pMainBuffer);


	map<wstring, IDirectSoundBuffer8*>::iterator iter=m_mapSubBuffer.begin();

	for (;iter!=m_mapSubBuffer.end();iter++)
	{
		IDirectSoundBuffer8* Buffer = iter->second;
		SAFE_DELETE(Buffer)

		m_mapSubBuffer.clear();
	}

	

	
}

bool CSoundResource::InsertFile(wstring fileName)
{
	errno_t err;
	FILE* pFile;
	size_t count;
	sOGGFormat fileFormat;

	count = fileName.length();

	fileName =fileName +  L"../\\Sound";
	char cFileName[256];

	wcstombs_s(NULL, cFileName,sizeof(cFileName),fileName.c_str(),256);

	return true;
}


void CSoundResource::PlayBuffer(wstring fileName)
{

}

bool CSoundResource::InitSoundEngine(HWND hWnd)	// DirectSound8을 윈도우 핸들값에 연동
{
	HRESULT hr = DirectSoundCreate8(NULL, &m_pDirectSound, NULL);


	if (FAILED(hr))
		return false;

	hr = m_pDirectSound->SetCooperativeLevel(hWnd, DSSCL_NORMAL);

	if (FAILED(hr))
		return false;


	DSBUFFERDESC bufferDesc;
	WAVEFORMATEX waveFormat;


	bufferDesc.dwSize = sizeof(DSBUFFERDESC);
	bufferDesc.dwFlags = DSBCAPS_CTRLVOLUME | DSBCAPS_GLOBALFOCUS | DSBCAPS_PRIMARYBUFFER; //소리조정 가능 + 다른앱이 실행될때도 재생
	bufferDesc.dwBufferBytes = 0; /*Size of the new buffer, 
	in bytes. This value must be 0 when creating primary buffers.
	For secondary buffers, the minimum and maximum sizes 
	allowed are specified by DSBSIZE_MIN and DSBSIZE_MAX,
	defined in Dsound.h.
	메인버퍼일경우 0, 서브버퍼일경우 DSound.h에 정의된 DSBSIZE_MIN 과 DSBSIZE_MAX 를 이용하라?*/
	bufferDesc.dwReserved = 0;	//This value is reserved. Do not use.
	bufferDesc.lpwfxFormat = NULL;	//Address of a structure specifying the waveform format for the buffer. 메인버퍼는 NULL
	bufferDesc.guid3DAlgorithm = DS3DALG_DEFAULT;

	hr = m_pDirectSound->CreateSoundBuffer(&bufferDesc, &m_pMainBuffer, NULL); //Must be NULL

	if (FAILED(hr))
		return false;
	
	waveFormat.wFormatTag = WAVE_FORMAT_PCM;
	waveFormat.nSamplesPerSec = 44100;
	waveFormat.wBitsPerSample = 16;
	waveFormat.nChannels = 2;
	waveFormat.nBlockAlign = (waveFormat.wBitsPerSample / 8) * waveFormat.nChannels;
	waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;
	waveFormat.cbSize = 0;


	hr = m_pMainBuffer->SetFormat(&waveFormat);

	if (FAILED(hr))
		return false;

	
	


	return true;
}

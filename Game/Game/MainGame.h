#pragma once
#include <iostream>
#include <vector>
#include "Defines.h"
#include <queue>

using namespace std;


class CText;
class CScene;
class CGameObject;

class CSoundResource;
class CSpriteResource;

class CMessage;

class CMainGame
{


private:
	CScene * m_pCurrentScene = NULL;




private: //통합관리 모음

	CSoundResource* pSoundResource;	//사운드 리소스 모음
	CSpriteResource* pSpriteResource;	//이미지 리소스 모음
public:
	
	CSoundResource*  GetSound() { return pSoundResource; }	
	CSpriteResource*  GetSpriteResource() { return pSpriteResource;}

public:
	void ChangeScene(int Scene);	// Scene바꾸기

	void Init();			//게임 실행시 필요한 요소들 실행
	void Update(float deltaTime);	//	Update루프
	void Render();					//	Render루프
	void ResetSprite();				// 스프라이트 리소스 해제


	void CreateObject(CGameObject* pGameObject);

	DECLARE_SINGLETON(CMainGame)		//싱글톤 선인
};

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

private:
	queue<CMessage*> msgQue;
public:
	void UpdateMessage(CMessage* msg);
	void ProcessMessage();




private: //���հ��� ����

	CSoundResource* pSoundResource;
	CSpriteResource* pSpriteResource;
public:
	
	CSoundResource*  GetSound() { return pSoundResource; }
	CSpriteResource*  GetSpriteResource() { return pSpriteResource;}

public:
	void ChangeScene(int Scene);

	void Init();
	void Update(float deltaTime);
	void Render();
	void ResetSprite();

	DECLARE_SINGLETON(CMainGame)
};

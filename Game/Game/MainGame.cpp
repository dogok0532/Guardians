
#include "MainGame.h"

#include "Player.h"
#include "Defines.h"
#include "GameInfo.h"
#include "TextManager.h"
#include "CPlayerBullet.h"
#include "SoundResource.h"

void CMainGame::Update(float deltaTime)
{
	m_pPlayer[0]->Update(deltaTime);		//�÷��̾� ������Ʈ



	for (list<CGameObject*>::iterator iter = m_pPlayerBulletList.begin();
		iter != m_pPlayerBulletList.end(); iter++)
	{
		(*iter)->Update(deltaTime);
	}

	PlayerFire(deltaTime);

	
	
}

void CMainGame::Render()
{
	m_pPlayer[0]->Render();

	


	for (list<CGameObject*>::iterator iter = m_pPlayerBulletList.begin();
		iter != m_pPlayerBulletList.end(); iter++)
	{
		(*iter)->Render();
	}

	for (list<CGameObject*>::iterator iter = m_pUIList.begin();
		iter != m_pUIList.end(); iter++)
	{
		(*iter)->Render();
	}

	
}



void CMainGame::PlayerFire(float deltaTime)
{
	if ((dynamic_cast<CPlayer*>(m_pPlayer[0]))->Fire(deltaTime) == true)	//�߻簡������ Ȯ��
	{
		CPlayerBullet* pPlayerBullet = new CPlayerBullet;		//�÷��̾� Bullet����Ʈ�� ����
		pPlayerBullet->SetPos(m_pPlayer[0]->GetPos());			//Bullet ��ǥ ����
		m_pPlayerBulletList.push_back(pPlayerBullet);			//�÷��̾� Bullet����Ʈ�� ����
	}

	
}

CMainGame::CMainGame()
{
	m_pPlayer[0] = new CPlayer;

	
	CGameObject* UI = new CGameInfo;
	
	m_pUIList.push_back(UI);

	CSoundResource::GetInstance()->Init();
	CSoundResource::GetInstance()->Play(L"../bell.wav");
}


CMainGame::~CMainGame()
{
	SAFE_DELETE(m_pPlayer[0]);
	SAFE_DELETE(m_pPlayer[1]);


	for (list<CGameObject*>::iterator iter = m_pEnemyList.begin();
		iter != m_pEnemyList.end(); iter++)
	{
		SAFE_DELETE(*iter);
	}

	for (list<CGameObject*>::iterator iter = m_pPlayerBulletList.begin();
		iter != m_pPlayerBulletList.end(); iter++)
	{
		SAFE_DELETE(*iter);
	}

	for (list<CGameObject*>::iterator iter = m_pEnmeyBulletList.begin();
		iter != m_pEnmeyBulletList.end(); iter++)
	{
		SAFE_DELETE(*iter);
	}
}

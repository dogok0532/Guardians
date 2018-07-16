
#include "Stage.h"

#include "Player.h"
#include "Defines.h"
#include "GameInfo.h"
#include "TextManager.h"
#include "CPlayerBullet.h"
#include "SoundResource.h"
#include "UserFunction.h"
#include "Enemy.h"

void CStage::DestroyCheck()
{
	

	//-------------플레이어와 적탄 체크 ------------------------------------
	for (list<CGameObject*>::iterator iter_Bullet = m_pPlayerBulletList.begin();
		iter_Bullet != m_pPlayerBulletList.end();)
	{
		bool bAdded=false;

		for (list<CGameObject*>::iterator iter_Enemy = m_pEnemyList.begin();
			iter_Enemy != m_pEnemyList.end(); )

		{
			if ( CheckHit(&((*iter_Bullet)->GetRect()), &((*iter_Enemy)->GetRect())) )
			{
  				delete (*iter_Enemy);
				m_pEnemyList.erase(iter_Enemy++);

				delete(*iter_Bullet);
				m_pPlayerBulletList.erase(iter_Bullet++);
				bAdded = true;
			}
			else
				iter_Enemy++;
		}
		if (bAdded == false)
			iter_Bullet++;
		else
			bAdded = false;
	}
	//------------------------------------------------------------------------------

	//---------적과 플레이어 탄 체크----------------------------------------------
	for (list<CGameObject*>::iterator iter_Bullet = m_pEnmeyBulletList.begin();
		iter_Bullet != m_pEnmeyBulletList.end();)
	{
		if (CheckHit( &((*iter_Bullet)->GetRect()),& (m_pPlayer[0]->GetRect())))
		{
			//GameOver
		}
	}
	//---------------------------------------------------------------------
}

void CStage::Update(float deltaTime)
{
	m_pPlayer[0]->Update(deltaTime);		//플레이어 업데이트
	PlayerFire(deltaTime);

	
	for (list<CGameObject*>::iterator iter = m_pPlayerBulletList.begin();		//플레이어 탄막 업데이트
		iter != m_pPlayerBulletList.end();)
	{
		if ((*iter)->Destroy() == true)
		{
			delete (*iter);
			m_pPlayerBulletList.erase(iter++);
		}
		else
		{
			(*iter)->Update(deltaTime);
			iter++;
		}
	}


	for (vector<CGameObject*>::iterator iter = m_pVecUI.begin();				//UI 업데이트
		iter != m_pVecUI.end(); iter++)
	{
		(*iter)->Update(deltaTime);
	}

	for (list<CGameObject*>::iterator iter = m_pEnemyList.begin();		//적 업데이트
		iter != m_pEnemyList.end();)
	{
		if ((*iter)->Destroy() == true)
		{
			delete (*iter);
			m_pEnemyList.erase(iter++);
		}
		else
			(*iter)->Update(deltaTime);
		iter++;
	}


	

	
	DestroyCheck();
	
	

	fTimePassed += deltaTime;
}

void CStage::Render()
{
	m_pPlayer[0]->Render();

	


	for (list<CGameObject*>::iterator iter = m_pPlayerBulletList.begin();
		iter != m_pPlayerBulletList.end(); iter++)
	{
		(*iter)->Render();
	}

	for (vector<CGameObject*>::iterator iter = m_pVecUI.begin();
		iter != m_pVecUI.end(); iter++)
	{
		(*iter)->Render();
	}

	for (list<CGameObject*>::iterator iter = m_pEnemyList.begin();
		iter != m_pEnemyList.end(); iter++)
	{
		(*iter)->Render();
	}

	
}



bool CStage::Destroy()
{
	return false;
}

void CStage::PlayerFire(float deltaTime)
{
	if ((dynamic_cast<CPlayer*>(m_pPlayer[0]))->Fire(deltaTime) == true)	//발사가능한지 확인
	{
		CGameObject* pPlayerBullet = new CPlayerBullet;		//플레이어 Bullet리스트에 삽입
		pPlayerBullet->SetPos(m_pPlayer[0]->GetPos());			//Bullet 좌표 설정
		m_pPlayerBulletList.push_back(pPlayerBullet);			//플레이어 Bullet리스트에 삽입
	}

	
}

CStage::CStage()
{
	

	
	CGameObject* UI = new CGameInfo;
	m_pVecUI.push_back(UI);

	m_pPlayer[0] = new CPlayer;



	
	CGameObject* Enemy = new CEnemy;
	Enemy->SetPos(rand()%GAMESIZE_X  + (WINCX - GAMESIZE_X)/2,0);
	m_pEnemyList.push_back(Enemy);



	CSoundResource::GetInstance()->Init();


	//CSoundResource::GetInstance()->Play(L"../bell.wav");
}


CStage::~CStage()
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

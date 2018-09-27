
#include "Stage.h"

#include "Player.h"
#include "Defines.h"
#include "GameInfo.h"
#include "Text.h"
#include "PlayerBullet.h"
#include "SoundResource.h"
#include "UserFunction.h"
#include "Enemy.h"
#include "direct.h"
#include "GameFlowParser.h"
#include "EnemyFighter.h"

void CStage::DestroyCheck()
{
	

	//-------------플레이어와 적탄 체크 ------------------------------------
	for (list<CGameObject*>::iterator iter_Bullet = m_pPlayerBulletList.begin();
		iter_Bullet != m_pPlayerBulletList.end();)
	{
		bool bAdded=false;

		for (list<CEnemy*>::iterator iter_Enemy = m_pEnemyList.begin();
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
	for (list<CGameObject*>::iterator iter_Bullet = m_pEnemeyBulletList.begin();
		iter_Bullet != m_pEnemeyBulletList.end();)
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
		if ((*iter)->isOutOfScreen() == true)
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

	for (list<CEnemy*>::iterator iter = m_pEnemyList.begin();		//적 업데이트
		iter != m_pEnemyList.end();)
	{
		if ((*iter)->isOutOfScreen() == true)
		{
			delete (*iter);
			m_pEnemyList.erase(iter++);
			continue;
		}
		else
			(*iter)->Update(deltaTime);
		iter++;
	}

	for (list<CGameObject*>::iterator iter = m_pEnemeyBulletList.begin();		//적 탄막 업데이트
		iter != m_pEnemeyBulletList.end();)
	{
		if ((*iter)->isOutOfScreen() == true)
		{
			delete (*iter);
			m_pEnemeyBulletList.erase(iter++);
			continue;
		}
		else
			(*iter)->Update(deltaTime);
		iter++;
	}


	

	
	DestroyCheck();
	
	

	fTimePassed += deltaTime;

	if (!m_pEnemySpawnQueue.empty() &&m_pEnemySpawnQueue.front()->Spawn(fTimePassed))  /*Stage파싱에 따라 몬스터 생성 시간*/
	{
		m_pEnemyList.push_back(m_pEnemySpawnQueue.front());
		m_pEnemySpawnQueue.pop();
	}
}

void CStage::Render()
{
	
	

	RenderIngame();

	RenderBlackBox();
	
	for (vector<CGameObject*>::iterator iter = m_pVecUI.begin();
		iter != m_pVecUI.end(); iter++)
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
	if (int BulletState =(dynamic_cast<CPlayer*>(m_pPlayer[0]))->Fire(deltaTime))	//발사가능한지 확인
	{
		for (int i = 0; i < BulletState; i++)						//탄약상태(파워업)에 따라 한번에 단발/여러발을 쏨
		{
			CGameObject* pPlayerBullet = 
			(dynamic_cast<CPlayer*>(m_pPlayer[0]))->MakeBullet(
				-15 + i * 30.f / (BulletState - 1)
			);		
			m_pPlayerBulletList.push_back(pPlayerBullet);		
		}
		
	}

	
}

void CStage::EnemyFire(float deltaTime)
{

}

void CStage::RenderIngame()
{
	m_pPlayer[0]->SetAdjustIngame();
	m_pPlayer[0]->Render();
	m_pPlayer[0]->ResetAdjustIngame();


	for (list<CEnemy*>::iterator iter = m_pEnemyList.begin();
		iter != m_pEnemyList.end(); iter++)
	{
		(*iter)->SetAdjustIngame();
		(*iter)->Render();
		(*iter)->ResetAdjustIngame();
	}
	for (list<CGameObject*>::iterator iter = m_pPlayerBulletList.begin();
		iter != m_pPlayerBulletList.end(); iter++)
	{
		(*iter)->SetAdjustIngame();
		(*iter)->Render();
		(*iter)->ResetAdjustIngame();
	}

}

void CStage::RenderBlackBox()
{

	RECT rc = { 0,0, WINCX / 2 - GAMESIZE_X / 2 ,WINCY + 200 };
	CDirect::GetInstance()->DrawRectangle(rc);

	rc = { WINCX / 2 + GAMESIZE_X / 2,0,WINCX,WINCY + 200 };
	CDirect::GetInstance()->DrawRectangle(rc);

}

CStage::CStage()
{
	

	
	CGameObject* UI = new CGameInfo;
	m_pVecUI.push_back(UI);

	m_pPlayer[0] = new CPlayer;




	CEnemy* Enemy = new CEnemyFighter;
	Enemy->SetPos(rand() % GAMESIZE_X + (WINCX - GAMESIZE_X) / 2, 0);
	m_pEnemyList.push_back(Enemy);

	
	
	CGameFlowParser Parser;
	while (!Parser.EnemyParseEnd())
	{
		CEnemy* pEnemy = Parser.GetEnemy();
		if(pEnemy)
			m_pEnemySpawnQueue.push(pEnemy);
	}

	while (!Parser.ItemParseEnd())
	{
		CItem* pItem = Parser.GetItem();
			if (pItem)
		m_pItemSpawnQueue.push(pItem);
	}


	//CSoundResource::GetInstance()->Play(L"../bell.wav");
}


CStage::~CStage()
{
	SAFE_DELETE(m_pPlayer[0]);
	SAFE_DELETE(m_pPlayer[1]);


	for (list<CEnemy*>::iterator iter = m_pEnemyList.begin();
		iter != m_pEnemyList.end(); iter++)
	{
		SAFE_DELETE(*iter);
	}

	for (list<CGameObject*>::iterator iter = m_pPlayerBulletList.begin();
		iter != m_pPlayerBulletList.end(); iter++)
	{
		SAFE_DELETE(*iter);
	}

	for (list<CGameObject*>::iterator iter = m_pEnemeyBulletList.begin();
		iter != m_pEnemeyBulletList.end(); iter++)
	{
		SAFE_DELETE(*iter);
	}
}

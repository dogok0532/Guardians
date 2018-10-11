#pragma once
#include "DirectHeader.h"
#include "GameObject.h"

void SafeDelete(void** ptr)
{
	if(*ptr != nullptr)
		delete *ptr;

	*ptr = nullptr;
}



bool CheckHit(D3DXVECTOR3* vecSrcPos, D3DXVECTOR3* vecScrSize, D3DXVECTOR3* vecDesPos, D3DXVECTOR3* vecDesSize)	// 위치벡터, 크기벡터로 계산
{
	RECT rc, rcScr, rcDes;
	
	rcScr = {
		(LONG)(vecSrcPos->x) - (LONG)(vecScrSize->x / 2) ,
		(LONG)(vecSrcPos->y) - (LONG)(vecScrSize->y / 2) ,
		(LONG)(vecSrcPos->x) + (LONG)(vecScrSize->x / 2) ,
		(LONG)(vecSrcPos->y) + (LONG)(vecScrSize->y / 2) };

	rcDes = { 
		(LONG)(vecDesPos->x) - (LONG)(vecDesSize->x / 2) ,
		(LONG)(vecDesPos->y) - (LONG)(vecDesSize->y / 2) ,
		(LONG)(vecDesPos->x) + (LONG)(vecDesSize->x / 2) ,
		(LONG)(vecDesPos->y) + (LONG)(vecDesSize->y / 2) }; 

	//사각형 계산해서 추가
	
	return IntersectRect(&rc, &rcScr, &rcDes);

	
}


bool CheckHit(RECT* rcSrc,RECT* rcDes)
{
	RECT rc;

	//사각형 계산해서 추가

	return IntersectRect(&rc, rcSrc, rcDes);


}


bool CheckGameObjectCollision(CGameObject* pGameObjSrc, CGameObject* pGameObjDes)
{
	if (1 )	// 실체가 없는 Object일경우 반환
	{
		return 0;
	}
	
	if (1)//Circle&& Circle
	{
		if (1)	//충돌할경우
		{
			return 1;
		}
		else    //충돌하지 않을경우
		{

		}
			return 0;
	}
	


}

void CollisionAdjust(CGameObject* pGameObjSrc, CGameObject* pGameObjDes)
//움직이는 물체     , 고정물체
{
	if (CheckGameObjectCollision(pGameObjSrc, pGameObjDes) == 1)	//실체가 있는 객체끼리 부딛칠때
	{
		
	}
}
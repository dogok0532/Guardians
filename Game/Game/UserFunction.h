#pragma once
#include "DirectHeader.h"

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



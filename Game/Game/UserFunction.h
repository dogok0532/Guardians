#pragma once
#include "DirectHeader.h"
#include "GameObject.h"

void SafeDelete(void** ptr)
{
	if(*ptr != nullptr)
		delete *ptr;

	*ptr = nullptr;
}



bool CheckHit(D3DXVECTOR3* vecSrcPos, D3DXVECTOR3* vecScrSize, D3DXVECTOR3* vecDesPos, D3DXVECTOR3* vecDesSize)	// ��ġ����, ũ�⺤�ͷ� ���
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

	//�簢�� ����ؼ� �߰�
	
	return IntersectRect(&rc, &rcScr, &rcDes);

	
}


bool CheckHit(RECT* rcSrc,RECT* rcDes)
{
	RECT rc;

	//�簢�� ����ؼ� �߰�

	return IntersectRect(&rc, rcSrc, rcDes);


}


bool CheckGameObjectCollision(CGameObject* pGameObjSrc, CGameObject* pGameObjDes)
{
	if (1 )	// ��ü�� ���� Object�ϰ�� ��ȯ
	{
		return 0;
	}
	
	if (1)//Circle&& Circle
	{
		if (1)	//�浹�Ұ��
		{
			return 1;
		}
		else    //�浹���� �������
		{

		}
			return 0;
	}
	


}

void CollisionAdjust(CGameObject* pGameObjSrc, CGameObject* pGameObjDes)
//�����̴� ��ü     , ������ü
{
	if (CheckGameObjectCollision(pGameObjSrc, pGameObjDes) == 1)	//��ü�� �ִ� ��ü���� �ε�ĥ��
	{
		
	}
}
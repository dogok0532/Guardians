#include "Sprite.h"



const RECT* CSprite::GetRect(int Frame)
{
	RECT rc = { 0,0,0,0 };	//������, ��ǥ���� ���� ����� ���� ����

	return &rc;
}

const D3DXVECTOR3* CSprite::GetCenter()
{
	return &D3DXVECTOR3((float)iXSize / 2, (float)iYSize / 2, 0);
}

CSprite::CSprite()
{
	
}




CSprite::CSprite(wstring body, int XBegin, int YBegin, int isLine, int XFrame, int YFrame, int XSize, int YSize)

{

}

CSprite::~CSprite()
{
}

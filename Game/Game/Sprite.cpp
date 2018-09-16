#include "Sprite.h"



const RECT* CSprite::GetFrameRect(int Frame)
{
	RECT rc ;	//������, ��ǥ���� ���� ����� ���� ����

	int StartX = m_SpriteInfo.iXBegin
		+ (Frame%m_SpriteInfo.iXSize);

	int StartY = m_SpriteInfo.iYBegin
		+ (Frame / m_SpriteInfo.iYSize);

	int EndX = StartX + m_SpriteInfo.iXSize;

	int EndY = StartY + m_SpriteInfo.iYSize;

	rc = { StartX,StartY,EndX,EndY };

	return &rc;
}

const D3DXVECTOR3* CSprite::GetCenter()
{
	return &D3DXVECTOR3((float)m_SpriteInfo.iXSize / 2, (float)m_SpriteInfo.iYSize / 2, 0);
}

void CSprite::SetSpriteInfo(spriteInfo* SpriteInfo)
{
	m_SpriteInfo = *SpriteInfo;
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

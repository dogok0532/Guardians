#include "Sprite.h"



RECT CSprite::GetFrameRect(int Frame)
{
	Frame %= m_SpriteInfo.iFrameCount;


	RECT rc ;	//프레임, 좌표값에 따라 출력할 범위 설정

	int StartX = m_SpriteInfo.iXBegin
		+ (m_SpriteInfo.iXSize+m_SpriteInfo.iIsLine) *(Frame%m_SpriteInfo.iXFrame);

	int StartY = m_SpriteInfo.iYBegin
		+ (m_SpriteInfo.iYSize + m_SpriteInfo.iIsLine)*(Frame/m_SpriteInfo.iXFrame);

	int EndX = StartX + m_SpriteInfo.iXSize;

	int EndY = StartY + m_SpriteInfo.iYSize;

	rc = { StartX,StartY,EndX,EndY };

	return rc;
}

 RECT CSprite::GetSpriteRect()
{
	RECT rc = {m_SpriteInfo.iXBegin, m_SpriteInfo.iYBegin,
	m_SpriteInfo.iXBegin + m_SpriteInfo.iXSize*m_SpriteInfo.iXFrame,
		m_SpriteInfo.iYBegin + m_SpriteInfo.iYSize*m_SpriteInfo.iYFrame };
	return rc;
}

D3DXVECTOR3 CSprite::GetFrameCenter()
{
	return D3DXVECTOR3((LONG)m_SpriteInfo.iXSize / 2.f, (LONG)m_SpriteInfo.iYSize / 2.f, 0);

}

D3DXVECTOR3 CSprite::GetSpriteCenter()
{
	return D3DXVECTOR3((LONG)(m_SpriteInfo.iXSize *m_SpriteInfo.iXFrame / 2.f), (long)(m_SpriteInfo.iYSize *m_SpriteInfo.iYFrame / 2.f), 0);

}

void CSprite::SetSpriteInfo(spriteInfo* SpriteInfo)
{
	m_SpriteInfo = *SpriteInfo;
}

D3DXVECTOR3 CSprite::GetSize()
{
	
	return D3DXVECTOR3(m_SpriteInfo.iXSize,m_SpriteInfo.iYSize,0);
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

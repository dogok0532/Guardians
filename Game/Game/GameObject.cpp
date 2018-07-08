
#include "GameObject.h"
#include "direct.h"
#include "SpriteResource.h"

LPD3DXSPRITE CGameObject::m_pSprite = NULL;

void CGameObject::SetSprite(LPD3DXSPRITE pSprite)
{
	m_pSprite = pSprite;
}


void CGameObject::SetObjectSizeToTextureSize()
{
	D3DSURFACE_DESC desc;
	m_vecImage[0]->GetLevelDesc(0,&desc);


	m_vecSize.x = desc.Height;
	m_vecSize.y = desc.Width;
}

void CGameObject::SetPos(D3DXVECTOR3 vecPos)
{
	m_vecPos = vecPos;
}

void CGameObject::SetPos(float x, float y, float z)
{
	m_vecPos.x = x;
	m_vecPos.y = y;
	m_vecPos.z = z;
}


D3DXVECTOR3 CGameObject::GetPos()
{
	return m_vecPos;
}

CGameObject::CGameObject()
{

	SetSprite(CDirect::GetInstance()->GetSprite());
}


CGameObject::~CGameObject()
{
	for (int i = 0; i < m_vecImage.size(); i++)
	{
		SAFE_RELEASE(m_vecImage[i]);		
	}
	
	m_vecImage.clear();

}

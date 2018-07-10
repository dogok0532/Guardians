
#include "GameObject.h"
#include "direct.h"

LPD3DXSPRITE CGameObject::m_pSprite = NULL;

void CGameObject::SetSprite(LPD3DXSPRITE pSprite)
{
	m_pSprite = pSprite;
}


void CGameObject::SetSizeToTextureSize()	//���ӿ�����Ʈ�� ũ�⸦ �ؽ�ó ũ�⿡ �����.
{
	
	

	m_vecSize.x = m_vecImage[0].ImageInfo.Width;
	m_vecSize.y = m_vecImage[0].ImageInfo.Height;

	

	m_vecCenter = m_vecSize / 2;
	
	
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
		SAFE_RELEASE(m_vecImage[i].pTexture);		
	}
	
	m_vecImage.clear();

}

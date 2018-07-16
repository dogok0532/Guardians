
#include "GameObject.h"
#include "direct.h"







void CGameObject::SetSizeToTextureSize()	//게임오브젝트의 크기를 텍스처 크기에 맞춘다.
{


	m_vecSize = m_vecImage[0]->GetSize();
	
	
}

void CGameObject::SetPos(D3DXVECTOR3 vecPos)
{
	m_vecPos = vecPos;
}

void CGameObject::SetPos(float x, float y,float z)
{
	m_vecPos.x = x;
	m_vecPos.y = y;
	m_vecPos.z = z;
}


D3DXVECTOR3 CGameObject::GetPos()
{
	return m_vecPos;
}

RECT CGameObject::GetRect()
{
	RECT rc = { m_vecPos.x - m_vecSize.x / 2,
		m_vecPos.y - m_vecSize.y / 2,
		m_vecPos.x + m_vecSize.x / 2,
		m_vecPos.y + m_vecSize.y / 2 };

	return rc;
}

void CGameObject::UpdateTextureInfo()
{
	m_vecImage[m_iFrame]->SetPos(m_vecPos);
	m_vecImage[m_iFrame]->SetRenderSize(m_vecSize);
	m_vecImage[m_iFrame]->SetRenderSizeRatio(1, 1, 1);
}

void CGameObject::UpdatePos() //렌더링전 필수 함수(좌표 업데이트)
{
	m_vecImage[m_iFrame]->SetPos(m_vecPos);	
}

CGameObject::CGameObject()
{

	
}


CGameObject::~CGameObject()
{
	
	m_vecImage.clear();

}

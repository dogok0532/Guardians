
#include "GameObject.h"
#include "direct.h"







void CGameObject::SetSizeToTextureSize()	//���ӿ�����Ʈ�� ũ�⸦ �ؽ�ó ũ�⿡ �����.
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

void CGameObject::UpdatePos() //�������� �ʼ� �Լ�(��ǥ ������Ʈ)
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

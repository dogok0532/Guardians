#pragma once
#include "DirectHeader.h"
#include <vector>

using namespace std;

class CGameObject
{
protected:
	D3DXVECTOR3 m_vecPos;	//��ǥ
	D3DXVECTOR3 m_vecDir = {0,0,0};	//����
	D3DXVECTOR3 m_vecSize; //ũ��


	vector<LPDIRECT3DTEXTURE9> m_vecImage;	//�̹�������
	
	
	static LPD3DXSPRITE m_pSprite;				// Device�� ������ SPRITE;

public:
	static void SetSprite(LPD3DXSPRITE pSprite);
	virtual void Update(float deltaTime)=0;
	virtual void Render()=0;

	void SetObjectSizeToTextureSize();	// ��ü�� ũ��(vecSize)�� �ؽ�ó�� ������� ����, ���⼭ m_vecImage[0] �������� �Ѵ�.

	void SetPos(D3DXVECTOR3 vecPos);	//Bullet�� �����ɶ� ��ǥ����
	void SetPos(float x, float y, float z);
	D3DXVECTOR3 GetPos();

public:
	CGameObject();
	virtual ~CGameObject();
};


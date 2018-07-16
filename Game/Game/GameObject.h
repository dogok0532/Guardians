#pragma once
#include "DirectHeader.h"
#include <vector>
#include "SpriteResource.h"

using namespace std;

class CGameObject
{
protected:
	D3DXVECTOR3 m_vecPos;	//��ǥ
	D3DXVECTOR3 m_vecDir = {0,0,0};	//����
	D3DXVECTOR3 m_vecSize; //ũ��
	D3DXVECTOR3 m_vecCenter;

	vector <CTexture*> m_vecImage;	//�̹�������
	
	int m_iFrame = 0;


public:


	virtual void Update(float deltaTime)=0;
	virtual void Render()=0;

	virtual bool Destroy()=0;

	void SetSizeToTextureSize();	// ��ü�� ũ��(vecSize)�� �ؽ�ó�� ������� ����, ���⼭ m_vecImage[0] �������� �Ѵ�.

	void SetPos(D3DXVECTOR3 vecPos);	//Bullet�� �����ɶ� ��ǥ����
	void SetPos(float x, float y, float z=0);
	D3DXVECTOR3 GetPos();

	RECT GetRect();

public:
	void UpdateTextureInfo();		//��� ������ �ؽ�ó�� ������Ʈ. ���� ����Ȥ�� ������ ����ÿ��� 
	void UpdatePos();				//��ǥ�� ������Ʈ.


public:
	CGameObject();
	virtual ~CGameObject();
};


#pragma once
#include "DirectHeader.h"
#include <vector>
#include "SpriteResource.h"
#include <map>
#include "Sprite.h"

using namespace std;

struct ObjectInfo
{
	D3DXVECTOR3 vecPos;	//��ǥ
	D3DXVECTOR3 vecSize; //ũ��
	D3DXVECTOR3 vecRenderRatio = { 1,1,1 };

	float fDirection = 0;
	
};

class CGameObject
{
protected:
	ObjectInfo m_GameInfo;

	

	vector <CTexture*> m_vecImage;	//�̹�������
	

	wstring m_strTextureName;
	wstring m_strSpriteName;
	int m_iFrame = 0;

	void Draw(wstring textureName, wstring spriteName, int iFrame);
	void Draw(wstring textureName, wstring spriteName);

	void DrawWholeTexture(wstring textureName);
public:
	


public:


	virtual void Update(float deltaTime);
	virtual void Render();

	virtual bool Destroy()=0;

	void SetInfoToTexture();	// ��ü�� ũ��(vecSize)�� �ؽ�ó�� ������� ����, ���⼭ m_vecImage[0] �������� �Ѵ�.

	void SetPos(D3DXVECTOR3 vecPos);	//Bullet�� �����ɶ� ��ǥ����
	void SetPos(float x, float y, float z=0);
	D3DXVECTOR3 GetPos();
	

	RECT GetRect();


	void SetAngle(float Angle);


public:
	CGameObject();
	virtual ~CGameObject();
};




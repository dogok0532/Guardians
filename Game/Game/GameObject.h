#pragma once
#include "DirectHeader.h"
#include <vector>

using namespace std;

class CGameObject
{
protected:
	D3DXVECTOR3 m_vecPos;	//좌표
	D3DXVECTOR3 m_vecDir = {0,0,0};	//방향
	D3DXVECTOR3 m_vecSize; //크기


	vector<LPDIRECT3DTEXTURE9> m_vecImage;	//이미지파일
	
	
	static LPD3DXSPRITE m_pSprite;				// Device에 연동된 SPRITE;

public:
	static void SetSprite(LPD3DXSPRITE pSprite);
	virtual void Update(float deltaTime)=0;
	virtual void Render()=0;

	void SetObjectSizeToTextureSize();	// 객체의 크기(vecSize)를 텍스처의 사이즈로 지정, 여기서 m_vecImage[0] 기준으로 한다.

	void SetPos(D3DXVECTOR3 vecPos);	//Bullet이 생성될때 좌표지정
	void SetPos(float x, float y, float z);
	D3DXVECTOR3 GetPos();

public:
	CGameObject();
	virtual ~CGameObject();
};


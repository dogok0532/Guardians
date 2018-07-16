#pragma once
#include "DirectHeader.h"
#include <vector>
#include "SpriteResource.h"

using namespace std;

class CGameObject
{
protected:
	D3DXVECTOR3 m_vecPos;	//좌표
	D3DXVECTOR3 m_vecDir = {0,0,0};	//방향
	D3DXVECTOR3 m_vecSize; //크기
	D3DXVECTOR3 m_vecCenter;

	vector <CTexture*> m_vecImage;	//이미지파일
	
	int m_iFrame = 0;


public:


	virtual void Update(float deltaTime)=0;
	virtual void Render()=0;

	virtual bool Destroy()=0;

	void SetSizeToTextureSize();	// 객체의 크기(vecSize)를 텍스처의 사이즈로 지정, 여기서 m_vecImage[0] 기준으로 한다.

	void SetPos(D3DXVECTOR3 vecPos);	//Bullet이 생성될때 좌표지정
	void SetPos(float x, float y, float z=0);
	D3DXVECTOR3 GetPos();

	RECT GetRect();

public:
	void UpdateTextureInfo();		//모든 정보를 텍스처에 업데이트. 최초 실행혹은 사이즈 변경시에만 
	void UpdatePos();				//좌표만 업데이트.


public:
	CGameObject();
	virtual ~CGameObject();
};


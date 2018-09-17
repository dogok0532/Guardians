#pragma once
#include "DirectHeader.h"
#include <vector>
#include "SpriteResource.h"
#include <map>
#include "Sprite.h"

using namespace std;

struct ObjectInfo
{
	D3DXVECTOR3 vecPos;	//좌표
	D3DXVECTOR3 vecSize; //크기
	D3DXVECTOR3 vecRenderRatio = { 1,1,1 };

	float fDirection = 0;
	
};

class CGameObject
{
protected:
	ObjectInfo m_GameInfo;

	

	vector <CTexture*> m_vecImage;	//이미지파일
	

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

	void SetInfoToTexture();	// 객체의 크기(vecSize)를 텍스처의 사이즈로 지정, 여기서 m_vecImage[0] 기준으로 한다.

	void SetPos(D3DXVECTOR3 vecPos);	//Bullet이 생성될때 좌표지정
	void SetPos(float x, float y, float z=0);
	D3DXVECTOR3 GetPos();
	

	RECT GetRect();


	void SetAngle(float Angle);


public:
	CGameObject();
	virtual ~CGameObject();
};




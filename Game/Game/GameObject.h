#pragma once
#include "DirectHeader.h"
#include <vector>
#include "SpriteResource.h"
#include <map>
#include "Sprite.h"

using namespace std;



class CGameObject
{

protected:  // Render Á¤º¸
	RenderInfo m_GameInfo;

	wstring m_strTextureName;
	wstring m_strSpriteName;
	int m_iFrame = 0;

	void DrawFrame();
	void DrawSprite();
	void DrawTexture();

public:
	

public:
	void SetSizeAsSprite(wstring textureName, wstring spriteName);
	void SetSizeAsSprite();


public:


	virtual void Update(float deltaTime);
	virtual void Render();



	void SetPos(D3DXVECTOR3 vecPos);	
	void SetPos(float x, float y, float z=0);
	D3DXVECTOR3 GetPos();
	

	RECT GetRect();


	void SetAngle(float Angle);




public:
	CGameObject();
	virtual ~CGameObject();
};




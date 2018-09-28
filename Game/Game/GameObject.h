#pragma once
#include "DirectHeader.h"
#include <vector>
#include "SpriteResource.h"
#include <map>
#include "Sprite.h"

using namespace std;



class CGameObject
{

protected:
	RenderInfo m_GameInfo;



	wstring m_strTextureName;
	wstring m_strSpriteName;
	

	float m_fSpeed=0;
	float m_fMovingDirection=0;


	void Draw(wstring textureName, wstring spriteName, int iFrame);
	void Draw(wstring textureName, wstring spriteName);
	void Draw(int iFrame);
	void Draw();
	void DrawWholeTexture(wstring textureName);

public:
	int m_iFrame = 0;

public:
	void SetSizeAsSprite(wstring textureName, wstring spriteName);
	void SetSizeAsSprite();


public:


	virtual void Update(float deltaTime);
	virtual void Render()=0;



	void SetPos(D3DXVECTOR3 vecPos);	//Bullet이 생성될때 좌표지정
	void SetPos(float x, float y, float z=0);
	D3DXVECTOR3 GetPos();
	

	RECT GetRect();


	void SetAngle(float Angle);


	bool isOutOfScreen();	//화면에서 벗어났는지 판정

	void SetAdjustIngame();
	void ResetAdjustIngame();









private:
	float m_fSpawnTime;
	bool m_bMoveByBackground;
	int iPattern;

public:
	bool Spawn(float fTimePassed);
	void SetSpawnInformation(float fX, float fY, float SpawnTime,float fRenderDirection, float fMoveDirection, int iPattern, float fSpeed, bool bMoveByGround);



public:
	CGameObject();
	virtual ~CGameObject();
};




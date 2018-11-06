#pragma once
#include "IComponent.h"
#include "directheader.h"
#include <string>

using namespace std;



class C2DSpriteComponent :
	public IComponent
{
private:
	RenderInfo m_RenderInfo;
	friend CGameObject;

	wstring m_strTextureName;
	wstring m_strSpriteName;
	int m_iFrame = 0;

	void SetSizeAsFrame();

public:	//그릴 그림 설정
	void SetTexture(wstring texture);
	void SetSprite(wstring sprite);
	void SetFrame(int frame);


public: //그림을  Auto K 그릴지 설정
	void SetAngle(float fAngle);
	void SetPos(D3DXVECTOR3 vecPos);
	void SetPos(float x, float y, float z = 0);
	void SetRatio(float XRatio, float YRatio);
	void SetSize(float width, float height);


public:
	void DrawFrame();
	void DrawSprite();
	void DrawTexture();


	virtual const wstring GetComponentID() override;
	virtual const wstring GetFamilyID() override;

public:
	C2DSpriteComponent();
	virtual ~C2DSpriteComponent();
};


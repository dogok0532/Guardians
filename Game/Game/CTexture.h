#pragma once
#include "DirectHeader.h"
#include <string>
#include <d3dx9math.h>
#include <map>
#include "Sprite.h"
using namespace std;


class CSprite;
class CTexture
{
private:
	LPDIRECT3DTEXTURE9 m_pTexture=NULL;
	D3DXVECTOR3 m_vecSize;	//가로세로 크기
	static LPD3DXSPRITE m_pSprite;
	D3DXMATRIX m_matWorld;
	map<wstring,CSprite*>  mapSprite;

	D3DCOLOR m_ColorKey;


private:
	LPD3DXLINE JudgeLine;

public:
	void SetSprite(wstring name, CSprite* pSprite);
	void SetSprite(wstring name, spriteInfo* SpriteInfo );

public:
	D3DXVECTOR3 GetSize();
	D3DXVECTOR3 GetSpriteSize(wstring name);


public:
	

	//-----차후 아랫걸로 교체-----//
	void Draw(wstring spriteName, int frame, RenderInfo* pGameInfo);
	void DrawWholeSprite(wstring spriteName, RenderInfo* pGameInfo);
	void DrawWholeTexture(RenderInfo* pGameInfo);
	void DrawJudgeLine(wstring spriteName, RenderInfo* pGameInfo,D3DXMATRIX* pMatrix);

private:
	void UpdateMat(RenderInfo* pGameInfo);
	
public:
	void Release();

public:
	CTexture();
	CTexture(wstring path);

	
	~CTexture();
public:
	void SetDevice(wstring fileName,D3DCOLOR color);



	
private:
	int iFrameX;
	int iFrameY;
	bool bMultiFrame;
};


#pragma once
#include "DirectHeader.h"
#include <string>
#include <d3dx9math.h>
#include <map>

using namespace std;

class ObjectInfo;
class CSprite;
class Texture
{
private:
	LPDIRECT3DTEXTURE9 m_pTexture;
	D3DXVECTOR3 m_vecSize;	//가로세로 크기
	ObjectInfo* m_pGameInfo;
	static LPD3DXSPRITE m_pSprite;
	D3DXMATRIX matWorld;
	map<wstring,CSprite*>  mapSprite;

	D3DCOLOR m_ColorKey = D3DCOLOR_ARGB(255,255,255,255);


public:
	

public:
	D3DXVECTOR3 GetSize();
	void SetInfo(ObjectInfo* pObjectInfo);
	void SetColorKey(D3DCOLOR color);

public:
	
	void Update();
	void Render();

	//-----차후 아랫걸로 교체-----//
	void Draw(wstring spriteName, int frame);

public:
	void Release();

public:
	Texture(wstring fileName);
	Texture(wstring fileName, int frameX,int frameY); // 한장에 가로세로별로 몇장씩 있는지 정의
	~Texture();
private:
	void SetDevice(wstring fileName);
	
private:
	int iFrameX;
	int iFrameY;
	bool bMultiFrame;
};


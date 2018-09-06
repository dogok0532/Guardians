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
	D3DXVECTOR3 m_vecSize;	//���μ��� ũ��
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

	//-----���� �Ʒ��ɷ� ��ü-----//
	void Draw(wstring spriteName, int frame);

public:
	void Release();

public:
	Texture(wstring fileName);
	Texture(wstring fileName, int frameX,int frameY); // ���忡 ���μ��κ��� ���徿 �ִ��� ����
	~Texture();
private:
	void SetDevice(wstring fileName);
	
private:
	int iFrameX;
	int iFrameY;
	bool bMultiFrame;
};


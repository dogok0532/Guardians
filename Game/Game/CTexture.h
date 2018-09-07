#pragma once
#include "DirectHeader.h"
#include <string>
#include <d3dx9math.h>
#include <map>
#include "Sprite.h"
using namespace std;

class ObjectInfo;
class CSprite;
class CTexture
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
	void SetTexture(wstring path, D3DCOLOR ColorKey);	//path�� �� �̸�
	void SetSprite(wstring name, CSprite* pSprite);
	void SetSprite(wstring name, spriteInfo* SpriteInfo );

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
	CTexture();
	CTexture(wstring fileName);
	CTexture(wstring fileName, int frameX,int frameY); // ���忡 ���μ��κ��� ���徿 �ִ��� ����

	
	~CTexture();
private:
	void SetDevice(wstring fileName);
	
private:
	int iFrameX;
	int iFrameY;
	bool bMultiFrame;
};


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
	LPDIRECT3DTEXTURE9 m_pTexture=NULL;
	D3DXVECTOR3 m_vecSize;	//���μ��� ũ��
	ObjectInfo* m_pGameInfo=NULL;
	static LPD3DXSPRITE m_pSprite;
	D3DXMATRIX matWorld;
	map<wstring,CSprite*>  mapSprite;

	D3DCOLOR m_ColorKey;

public:
	void SetTexture(wstring path, D3DCOLOR ColorKey);	//path�� �� �̸�
	void SetSprite(wstring name, CSprite* pSprite);
	void SetSprite(wstring name, spriteInfo* SpriteInfo );

public:
	D3DXVECTOR3 GetSize();
	void SetInfo(ObjectInfo* pObjectInfo);

public:
	
	
	void Render();

	//-----���� �Ʒ��ɷ� ��ü-----//
	void Draw(wstring spriteName, int frame, ObjectInfo* pGameInfo);
	void DrawWholeTexture(ObjectInfo* pGameInfo);

private:
	void UpdateMat();
	
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


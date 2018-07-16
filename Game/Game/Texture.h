#pragma once
#include "DirectHeader.h"
#include <string>

using namespace std;
class CTexture
{
private:
	LPDIRECT3DTEXTURE9 m_pTexture;
	
	D3DXVECTOR3 m_vecSize;	//가로세로 크기
	D3DXVECTOR3 m_vecPos;		//좌표

	D3DXVECTOR3 m_vecRenderSizeRatio = { 1,1,1 }; //배율
	float m_fTurn=0;	//각도

	D3DXMATRIX m_matRender;

	static LPD3DXSPRITE m_pSprite;

public:
	void SetPos(D3DXVECTOR3 vecPos);
	void SetPos(float x,float y, float z=0);

	void SetRenderSizeRatio(D3DXVECTOR3 vecPos);
	void SetRenderSizeRatio(float x, float y, float z = 0);

	void SetRenderSize(D3DXVECTOR3 vecPos);
	void SetRenderSize(float x, float y, float z = 0);


public:
	D3DXVECTOR3 GetSize();

public:
	void Render();
	

public:
	void Release();

public:
	CTexture(wstring fileName);
	~CTexture();

	
};


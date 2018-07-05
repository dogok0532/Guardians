#pragma once
class CGameObject
{
protected:
	D3DXVECTOR3 vecPos;	//좌표
	D3DXVECTOR3 vecDir;	//방향

	vector<LPDIRECT3DTEXTURE9> vecImage;	//이미지파일
	LPD3DXSPRITE pSprite;
	
public:
	virtual void Update(float deltaTime);
	virtual void Render();

public:
	CGameObject();
	virtual ~CGameObject();
};


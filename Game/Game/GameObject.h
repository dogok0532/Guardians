#pragma once
class CGameObject
{
protected:
	D3DXVECTOR3 vecPos;	//��ǥ
	D3DXVECTOR3 vecDir;	//����

	vector<LPDIRECT3DTEXTURE9> vecImage;	//�̹�������
	LPD3DXSPRITE pSprite;
	
public:
	virtual void Update(float deltaTime);
	virtual void Render();

public:
	CGameObject();
	virtual ~CGameObject();
};


#pragma once
#include "IComponent.h"
#include "DirectHeader.h"
#include <map>
#include "Sprite.h"
#include "CharacterEnum.h"



struct PlayerTexture {
	CSprite sprite;
	LPDIRECT3DTEXTURE9 texture;
};
class CCharacterComponent;
class CCharacterRenderComponent :
	public IComponent
{
	friend class CCharacterComponent;

private:
	static bool m_bTextureLoaded;
	static std::map<wstring, PlayerTexture*> m_pTexture[WAY_END];


private: //웬만하면 고정될 값
	D3DXVECTOR3 m_vecFrameSize = { 64,64,0 };
	D3DXVECTOR3 m_vecFrameCenter = {32,16,0};
	

private:
	int m_iCurrentFrame = 0;
	float m_fFrameRate;
	float m_fPassedTime;

	eWay m_CurrentWay;
	wstring m_strStatus;
	D3DXVECTOR3 m_vecPos;

public:
	

public:
	virtual void Update(float deltaTime) override;
	virtual void Render() override;

public:
	CCharacterRenderComponent();
	virtual ~CCharacterRenderComponent();
	
private:
	void GetTextureInfo();



};


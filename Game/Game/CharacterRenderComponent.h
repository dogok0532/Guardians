#pragma once
#include "IComponent.h"
#include "DirectHeader.h"
#include <map>
#include "Sprite.h"
#include "CharacterEnum.h"



struct PlayerTexture {
	CSprite sprite;
	LPDIRECT3DTEXTURE9 texture;
	float fFrameRate;
	bool isTurn;
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
	D3DXVECTOR3 m_vecFrameCenter = { 32,16,0 };	//


private:
	int m_iCurrentFrame = 0;
	int m_iMaxFrame;
	float m_fPassedTime;
	float m_fFrameRate = 0.5;		//프레임 관련



	eWay m_CurrentWay;				//방향
	eStatus m_CurrentStatus;		//상태
	wstring m_strCurrentStatus;		//상태(문자열)
	D3DXVECTOR3 m_vecPos;			//그릴좌표


private:
	bool m_isCycleEnded = false;	//반복이 끝났는가
	eStatus m_SavedStatus;



	
private:
	bool m_isTurn=false;		//직진형주기인가
	bool m_isTurned = false;	//되돌아오는중인가

public:
	void UpdateFrameStraight();
	void UpdateFrameTurnBack();

public:
	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	
	
	void UpdateStatusToString();

public:
	CCharacterRenderComponent();
	virtual ~CCharacterRenderComponent();
	
private:
	void GetTextureInfo();



};


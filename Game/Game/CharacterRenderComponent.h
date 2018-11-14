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


private: //�����ϸ� ������ ��
	D3DXVECTOR3 m_vecFrameSize = { 64,64,0 };
	D3DXVECTOR3 m_vecFrameCenter = { 32,16,0 };	//


private:
	int m_iCurrentFrame = 0;
	int m_iMaxFrame;
	float m_fPassedTime;
	float m_fFrameRate = 0.5;		//������ ����



	eWay m_CurrentWay;				//����
	eStatus m_CurrentStatus;		//����
	wstring m_strCurrentStatus;		//����(���ڿ�)
	D3DXVECTOR3 m_vecPos;			//�׸���ǥ


private:
	bool m_isCycleEnded = false;	//�ݺ��� �����°�
	eStatus m_SavedStatus;



	
private:
	bool m_isTurn=false;		//�������ֱ��ΰ�
	bool m_isTurned = false;	//�ǵ��ƿ������ΰ�

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


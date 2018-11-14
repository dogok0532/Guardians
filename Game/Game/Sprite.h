#pragma once
#include <string>
#include <vector>
#include <d3dx9.h>

using namespace std;


struct spriteInfo
{
	int iXBegin;	//Sprite의 텍스쳐내 시발점X
	int iYBegin;	//Sprite의 텍스쳐내 시발점Y
	int iIsLine; //0이면 라인없음, 1이상이면 라인의 사이즈
	int iFrameCount; // 총 프레임 개수
	int iXFrame;	//수평 프레임 개수
	int iYFrame;	//수직 프레임 개수
	int iXSize;		// SpriteFrame의 X크기
	int iYSize;		// SpriteFrame의 Y크기
};

class CTexture;
class CSprite
{
private:

	spriteInfo m_SpriteInfo;

public:	

	RECT GetFrameRect(int Frame);
	RECT GetSpriteRect();

	D3DXVECTOR3 GetFrameCenter();
	D3DXVECTOR3 GetSpriteCenter();


	void SetSpriteInfo(spriteInfo* SpriteInfo);

	D3DXVECTOR3 GetSize();


	int GetFrameCount() { return m_SpriteInfo.iFrameCount; }
public:
	CSprite();
	CSprite(wstring name, int XBegin, int YBegin, int isLine,int XFrame,int YFrame,int XSize, int YSize);
	virtual ~CSprite();
};


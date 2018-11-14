#pragma once
#include <string>
#include <vector>
#include <d3dx9.h>

using namespace std;


struct spriteInfo
{
	int iXBegin;	//Sprite�� �ؽ��ĳ� �ù���X
	int iYBegin;	//Sprite�� �ؽ��ĳ� �ù���Y
	int iIsLine; //0�̸� ���ξ���, 1�̻��̸� ������ ������
	int iFrameCount; // �� ������ ����
	int iXFrame;	//���� ������ ����
	int iYFrame;	//���� ������ ����
	int iXSize;		// SpriteFrame�� Xũ��
	int iYSize;		// SpriteFrame�� Yũ��
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


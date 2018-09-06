#pragma once
#include <string>
#include <vector>
#include <d3dx9.h>
using namespace std;

class CTexture;
class CSprite
{
private:

	int iXBegin;
	int iYBegin;
	
	int iIsLine; //0�̸� ���ξ���, 1�̻��̸� ������ ������

	int iXFrameCount;
	int iYFrameCount;

	int iTotalFrameCount;
	int iCurrentFrame;

	int iXSize;
	int iYSize;


public:	

	const RECT* GetRect(int Frame);
	const D3DXVECTOR3* GetCenter();

public:
	CSprite();
	CSprite(wstring name, int XBegin, int YBegin, int isLine,int XFrame,int YFrame,int XSize, int YSize);
	virtual ~CSprite();
};


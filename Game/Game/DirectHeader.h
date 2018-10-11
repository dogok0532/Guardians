#pragma once


#include <d3d9.h>
#include <d3dx9core.h>

struct RenderInfo
{
	D3DXVECTOR3 vecPos;	//좌표
	D3DXVECTOR3 vecSize = { 0,0,0 }; //이미지크기
	D3DXVECTOR3 vecRenderRatio = { 1,1,1 };
	float fRenderDirection = 0;

};
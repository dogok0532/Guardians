#pragma once


#include <d3d9.h>
#include <d3dx9core.h>

struct RenderInfo
{
	D3DXVECTOR3 vecPos;	//ÁÂÇ¥
	D3DXVECTOR3 vecSize = { 0,0,0 }; //Å©±â
	D3DXVECTOR3 vecRenderRatio = { 1,1,1 };

	float fRenderDirection = 0;

};
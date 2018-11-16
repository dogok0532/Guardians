#include "CTexture.h"

#include "direct.h"
#include "GameObject.h"

#define D3D_DEBUG_INFO



LPD3DXSPRITE CTexture::m_pSprite;




void CTexture::SetSprite(wstring name,CSprite* pSprite)
{
	mapSprite.insert(make_pair(name, pSprite));
}

void CTexture::SetSprite(wstring name, spriteInfo* SpriteInfo)
{
	CSprite* pSprite;
	pSprite = new CSprite();
	pSprite->SetSpriteInfo(SpriteInfo);

	mapSprite.insert(make_pair(name, pSprite));
}

D3DXVECTOR3 CTexture::GetSize()
{
	return m_vecSize;
}

D3DXVECTOR3 CTexture::GetSpriteSize(wstring name)
{
	
	if(name !=L"" && NULL!=mapSprite[name])
		return mapSprite[name]->GetSize();

	return D3DXVECTOR3(0, 0, 0);
}



void CTexture::UpdateMat(RenderInfo* pGameInfo)	//행렬 정보 업데이트
{
	
	D3DXMatrixIdentity(&m_matWorld);

	D3DXMATRIX matScale;
	D3DXMatrixScaling(&matScale,
		pGameInfo->vecRenderRatio.x,
		pGameInfo->vecRenderRatio.y,
		pGameInfo->vecRenderRatio.z);


	D3DXMATRIX matRotate;

	D3DXMATRIX matTempMove;
	D3DXMatrixTranslation(&matTempMove,
		-pGameInfo->vecPos.x,
		-pGameInfo->vecPos.y,
		-pGameInfo->vecPos.z);

	matRotate = matTempMove;

	D3DXMATRIX matTempRotate;
	D3DXMatrixRotationZ(&matTempRotate, pGameInfo->fRenderDirection * DEGREE_TO_RADIAN);

	matRotate *= matTempRotate;
	D3DXMatrixTranslation(&matTempMove,
		pGameInfo->vecPos.x,
		pGameInfo->vecPos.y,
		pGameInfo->vecPos.z);

	matRotate *= matTempMove;

	D3DXMATRIX matMove;
	D3DXMatrixTranslation(&matMove, 0, 0, 0);

	m_matWorld = matRotate * matMove * matScale;

	


	
}




void CTexture::Draw(wstring spriteName, int frame, RenderInfo* pGameInfo)	//차후바꿀것
{
	if (spriteName == L"")
	{
		DrawWholeTexture(pGameInfo);
	}

	if (mapSprite[spriteName] == NULL)
	{
		printf("Invalid Sprite");
		return;
	}
	pGameInfo;
	UpdateMat(pGameInfo);
	m_pSprite->SetTransform(&m_matWorld);



	RECT rcSrc = mapSprite[spriteName]->GetFrameRect(frame);
	D3DXVECTOR3 vecCenter = mapSprite[spriteName]->GetFrameCenter();

	int x = pGameInfo->vecPos.x;
	int y = pGameInfo->vecPos.y;
	D3DXVECTOR3 vecPos = { (float)x,(float)y,0 };

	m_pSprite->Draw(m_pTexture,&rcSrc, &vecCenter,
		&vecPos, DEFAULT_COLOR);

	DrawJudgeLine(spriteName, pGameInfo,&m_matWorld);


}

void CTexture::DrawWholeSprite(wstring spriteName, RenderInfo* pGameInfo)
{

	UpdateMat(pGameInfo);
	m_pSprite->SetTransform(&m_matWorld);


	RECT rcSrc = mapSprite[spriteName]->GetSpriteRect();
	D3DXVECTOR3 vecCenter = mapSprite[spriteName]->GetSpriteCenter();

	m_pSprite->Draw(m_pTexture, &rcSrc, &(m_vecSize / 2), &(pGameInfo->vecPos), DEFAULT_COLOR);
	D3DXMatrixIdentity(&m_matWorld);

	m_pSprite->SetTransform(&m_matWorld);
}

void CTexture::DrawWholeTexture(RenderInfo* pGameInfo)
{

	UpdateMat(pGameInfo);
	m_pSprite->SetTransform(&m_matWorld);

	m_pSprite->Draw(m_pTexture, NULL, &(m_vecSize / 2), &(pGameInfo->vecPos), DEFAULT_COLOR);
	D3DXMatrixIdentity(&m_matWorld);

	m_pSprite->SetTransform(&m_matWorld);
}

void CTexture::DrawJudgeLine(wstring spriteName, RenderInfo* pGameInfo, D3DXMATRIX* pMatrix)
{
	D3DXVECTOR3 vecSize = GetSpriteSize(spriteName);
	vecSize /= 2.f;

	D3DXVECTOR2 line[5] = { {pGameInfo->vecPos.x - vecSize.x,
		pGameInfo->vecPos.y - vecSize.y},

		{pGameInfo->vecPos.x + vecSize.x,
		pGameInfo->vecPos.y - vecSize.y},

		{pGameInfo->vecPos.x + vecSize.x,
		pGameInfo->vecPos.y + vecSize.y},

		{pGameInfo->vecPos.x - vecSize.x,
		pGameInfo->vecPos.y + vecSize.y},

		{pGameInfo->vecPos.x - vecSize.x,
		pGameInfo->vecPos.y - vecSize.y}
	};
	D3DXVECTOR4 vec4Result[5];

	for (int i = 0; i < 5; i++)
	{
		D3DXVec2Transform(&vec4Result[i], &line[i], pMatrix);
		
		line[i] = {vec4Result[i].x,vec4Result[i].y};
	}
	
	m_pSprite->End();

	JudgeLine->Draw(line, 5,  D3DCOLOR_XRGB(255, 0, 0));
	
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void CTexture::Release()
{
	if(m_pTexture)
		m_pTexture->Release();

	if (JudgeLine)
		JudgeLine->Release();
}

CTexture::CTexture()
{
	HRESULT hr =D3DXCreateLine(CDirect::GetInstance()->GetDevice(), &JudgeLine);
	

	bMultiFrame = false;
}


CTexture::CTexture(wstring path)
{
	SetDevice(path,D3DCOLOR_ARGB(255,255,255,255));
	bMultiFrame = false;
}



CTexture::~CTexture()
{
	map<wstring, CSprite*>::iterator iter= mapSprite.begin();
	for (; iter != mapSprite.end(); iter++)
	{
		if (iter->second)
		{
			delete iter->second;
		}
	}
	mapSprite.clear();
}

void CTexture::SetDevice(wstring fileName, D3DCOLOR color)
{
	if (m_pTexture)
	{
		MessageBox(g_hWnd, L"이미 텍스쳐가 설정되어있습니다!", fileName.c_str(), MB_OK);
		return;
	}

	HRESULT hr;

	D3DXIMAGE_INFO ImageInfo;

	hr = D3DXGetImageInfoFromFile(fileName.c_str(), &ImageInfo);


	m_vecSize = { (float)ImageInfo.Width, (float)ImageInfo.Height, 0 };

	if (FAILED(hr))
	{
		return;
	}
	hr = D3DXCreateTextureFromFileEx(CDirect::GetInstance()->GetDevice(),
		fileName.c_str(),
		ImageInfo.Width,
		ImageInfo.Height,
		1, 0,
		ImageInfo.Format,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		color,
		NULL,
		NULL,
		&m_pTexture);

	m_ColorKey = color;
	

	if (FAILED(hr))
	{
		MessageBox(g_hWnd, L"이미지 파일을 찾을수 없습니다!", fileName.c_str(), MB_OK);
		return;
	}

	m_pSprite = CDirect::GetInstance()->GetSprite();
}


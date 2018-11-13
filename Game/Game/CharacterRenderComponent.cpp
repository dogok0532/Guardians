#include "CharacterRenderComponent.h"
#include "direct.h"
#include "tinyxml.h"

#include "MainGame.h"
#include "SpriteResource.h"
#include "CharacterComponent.h"

void CCharacterRenderComponent::Update(float deltaTime)
{
	m_fPassedTime += deltaTime;

	m_fFrameRate = 0.1;
	if (m_fPassedTime <0 || m_fPassedTime >m_fFrameRate)
	{
		m_fPassedTime = 0;
		m_iCurrentFrame++;
	}
}

void CCharacterRenderComponent::Render()
{
	
	if (m_pTexture[m_CurrentWay][m_strStatus])
	{
		RECT rc = m_pTexture[m_CurrentWay][m_strStatus]->sprite.GetFrameRect(m_iCurrentFrame);

		HRESULT hr = CDirect::GetInstance()->GetSprite()->Draw(
			m_pTexture[m_CurrentWay][m_strStatus]->texture,
			&m_pTexture[m_CurrentWay][m_strStatus]->sprite.GetFrameRect(m_iCurrentFrame),
			&m_vecFrameCenter,
			&m_vecPos,
			DEFAULT_COLOR
		);

		int i = 0;
	}
}

CCharacterRenderComponent::CCharacterRenderComponent()
{

	if (m_bTextureLoaded == false)
	{
		GetTextureInfo();
		m_bTextureLoaded = true;
	}

	
	
}

CCharacterRenderComponent::~CCharacterRenderComponent()
{
}

void CCharacterRenderComponent::GetTextureInfo()
{
	TiXmlDocument xmlDoc;
	xmlDoc.LoadFile("../Script\\PlayerTexture.xml");
	TiXmlElement* xmlRoot = xmlDoc.FirstChildElement("PlayerTexture");
	
	string strValue = xmlRoot->FirstChildElement("Width")->GetText();
	m_vecFrameSize.x = atoi(strValue.c_str());

	strValue = xmlRoot->FirstChildElement("Height")->GetText();
	m_vecFrameSize.y = atoi(strValue.c_str());

	strValue = xmlRoot->FirstChildElement("Pivot")->FirstChildElement("X")->GetText();
	m_vecFrameCenter.x = atoi(strValue.c_str());

	strValue = xmlRoot->FirstChildElement("Pivot")->FirstChildElement("Y")->GetText();
	m_vecFrameCenter.y = atoi(strValue.c_str());

	

	D3DXIMAGE_INFO ImageInfo;
	string fileRoute= xmlRoot->FirstChildElement("Route")->GetText();
	
	TiXmlElement* xmlTextureList = xmlRoot->FirstChildElement("TextureList");
	

	for (int i = 0; i < WAY_END; i++)
	{
		TiXmlElement* xmlTexture = xmlTextureList->FirstChildElement("Texture");
		string folder;
		folder = to_string(i);


		while (xmlTexture !=nullptr)
		{
			string status = xmlTexture->FirstChildElement("Status")->GetText();
			wstring wStatus;
			wStatus.append(status.begin(), status.end());

			string fileName = fileRoute + folder + "\\"+ status +".png";
			wstring wFileName;
			wFileName.append(fileName.begin(), fileName.end());

			
			HRESULT hr = D3DXGetImageInfoFromFile(wFileName.c_str(), &ImageInfo);

			PlayerTexture* pPlayerTexture = new PlayerTexture;
			m_pTexture[i].insert(make_pair(wStatus, pPlayerTexture));

			hr = D3DXCreateTextureFromFileEx(CDirect::GetInstance()->GetDevice(),
				wFileName.c_str(),
				ImageInfo.Width,
				ImageInfo.Height,
				1, 0,
				ImageInfo.Format,
				D3DPOOL_DEFAULT,
				D3DX_DEFAULT,
				D3DX_DEFAULT,
				DEFAULT_COLOR,
				NULL,
				NULL,
				&(pPlayerTexture->texture));




			spriteInfo SpriteInfo;
			SpriteInfo.iFrameCount = atoi( xmlTexture->FirstChildElement("Frame")->GetText());
			SpriteInfo.iIsLine = 0;
			SpriteInfo.iXBegin = 0;
			SpriteInfo.iYBegin = 0;
			SpriteInfo.iXSize = m_vecFrameSize.x;
			SpriteInfo.iYSize = m_vecFrameSize.y;
			SpriteInfo.iXFrame = SpriteInfo.iFrameCount;
			SpriteInfo.iYFrame = 1;

			

			

			m_pTexture[i][wStatus]->sprite.SetSpriteInfo(&SpriteInfo);

			xmlTexture = xmlTexture->NextSiblingElement();
		}
	}

	//delete xmlRoot;
	
}

bool CCharacterRenderComponent::m_bTextureLoaded = false;

std::map<std::wstring, PlayerTexture*> CCharacterRenderComponent::m_pTexture[WAY_END];


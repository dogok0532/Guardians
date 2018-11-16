#include "CharacterRenderComponent.h"
#include "direct.h"
#include "tinyxml.h"

#include "MainGame.h"
#include "SpriteResource.h"
#include "CharacterComponent.h"

void CCharacterRenderComponent::Update(float deltaTime)
{
	UpdateStatusToString();

	
	m_iMaxFrame = m_pTexture[m_CurrentWay][m_strCurrentStatus]->sprite.GetFrameCount();
	if (m_iCurrentFrame >= m_iMaxFrame)
		m_iCurrentFrame %= m_iMaxFrame;
	

	m_fPassedTime += deltaTime;
	
	
	if (m_CurrentStatus == STOP_IDLE)
	{
		UpdateFrameTurnBack();
	}

	else if (m_CurrentStatus == WALK)
	{
		UpdateFrameStraight();
	}


	
}

void CCharacterRenderComponent::Render()
{
	if (m_pTexture[m_CurrentWay][m_strCurrentStatus])
	{
		RECT rc = m_pTexture[m_CurrentWay][m_strCurrentStatus]->sprite.GetFrameRect(m_iCurrentFrame);
		HRESULT hr = CDirect::GetInstance()->GetSprite()->Draw(
			m_pTexture[m_CurrentWay][m_strCurrentStatus]->texture,
			&m_pTexture[m_CurrentWay][m_strCurrentStatus]->sprite.GetFrameRect(m_iCurrentFrame),
			&m_vecFrameCenter,
			&m_vecPos,
			DEFAULT_COLOR);
	
	}
}



void CCharacterRenderComponent::UpdateFrameStraight()
{
	if (m_fPassedTime > m_fFrameRate)
	{
		m_iCurrentFrame++;
		m_fPassedTime = 0;
	}
}

void CCharacterRenderComponent::UpdateFrameTurnBack()
{

	if (m_fPassedTime > m_fFrameRate)
	{
		if (m_isTurned)
		{
			m_iCurrentFrame--;
			if (m_iCurrentFrame == 0)
			{
				m_isTurned = false;
			}
		}

		else
		{
			m_iCurrentFrame++;
			if (m_iCurrentFrame == m_iMaxFrame-1)
			{				
				m_isTurned = true;
			}
		}
		m_fPassedTime = 0;
	}
}

void CCharacterRenderComponent::ResetFrame()
{
	m_isTurned = false;
	m_iCurrentFrame = 0;
}

void CCharacterRenderComponent::UpdateStatusToString()
{

	switch (m_CurrentStatus)
	{
	case STOP_IDLE:
		m_strCurrentStatus = L"Stop Idle";
		break;
	case STOP_AIM:
		m_strCurrentStatus = L"Stop Aim";
		break;
	case STOP_FIRE:
		m_strCurrentStatus = L"Stop Fire";
		break;
	case CROUCH:
		m_strCurrentStatus = L"Crouch";
		break;
	case CROUCH_AIM:
		m_strCurrentStatus = L"Crouch Aim";
		break;
	case CROUCH_FIRE:
		m_strCurrentStatus = L"Crouch Fire";
		break;
	case WALK:
		m_strCurrentStatus = L"Walk";
		break;
	case WALK_AIM:
		m_strCurrentStatus = L"Walk Aim";
		break;
	case WALK_FIRE:
		m_strCurrentStatus = L"Walk Fire";
		break;
	case THROW_GRANADE:
		m_strCurrentStatus = L"Throw Granade";
		break;
	case HIT:
		m_strCurrentStatus = L"Hit 0";
		break;
	case HIT_BLOOD:
		m_strCurrentStatus = L"Hit Blood 0";
		break;
	case HIT_EXPLODE:
		m_strCurrentStatus = L"Hit Explo Blood";
		break;
	default:
		break;
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

	xmlDoc.Clear();
	
}

bool CCharacterRenderComponent::m_bTextureLoaded = false;

std::map<std::wstring, PlayerTexture*> CCharacterRenderComponent::m_pTexture[WAY_END];


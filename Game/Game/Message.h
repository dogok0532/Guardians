
#pragma once
#include <string>
using namespace std;

class IComponent;

class CMessage
{
private:
	IComponent* m_sender;

	wstring m_receiverObjectID;	//�޼����� ���� Ư��������Ʈ
	wstring m_receiverComponentID;//�޼����� ���� Ư�� ������Ʈ
	wstring m_receiverFamilyID;		//�޼����� ���� �ش�迭 ������Ʈ
	IComponent* m_receiver;		//�޼����� ���� Ư�� ������Ʈ�� Ư�� ������Ʈ


	wstring m_messageType;

public:
	CMessage(IComponent* sender,
		wstring receiverObjectId, wstring receiverComponentID,
		wstring receiverFamilyID, IComponent* m_receiver,
		wstring messageType);
	~CMessage();
};






#pragma once
#include <string>
using namespace std;

class IComponent;

class CMessage
{
private:
	IComponent* m_sender;

	wstring m_receiverObjectID;	//메세지를 받을 특정오브젝트
	wstring m_receiverComponentID;//메세지를 받을 특정 컴포넌트
	wstring m_receiverFamilyID;		//메세지를 받을 해당계열 컴포넌트
	IComponent* m_receiver;		//메세지를 받을 특정 오브젝트의 특정 컴포넌트


	wstring m_messageType;

public:
	CMessage(IComponent* sender,
		wstring receiverObjectId, wstring receiverComponentID,
		wstring receiverFamilyID, IComponent* m_receiver,
		wstring messageType);
	~CMessage();
};





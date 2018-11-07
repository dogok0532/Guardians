#include "Message.h"





CMessage::CMessage(IComponent* sender , 
	wstring receiverObjectId, wstring receiverComponentID,
	wstring receiverFamilyID, IComponent* receiver,
	wstring messageType)
{
	m_sender = sender;

	m_receiverObjectID = receiverObjectId;
	m_receiverFamilyID = receiverFamilyID;
	m_receiverComponentID = receiverComponentID;
	m_receiver = receiver;
}

CMessage::~CMessage()
{
}

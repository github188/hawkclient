#ifndef HAWK_MSGLISTENER_H
#define HAWK_MSGLISTENER_H

#include "HawkMsg.h"

namespace Hawk
{
	/************************************************************************/
	/* ��Ϣ������                                                           */
	/************************************************************************/
	class UTIL_API HawkMsgListener : public HawkRefCounter
	{
	public:
		//����
		HawkMsgListener();

		//����
		virtual ~HawkMsgListener();

		//��Ϣע���
		typedef map<Int32, Int32> RegMsgMap;

	public:
		//ע����Ϣ����
		virtual Bool   RegisterMsg(Int32 iMsg);

		//��Ϣ����
		virtual Bool   OnMessage(const HawkMsg& sMsg);

		//�Ƴ���Ϣ����(����Ϊ0��ʾ�Ƴ�����)
		virtual Bool   RemoveMsg(Int32 iMsg = 0);

	protected:
		//ע�����Ϣӳ��
		RegMsgMap  m_mRegMsg;
	};	
}
#endif

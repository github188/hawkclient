#ifndef HAWK_MSGPUMP_H
#define HAWK_MSGPUMP_H

#include "HawkMsgListener.h"
#include "HawkMutex.h"

namespace Hawk
{
	/************************************************************************/
	/* ��Ϣ�ô�����                                                         */
	/************************************************************************/
	class UTIL_API HawkMsgPump : public HawkRefCounter
	{
	public:
		//����
		HawkMsgPump(Bool bThreadSafe = false);

		//����
		virtual ~HawkMsgPump();

		//��Ϣ�������б�
		typedef map<HawkMsgListener*, HawkMsgListener*> RegListenerMap;

		//��Ϣ�����б�
		typedef map<Int32, RegListenerMap>				MsgListenerMap;

	public:
		//ע����Ϣ������
		virtual Bool     AddMsgListener(Int32 iMsg, const HawkMsgListener* pListener);

		//Ͷ����Ϣ(������)
		virtual Bool	 PostMsg(HawkMsg* pMsg);

		//������Ϣ(����)
		virtual Bool     SendMsg(HawkMsg* pMsg);

		//�ַ�������Ϣ
		virtual Bool     DispatchAllMsg();

		//�Ƴ���Ϣ������
		virtual Bool     RemoveMsgListener(Int32 iMsg, const HawkMsgListener* pListener);

	protected:
		//�������м�����
		virtual Bool     RemoveAllListener();

		//����������Ϣ
		virtual Bool     RemoveAllMsg();

	protected:
		//��Ϣ�����б�
		MsgListenerMap	  m_mMsgListener;		
		//��Ϣ����
		vector<HawkMsg*>  m_vPumpMsg;
		//��������
		HawkMutex*		  m_pListenerMutex;
		//��Ϣ����
		HawkMutex*		  m_pMsgMutex;
	};	
}
#endif

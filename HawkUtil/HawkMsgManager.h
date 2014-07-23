#ifndef HAWK_MSGMANAGER_H
#define HAWK_MSGMANAGER_H

#include "HawkMsgPump.h"
#include "HawkManagerBase.h"

namespace Hawk
{
	/************************************************************************/
	/* ��Ϣ������,�ڴ������ͷ���Ϣ֮ǰ,����ע�����ҵ���Ϣ����               */
	/************************************************************************/
	class UTIL_API HawkMsgManager : public HawkManagerBase
	{
	protected:
		//����
		HawkMsgManager();

		//����
		virtual ~HawkMsgManager();

		//��������������
		HAKW_SINGLETON_DECL(MsgManager);

		//ע���б�
		typedef map<Int32, Int32> MsgRegMap;

	public:
		//ע����Ϣ����
		virtual Bool	 Register(Int32 iMsg);	

		//��ȡ��Ϣ
		virtual HawkMsg* GetMsg(Int32 iMsg);

		//�ͷ���Ϣ
		virtual Bool     FreeMsg(HawkMsg*& pMsg);

		//��ȡע��Э��ID�б�
		virtual UInt32	 GetRegMsgIds(vector<Int32>& vMsgIds);

	public:
		//��ʼ����Ϣ��
		virtual Bool     InitMsgPump(Bool bThreadSafe = false);

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
		//ע�������б�
		MsgRegMap		m_mReg;

		//ע������Ϣ��
		HawkMsgPump*	m_pMsgPump;
	};

	#define P_MsgManager  HawkMsgManager::GetInstance()
}
#endif

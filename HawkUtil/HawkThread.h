#ifndef HAWK_THREAD_H
#define HAWK_THREAD_H

#include "HawkTask.h"
#include "HawkMutex.h"

namespace Hawk
{
	/************************************************************************/
	/* �̲߳�����װ                                                         */
	/************************************************************************/
	class UTIL_API HawkThread : public HawkRefCounter
	{
	public:
		//�Ƿ�ȴ��߳�
		HawkThread(Bool bWaitTask = false);

		//�߳�������
		HawkThread(HawkTask* pTask);

		//�̺߳�������
		typedef HawkTask::PThreadRoutine PThreadRoutine;

		//�̹߳���
		HawkThread(PThreadRoutine pRoutine);

		//����
		virtual ~HawkThread();

	public:
		//״̬����
		enum
		{
			STATE_NONE = 0,
			STATE_RUNNING,
			STATE_CLOSING,
			STATE_CLOSED,
		};

	public:
		//�����߳�
		virtual Bool   Start(void* pArgs = 0);

		//�����ȴ������߳�
		virtual Bool   Close();

		//����������,ֻ��ʹ���ڶ������߳�
		virtual Bool   AddTask(HawkTask* pTask, Bool bFirst = false);

		//��ȡPush��ȥ��������
		virtual UInt64 GetPushTaskCnt() const;

		//��ȡPop������������
		virtual UInt64 GetPopTaskCnt() const;

		//��ȡ�߳�ID
		virtual UInt32 GetThreadId() const;

		//��ȡ�߳�����״̬
		virtual Bool   IsRunning() const;

		//�Ƿ�ȴ��ر�
		virtual Bool   IsClosing() const;

		//����ӵ����
		virtual void   SetOwner(PVoid pPool);

		//��ȡӵ����
		virtual PVoid  GetOwner();

	public:
		//�̺߳�������
		virtual PVoid  RunLoop();

	protected:
		//�ڲ���ʼ��
		virtual Bool   InnerInit();

		//����������
		virtual void   ClearTaskQueue();

		//�����������
		virtual void   RunTaskQueue();

	protected:
		//�߳̾��
		PVoid		    m_pThread;
		//�̺߳�������
		PVoid			m_pArgs;
		//ӵ����(�����̳߳�)
		PVoid			m_pOwner;
		//�߳�ID
		UInt32			m_iId;
		//�߳�״̬
		volatile UInt32	m_iState;
		//������
		volatile Bool   m_bRunning;
		//�߳��������
		TaskQueue		m_qTask;
		//�̺߳�����ڵ�ַ
		PThreadRoutine	m_pRoutine;
		//������л�����
		HawkMutex*		m_pMutex;
		//��ӵ���������
		UInt64			m_iPushTaskCnt;
		//ִ�е���������
		UInt64			m_iPopTaskCnt;
	};
}
#endif

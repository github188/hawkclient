#ifndef __HAWKSYSPROTOCOLID_H__
#define __HAWKSYSPROTOCOLID_H__

#include "HawkUtil.h"

namespace Hawk
{
	namespace SysProtocol
	{
		enum
		{
			//���ܷ�ʽ
			SYS_SECURITY = 1,
			//ѡ������
			SYS_SEL_SERVER = 2,
			//�Ự��ʼ
			SYS_SESSION_START = 3,
			//�ܾ�����
			SYS_REFUSE_CONN = 4,
			//�Ự�Ͽ�
			SYS_SESSION_BREAK = 5,
			//�Ự�ر�
			SYS_CLOSE_SESSION = 6,
			//Ping����
			SYS_CLT_PING = 7,
			//Pong����
			SYS_SVR_PONG = 8,
			//�ֽ�����
			SYS_OCTETS = 9,
			//�Ự����
			SYS_HEART_BEAT = 10,
			//������ʱ
			SYS_HEART_BREAK = 11,
			//��Ϣ֪ͨ
			SYS_MSG_NOTIFY = 12,
			//����֪ͨ
			SYS_ERR_NOTIFY = 13,
			//��־��Ϣ
			SYS_LOG_MSG = 14,
			//��������
			SYS_PROF_REQ = 15,
			//������Ϣ
			SYS_PROF_INFO = 16,
		};
	}
}
#endif

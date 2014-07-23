#ifndef HAWK_PROTOCOL_H
#define HAWK_PROTOCOL_H

#include "HawkMarshalData.h"
#include "HawkSocket.h"

namespace Hawk
{
	/************************************************************************/
	/* Э���ʽ���������װ                                                 */
	/************************************************************************/
	class UTIL_API HawkProtocol : public HawkMarshal
	{
	public:
		//��������
		enum DriveType
		{
			DRIVE_EVENT = 0,	//�¼�(ÿ�η���)
			DRIVE_STATE,		//״̬(�ı䷢��)
		};

	public:
		//Э�鹹��
		HawkProtocol(ProtoType iType = 0, UInt8 iDrive = DRIVE_EVENT);

		//Э������
		virtual ~HawkProtocol();				

	public:
		//��¡Э��(ʵ��Э�����ʵ��)
		virtual HawkProtocol* Clone() const = 0;

	public:		
		//Э����: Type + Size + Crc + Data
		virtual Bool  Encode(HawkOctetsStream& rhsOS);

		//Э����
		virtual Bool  Decode(HawkOctetsStream& rhsOS);	

		//��ȡ�Խ�Buffer
		virtual Bool  GetDecodeOS(OctetsStream*& pOS);

	public:
		//��ȡЭ������
		ProtoType	  GetType() const;

		//��ȡ�ֽ���
		ProtoSize     GetSize() const;

		//��ȡЭ������У��CRC
		ProtoCrc	  GetCrc() const;		

		//��ȡ����ģʽ
		UInt8		  GetDrive() const;

	protected:
		//�Խ���,Ĭ������»��Խ���
		virtual Bool  DecodeSelf();

	protected:
		//����
		ProtoType	 m_iType;
		//�ֽ���
		ProtoSize	 m_iSize;
		//У����
		ProtoCrc	 m_iCrc;
		//����
		UInt8		 m_iDrive;
		//���ݴ洢��
		OctetsStream m_sDecode;
	};

	//Э�����ͼ�㶨��
	typedef HawkProtocol Protocol;
}
#endif

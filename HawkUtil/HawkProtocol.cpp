#include "HawkProtocol.h"
#include "HawkOSOperator.h"
#include "HawkLoggerManager.h"
#include "HawkProtocolManager.h"

namespace Hawk
{
	HawkProtocol::HawkProtocol(ProtoType iType, UInt8 iDrive) : m_iType(iType), m_iSize(0), m_iCrc(0), m_iDrive(iDrive)
	{
	}

	HawkProtocol::~HawkProtocol()
	{
	}

	ProtoType HawkProtocol::GetType() const
	{
		return m_iType;
	}	

	ProtoSize HawkProtocol::GetSize() const
	{
		return m_iSize;
	}

	ProtoCrc HawkProtocol::GetCrc() const
	{
		return m_iCrc;
	}

	UInt8 HawkProtocol::GetDrive() const
	{
		return m_iDrive;
	}

	Bool HawkProtocol::GetDecodeOS(OctetsStream*& pOS)
	{
		pOS = &m_sDecode;
		return true;
	}

	Bool HawkProtocol::Encode(HawkOctetsStream& rhsOS)
	{
		try
		{
			HawkOctetsStream sEncode;
			sEncode << *this;

			m_iSize = sEncode.Size();
			m_iCrc  = HawkOSOperator::CalcCrc((UChar*)sEncode.Begin(), m_iSize);

			P_ProtocolManager->WriteProtocolHeader(rhsOS, m_iType, m_iSize, m_iCrc);

			rhsOS.Push(sEncode.Begin(),m_iSize);
		}
		catch (HawkException& rhsExcep)
		{
			HawkFmtError(rhsExcep.GetMsg().c_str());
			return false;
		}

		return true;
	}

	Bool HawkProtocol::Decode(HawkOctetsStream& rhsOS)
	{
		//���Э��������
		if (!P_ProtocolManager->CheckDecodeProtocol(rhsOS))
			return false;

		m_iSize = 0;
		m_iCrc  = 0;
		m_sDecode.Clear();

		ProtoType iType = 0;
		ProtoCrc  iCrc  = 0;
		try
		{		
			//��Э��ͷ
			rhsOS >> HawkOctetsStream::TransBegin;

			P_ProtocolManager->ReadProtocolHeader(rhsOS, iType, m_iSize, m_iCrc);
			
			if ((ProtoSize)rhsOS.AvailableSize() >= m_iSize)
			{
				//��Э������
				if (m_iSize)
				{
					m_sDecode.Reserve(m_iSize);
					rhsOS.Pop((void*)m_sDecode.Begin(), m_iSize);
					m_sDecode.Resize(m_iSize);
					iCrc = HawkOSOperator::CalcCrc((UChar*)m_sDecode.Begin(),m_iSize);
				}

				//��ȡ��ȫ,�ύ
				rhsOS >> HawkOctetsStream::TransCommit;
			}
			else
			{
				//���ݰ�����ȫ,�ع�
				rhsOS >> HawkOctetsStream::TransRollback;
				return false;
			}
		}
		catch (HawkException& rhsExcep)
		{
			rhsOS >> HawkOctetsStream::TransRollback;
			HawkFmtError(rhsExcep.GetMsg().c_str());
			return false;
		}

		//����У��
		if(m_iType != iType)
		{
			HawkFmtError("Protocol Type Inconformity, Type: %u, Crc: %u", iType, m_iCrc);
			T_Exception("Protocol Type Inconformity.");
			return false;
		}
		else if(m_iCrc != iCrc)
		{
			HawkFmtError("Protocol Crc Inconformity, Type: %u, Crc: %u", iType, m_iCrc);
			T_Exception("Protocol Crc Inconformity.");
			return false;
		}

		if (P_ProtocolManager->IsAutoDecode())
		{
			return DecodeSelf();
		}

		return true;
	}

	Bool HawkProtocol::DecodeSelf()
	{
		try
		{
			m_sDecode >> *this;
		}
		catch (HawkException& rhsExcep)
		{
			HawkFmtError(rhsExcep.GetMsg().c_str());		
			return false;
		}

		return true;
	}
}

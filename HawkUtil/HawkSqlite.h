#ifndef HAWK_SQLITE_H
#define HAWK_SQLITE_H

#include "HawkRefCounter.h"

namespace Hawk
{
	//////////////////////////////////////////////////////////////////////////
	//Sqlite3���ݿ������װ,Ĭ�ϲ���Utf8����								//
	//////////////////////////////////////////////////////////////////////////
	class UTIL_API HawkSqlite : public HawkRefCounter
	{
	public:
		//DB������
		HawkSqlite();

		//DB��������
		virtual ~HawkSqlite();

	public:
		//���ݿ�����
		DEFINE_PROPERTY(AString, m_sDBName,	  DBName);
		//���ݿ���
		DEFINE_PROPERTY(PVoid,   m_pDBHandle, DBHandle);
		//������Ϣ
		DEFINE_PROPERTY(UString, m_sErrMsg,   ErrMsg);
		//������
		DEFINE_PROPERTY(Int32,   m_iErrCode,  ErrCode);
		//�Ƿ���������
		DEFINE_PROPERTY(Bool,    m_bTrans,    IsTrans);

	public:
		//DB��ѯ�����
		class UTIL_API QueryResult : public HawkRefCounter
		{
		public:
			//����
			QueryResult();

			//����
			virtual ~QueryResult();

			//��Ա������
			friend class HawkSqlite;

		public:
			//�������
			DEFINE_PROPERTY(UInt64, m_iRow,	Row);
			//�������
			DEFINE_PROPERTY(UInt64, m_iCol,	Col);
			//��������
			DEFINE_PROPERTY(PVoid,  m_pRes, Res);

		public:
			//�������л�ȡ���ؽ��
			const Utf8* GetResult(UInt64 iRow, UInt64 iCol, UInt32* pResLen = 0) const;			

			//����������ȡ���ؽ��
			const Utf8* operator[] (UInt64 iIdx) const;

			//�����������з���
			const Utf8* operator()(UInt64 iRow, UInt64 iCol) const;			
		};

	public:
		//�����ݿ�
		virtual Bool	Open(const AString& sDBName);

		//�ر����ݿ�
		virtual Bool	Close();		

	public:		
		//��ѯ����
		virtual Bool	Select(const UString& sSql, QueryResult& sResult);

		//�������
		virtual Bool	Insert(const UString& sSql, QueryResult& sResult);
		
		//���²���
		virtual Bool	Update(const UString& sSql, QueryResult& sResult);
		
		//ɾ������
		virtual Bool	Delete(const UString& sSql, QueryResult& sResult);

		//���ݿ���ɾ�Ĳ����
		virtual Int32	SqlExe(const UString& sSql, Char** ppErrMsg);

	public:
		//��ʼ���ﴦ��
		virtual Bool	BeginTrans();

		//�ع�����
		virtual Bool	RollbackTrans();

		//�ύ����
		virtual Bool	CommitTrans();

	public:				
		//��ȫת��sqlite3�ַ���
		virtual UString AmendString(const UString& sValue);

		//��ȫת��sqlite3�ַ���
		virtual AString AmendString(const AString& sValue);
	};
}
#endif

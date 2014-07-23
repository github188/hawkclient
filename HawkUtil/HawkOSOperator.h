#ifndef HAWK_OSOPERATOR_H
#define HAWK_OSOPERATOR_H

#include "HawkRefCounter.h"

namespace Hawk
{
	/************************************************************************/
	/* �Ͳ���ϵͳ��غ�����װ                                               */
	/************************************************************************/
	class UTIL_API HawkOSOperator : public HawkRefCounter
	{
	public:
		//���ù���·��
		static Bool    SetWorkDir(const AString& sDir);

		//��ù���·��
		static AString GetWorkDir();

		//���ϵͳTick������(CPU)
		static UInt32  GetTickCount();

		//��ȡϵͳʱ��
		static tm      GetSysClock();
	
		//��ȡϵͳʱ������
		static time_t  GetSysTime();

		//���ʱ���ַ���:2008-08-08 08:08:08
		static AString GetTimeString();

		//Sleep��װ
		static void    OSSleep(Int32 iTime);		

		//���ļ�·����ȡ�ļ���
		static AString SplitFileName(const AString& sFile);

		//���ļ�·����ȡ�ļ�·��
		static AString SplitFilePath(const AString& sFile);

		//��������
		static AString SetLocale(Int32 iCategory, const AString& sLocal);

		//�Ƿ����ĳ�ļ�
		static Bool    ExistFile(const AString& sFile);

		//�Ƿ����ĳĿ¼
		static Bool    ExistFolder(const AString& sFolder);

		//����ļ���С
		static Int64   GetFileSize(const AString& sFile);

		//����CRC
		static UInt32  CalcCrc(const UChar* pData, UInt32 iSize, UInt32* pCrc = 0);

		//�����ļ�CRC
		static UInt32  CalcFileCrc(const AString& sFile);
		
		//ɾ���ļ�
		static void    OsDeleteFile(const AString& sFile);

		//�������ļ�
		static Bool    RenameFile(const AString& sOldName, const AString& sNewName);

		//�����ļ���д
		static Bool    SetFileWritable(const AString& sFile);

		//����Ŀ¼��
		static Bool    CreateDir(const AString& sDir);		

		//��֤�ļ�Ŀ¼������
		static void    MakeSureFilePath(const AString& sFolderPath);

		//��֤�ļ���ǰ׺Ŀ¼������
		static void    MakeSureFileName(const AString& sFilePath);

		//��ȡ�ں��߳�ID
		static UInt32  GetThreadId();

		//��ȡ����ID
		static UInt32  GetProcessId();

	public:
		//getch��װ
		static Int32   WaitKeyboardInput(const AString& sInfo = "", Bool bPrint = true);
	};

	//�����Ϊ���׺���
	#define HawkSleep(ms)   HawkOSOperator::OSSleep(ms)
	#define HawkSysTime()   HawkOSOperator::GetSysTime()
	#define HawkTickCount() HawkOSOperator::GetTickCount()
}
#endif

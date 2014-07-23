LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

#����ģ����
LOCAL_MODULE := hawkutil_static

#����ģ���ļ���
LOCAL_MODULE_FILENAME := libhawkutil

#����ĳ��Ŀ¼������cpp�ļ�����
define all-cpp-files-under
$(patsubst $(LOCAL_PATH)/%, %, $(shell find $(1) -maxdepth 1 -name "*.cpp" -and -not -name ".*") )
endef

#ICONV�����������ļ��б�
LOCAL_ICONV_SRC_FILES := \
../../source/iconv/libcharset/lib/localcharset.c \
../../source/iconv/lib/iconv.c \
../../source/iconv/lib/relocatable.c

#SQLITE�������Դ�ļ��б�
LOCAL_SQLITE_SRC_FILES := \
../../source/sqlite/sqlite3.c

#JSON�������Դ�ļ��б�
LOCAL_JSON_SRC_FILES := \
../../source/json/json_reader.cpp \
../../source/json/json_writer.cpp \
../../source/json/json_value.cpp

#ZIP�������Դ�ļ��б�
LOCAL_ZIP_SRC_FILES := \
../../source/zlib/adler32.c \
../../source/zlib/compress.c \
../../source/zlib/crc32.c \
../../source/zlib/deflate.c \
../../source/zlib/infback.c \
../../source/zlib/inffast.c \
../../source/zlib/inflate.c \
../../source/zlib/inftrees.c \
../../source/zlib/ioapi.c \
../../source/zlib/trees.c \
../../source/zlib/uncompr.c \
../../source/zlib/unzip.c \
../../source/zlib/zutil.c

#Hawk�������Դ�ļ��б�
LOCAL_HAWK_SRC_FILES := $(call all-cpp-files-under, $(LOCAL_PATH)/../../)

$(warning $(LOCAL_ICONV_SRC_FILES))
$(warning $(LOCAL_SQLITE_SRC_FILES))
$(warning $(LOCAL_JSON_SRC_FILES))
$(warning $(LOCAL_ZIP_SRC_FILES))
$(warning $(LOCAL_HAWK_SRC_FILES))

#����ʹ�õ�Դ�ļ��б�
LOCAL_SRC_FILES := $(LOCAL_ICONV_SRC_FILES) + \
				   $(LOCAL_SQLITE_SRC_FILES) + \
				   $(LOCAL_JSON_SRC_FILES) + \
				   $(LOCAL_ZIP_SRC_FILES) + \
				   $(LOCAL_HAWK_SRC_FILES)
				   
#��������ͷ�ļ�����
LOCAL_C_INCLUDES := $(LOCAL_PATH) \
					$(LOCAL_PATH)/../../source/sqlite \
                    $(LOCAL_PATH)/../../source/json \
					$(LOCAL_PATH)/../../source/rapidxml \
                    $(LOCAL_PATH)/../../source/zlib \
					$(LOCAL_PATH)/../../source/iconv/include \
					$(LOCAL_PATH)/../../source/iconv/lib \
					$(LOCAL_PATH)/../../source/iconv/libcharset \
					$(LOCAL_PATH)/../../source/iconv/libcharset/include
					
#������ͷ�ļ�·��
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)
				
#�������ļ�����				
LOCAL_LDLIBS := 
#�����������ļ�����
LOCAL_EXPORT_LDLIBS :=

#Ԥ�����Ƕ���
LOCAL_CFLAGS := -DUTIL_EXPORT -DANDROID -D_ANDROID -DUSE_FILE32API -D_FILE_OFFSET_BITS=64 -Wno-multichar -DLIBDIR=\"\" -DBUILDING_LIBICONV -DIN_LIBRARY
#����Ԥ�����Ƕ���
LOCAL_EXPORT_CFLAGS := -DANDROID -D_ANDROID

#����׳��쳣��֧��
LOCAL_CPPFLAGS := -fexceptions
#��������׳��쳣��֧��
LOCAL_EXPORT_CPPFLAGS := -fexceptions

#���ɾ�̬��
include $(BUILD_STATIC_LIBRARY)

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_LDLIBS := -llog \
                -landroid
LOCAL_SHARED_LIBRARIES := liblog libcutils

LOCAL_MODULE    := pfg_jni
LOCAL_SRC_FILES := JniCom.cpp

include $(BUILD_SHARED_LIBRARY)
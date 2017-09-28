/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include <android/log.h>
#include <pthread.h>
/* Header for class com_pfg_jnipro_JniCom */

#ifndef _Included_com_pfg_jnipro_JniCom
#define _Included_com_pfg_jnipro_JniCom
#ifdef __cplusplus
extern "C" {
#endif

#define TAG "JniCom"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define NELM(methods) (sizeof(methods)/sizeof(methods[0]))

/*
 * Class:     com_pfg_jnipro_JniCom
 * Method:    add
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_pfg_jnipro_JniCom_add
  (JNIEnv *env, jobject obj, jint a, jint b)
{
	LOGD("add(%d,%d)", a, b);
	//LOGD("getVersion:%xd",env->GetVersion());
	return a+b;
}

/*
 * Class:     com_pfg_jnipro_JniCom
 * Method:    sub
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_pfg_jnipro_JniCom_sub
  (JNIEnv *env, jobject obj, jint a, jint b)
{
	LOGD("sub(%d,%d)", a, b);
	return a-b;
}

JNINativeMethod methods[] =
{
	{"add","(II)I", (void *)Java_com_pfg_jnipro_JniCom_add},
	{"sub","(II)I", (void *)Java_com_pfg_jnipro_JniCom_sub}
};

JavaVM *gVm;
jobject gobject;
pthread_t thread;

void * thread_func(void *arg)
{
	LOGD("Thread running start==");
	JNIEnv *env;
	//gVm->AttachCurrentThread(p_env, thr_args)
    if(gVm != NULL)
    {
    	jint result = gVm->AttachCurrentThread(&env, (void*)0);
    	jclass clazz = env->FindClass("com/pfg/jnipro/JniCom");
        if(result == 0)
        {
        	jmethodID methodid = env->GetMethodID(clazz, "callBack", "(I)V");
            env->CallVoidMethod(gobject, methodid, 10);
        }
        gVm->DetachCurrentThread();
    }
    LOGD("Thread running end==");
    return (void *)0;
}


JNIEXPORT void JNICALL Java_com_pfg_jnipro_JniCom_startThread
  (JNIEnv *env, jobject object)
{
   int result = env->GetJavaVM(&gVm);
   gobject = env->NewGlobalRef(object);
   if(pthread_create(&thread, NULL, thread_func, (void*)2) != 0)
   {
	   LOGD("Create native thread failed");
	   return;
   }

}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	LOGD("JNI_OnLoad start==");
	JNIEnv *env;
	if(vm->GetEnv((void**)&env, JNI_VERSION_1_6) != JNI_OK)
	{
		LOGD("JNI_OnLoad getEnv failed!");
		return -1;
	}

    jclass clazz = env->FindClass("com/pfg/jnipro/JniCom");
    if(clazz == 0)
    {
    	LOGD("JNI_OnLoad FindClass failed!");
    	return -1;
    }

    int result = env->RegisterNatives(clazz, methods, NELM(methods));
    LOGD("JNI_OnLoad RegisterNatives result:%d", result);
	LOGD("JNI_OnLoad end==");
	return JNI_VERSION_1_6;
}

JNIEXPORT void JNI_OnUnload(JavaVM* vm, void* reserved)
{
	LOGD("JNI_OnUnload start==");
	JNIEnv *env;
	if(vm->GetEnv((void**)&env, JNI_VERSION_1_6) != JNI_OK)
	{
		LOGD("JNI_OnUnload getEnv failed!");
		return;
	}
    jclass clazz = env->FindClass("com/pfg/jnipro/JniCom");
    if(clazz == 0)
    {
    	LOGD("JNI_OnUnload FindClass failed!");
    	return;
    }

    int result = env->UnregisterNatives(clazz);
    LOGD("JNI_OnUnload UnregisterNatives result:%d", result);
	LOGD("JNI_OnUnload end==");
}


#ifdef __cplusplus
}
#endif
#endif

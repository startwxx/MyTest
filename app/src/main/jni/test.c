//
// Created by Administrator on 2016/6/13.
//
#include "com_example_administrator_myapp_JNIS.h"
#include "stdlib.h"

char* _JString2CStr(JNIEnv* env, jstring jstr) {

    char* rtn;
    jclass clsstring = (*env)->FindClass(env, "java/lang/String");
    jstring strencode = (*env)->NewStringUTF(env,"GB2312");
    jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid, strencode); // String .getByte("GB2312");
    jsize alen = (*env)->GetArrayLength(env, barr);
    jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
    if(alen > 0) {
        rtn = (char*)malloc(alen+1);
        memcpy(rtn, ba, alen);
        rtn[alen]=0;
    }
    (*env)->ReleaseByteArrayElements(env, barr, ba,0);
    return rtn;
}

JNIEXPORT jstring JNICALL Java_com_example_administrator_myapp_JNIS_helloJNI
        (JNIEnv * env, jobject jobj) {
    return (*env)->NewStringUTF(env, "Hello from C");
}

JNIEXPORT jintArray JNICALL Java_com_example_administrator_myapp_JNIS_increaseArrayEles
        (JNIEnv * env, jobject obj, jintArray arr) {

    jsize length = (*env)->GetArrayLength(env, arr);
    jint* array = (*env)->GetIntArrayElements(env, arr, JNI_FALSE);
    int i;
    for(i=0;i<length;i++) {
        *(array+i) += 10;
    }
    return arr;
}

JNIEXPORT jstring JNICALL Java_com_example_administrator_myapp_JNIS_checkPwd
        (JNIEnv * env, jobject obj, jstring js){
    char* cs = _JString2CStr(env, js);
    char* pwd = "123456";

    int result = strcmp(cs, pwd);
    if (result == 0) {
        return 200;
    }
    return 400;
}

JNIEXPORT void JNICALL Java_com_example_administrator_myapp_MainActivity_callbackShowToast
        (JNIEnv* env, jobject jobj) {

    jclass class = (*env)->FindClass(env, "com/example/administrator/myapp/MainActivity");

   jmethodID method = (*env)->GetMethodID(env,class,"showToast", "()V");

    (*env)->CallVoidMethod(env,jobj,method);
}
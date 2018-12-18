#include <iostream>
#include "HelloTransfer.h"
#include "jni.h"
#include <string>

std::string jstring2string(JNIEnv *env, jstring jStr) {
	if (!jStr) {
		return "";
	}

	const jclass stringClass = env->GetObjectClass(jStr);
	const jmethodID getBytes = env->GetMethodID(stringClass, "getBytes", "(Ljava/lang/String;)[B");
	const jbyteArray stringJbytes = (jbyteArray)env->CallObjectMethod(jStr, getBytes, env->NewStringUTF("UTF-8"));

	size_t length = (size_t)env->GetArrayLength(stringJbytes);
	jbyte* pBytes = env->GetByteArrayElements(stringJbytes, NULL);

	std::string ret = std::string((char *)pBytes, length);
	env->ReleaseByteArrayElements(stringJbytes, pBytes, JNI_ABORT);

	env->DeleteLocalRef(stringJbytes);
	env->DeleteLocalRef(stringClass);
	return ret;
}

jstring string2jstring(JNIEnv* env, const std::string& value) {
	return env->NewStringUTF(value.c_str());
}

jboolean ToJBool(bool value) {
	return value ? JNI_TRUE : JNI_FALSE;
}

bool ToCppBool(jboolean value) {
	return value == JNI_TRUE;
}

JNIEXPORT void JNICALL Java_HelloTransfer_helloTransfer
(JNIEnv *env, jclass javaClass, jboolean jIsTrue, jint intValue, jlong longValue, jstring jName) {

	long x = intValue;
	std::cout << x << std::flush;
	long y = 1;
	int z = 2;
	std::cout << sizeof(y) << std::flush;
	std::cout << sizeof(z) << std::flush;
	std::cout << (jIsTrue == 1) << std::flush;
	std::cout << jIsTrue << std::flush;
	std::string s = jstring2string(env, jName);
	std::cout << s << std::flush;
	jstring s1 = string2jstring(env, s);
	std::string s2 = jstring2string(env, s1);
	std::cout << s2 << std::flush;

}

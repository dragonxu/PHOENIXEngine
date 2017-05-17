// org_appplay_lib_AppPlayNatives.cpp

#include "org_appplay_lib_AppPlayNatives.h"
#include "AppPlay.hpp"
#include "AppPlayJNI.hpp"
#include <android/log.h>

#ifdef __cplusplus
extern "C"
{
#endif

	jint JNI_OnLoad(JavaVM *vm, void *reserved)
	{	
		appplay::JNIHelper::SetJavaVM(vm);
		
		__android_log_print(ANDROID_LOG_INFO, "appplay.lib", "JNI_OnLoad.");
			
		return JNI_VERSION_1_4;
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeOdle
		(JNIEnv *env, jclass)
	{
		appplay::NativeCall::OnOdle();
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeInit
		(JNIEnv *, jclass, jint width, jint height)
	{
		appplay::NativeCall::Initlize(width, height);
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeOnPause
		(JNIEnv *, jclass)
	{
		appplay::NativeCall::DidEnterBackground();
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeOnResume
		(JNIEnv *, jclass)
	{
		appplay::NativeCall::WillEnterForeground();
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeOnTerm
		(JNIEnv *, jclass)
	{
		appplay::NativeCall::Ternamate();
	}
	
	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeSetApkDataPath
  (JNIEnv *env, jclass, jstring apkPath)
	{
		const char* str;
		jboolean isCopy;
		str = env->GetStringUTFChars(apkPath, &isCopy);
		if (isCopy)
		{
			appplay::NativeCall::SetResourcePath(str);

			env->ReleaseStringUTFChars(apkPath, str);
		}
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeSetDataUpdateServerType
		(JNIEnv *env, jclass, jstring type)
	{
		const char* str;
		jboolean isCopy;
		str = env->GetStringUTFChars(type, &isCopy);
		if (isCopy)
		{
			appplay::NativeCall::SetDataServerUpdateType(str);

			env->ReleaseStringUTFChars(type, str);
		}
	}
	
	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeSetDeviceIDStr
	(JNIEnv *env, jclass, jstring deviceIDStr)
	{
	  	const char* str;
		jboolean isCopy;
		str = env->GetStringUTFChars(deviceIDStr, &isCopy);
		if (isCopy)
		{
			appplay::NativeCall::SetDeviceIDStr(str);

			env->ReleaseStringUTFChars(deviceIDStr, str);
		}
	}
	
	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeIPMac
	(JNIEnv *env, jclass, jstring ip, jstring mac)
	{
		const char* strIP;
		jboolean isCopyIP;
		strIP = env->GetStringUTFChars(ip, &isCopyIP);
		
		const char* strMac;
		jboolean isCopyMac;
		strMac = env->GetStringUTFChars(mac, &isCopyMac);
		
		appplay::NativeCall::SetIPMac(strIP, strMac);
		
		if (isCopyIP)
		{
			env->ReleaseStringUTFChars(ip, strIP);
		}

		if (isCopyMac)
		{
			env->ReleaseStringUTFChars(mac, strMac);
		}
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeTouchPressed
		(JNIEnv *, jclass, jint id, jfloat x, jfloat y)
	{
		appplay::NativeCall::OnTouchPressed(1, &id, &x, &y);
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeTouchReleased
		(JNIEnv *, jclass, jint id, jfloat x, jfloat y)
	{
		appplay::NativeCall::OnTouchReleased(1, &id, &x, &y);
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeTouchMoved
		(JNIEnv *env, jclass, jintArray ids, jfloatArray xs, jfloatArray ys)
	{
		int size = env->GetArrayLength(ids);
		jint id[size];
		jfloat x[size];
		jfloat y[size];

		env->GetIntArrayRegion(ids, 0, size, id);
		env->GetFloatArrayRegion(xs, 0, size, x);
		env->GetFloatArrayRegion(ys, 0, size, y);

		appplay::NativeCall::OnTouchMoved(size, id, x, y);
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeTouchCancelled
		(JNIEnv *env, jclass, jintArray ids, jfloatArray xs, jfloatArray ys)
	{
		int size = env->GetArrayLength(ids);
		jint id[size];
		jfloat x[size];
		jfloat y[size];

		env->GetIntArrayRegion(ids, 0, size, id);
		env->GetFloatArrayRegion(xs, 0, size, x);
		env->GetFloatArrayRegion(ys, 0, size, y);

		appplay::NativeCall::OnTouchCancelled(size, id, x, y);
	}

	JNIEXPORT jboolean JNICALL Java_org_appplay_lib_AppPlayNatives_nativeKeyDown
		(JNIEnv *, jclass, jint)
	{
		return JNI_FALSE;
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeInsertText
		(JNIEnv *env, jclass, jstring text)
	{
		const char* pszText = env->GetStringUTFChars(text, NULL);
		appplay::NativeCall::Text_InsertText(pszText, strlen(pszText));
		env->ReleaseStringUTFChars(text, pszText);
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeDeleteBackward
		(JNIEnv *, jclass)
	{
		appplay::NativeCall::Text_DeleteBackward();
	}

	JNIEXPORT jstring JNICALL Java_org_appplay_lib_AppPlayNatives_nativeGetContentText
		(JNIEnv *env, jclass)
	{
		const char * pszText = appplay::NativeCall::Text_GetInitContent();
		return env->NewStringUTF(pszText);
	}
	
	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeBluetoothOnConnected
		(JNIEnv *, jclass)
	{
		appplay::NativeCall::BluetoothConnected();
	}
	
	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeBluetoothOnDisConnected
		(JNIEnv *, jclass)
	{
		appplay::NativeCall::BluetoothDisConnected();	
	}
	
	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeBluetoothOnConnectFailed
		(JNIEnv *, jclass)
	{
		appplay::NativeCall::BluetoothConnectFailed();	
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeBluetoothDiscoveryNewDevice
		(JNIEnv *env, jclass, jstring strDevice)
	{
		const char* pszText = env->GetStringUTFChars(strDevice, NULL);
		appplay::NativeCall::BluetoothDiscoveryNewDevice(pszText);
		env->ReleaseStringUTFChars(strDevice, pszText);
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeBluetoothDiscoveryFinished
		(JNIEnv *env, jclass)
	{
		appplay::NativeCall::BluetoothDiscoveryFinished();
	}
	
	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeVoiceSetSDK
	(JNIEnv *env, jclass, jstring strPlat)
	{
	  	const char* pszText = env->GetStringUTFChars(strPlat, NULL);
		appplay::NativeCall::SetVoiceSDK(pszText);
		env->ReleaseStringUTFChars(strPlat, pszText);
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeVoiceRecognizeResults
	(JNIEnv *env, jclass, jstring strRet, jstring strJSON)
	{
		const char* pszText = env->GetStringUTFChars(strRet, NULL);
		const char* pszText1 = env->GetStringUTFChars(strJSON, NULL);
		appplay::NativeCall::OnVoiceRecognizeResults(pszText, pszText1);
		env->ReleaseStringUTFChars(strRet, pszText);
		env->ReleaseStringUTFChars(strJSON, pszText1);
	}

#ifdef __cplusplus
}
#endif
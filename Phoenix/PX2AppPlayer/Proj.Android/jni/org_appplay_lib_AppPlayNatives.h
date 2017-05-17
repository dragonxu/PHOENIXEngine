/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_appplay_lib_AppPlayNatives */

#ifndef _Included_org_appplay_lib_AppPlayNatives
#define _Included_org_appplay_lib_AppPlayNatives
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeOdle
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeOdle
  (JNIEnv *, jclass);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeInit
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeInit
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeOnPause
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeOnPause
  (JNIEnv *, jclass);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeOnResume
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeOnResume
  (JNIEnv *, jclass);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeOnTerm
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeOnTerm
  (JNIEnv *, jclass);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeSetApkDataPath
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeSetApkDataPath
  (JNIEnv *, jclass, jstring);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeSetDataUpdateServerType
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeSetDataUpdateServerType
  (JNIEnv *, jclass, jstring);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeSetDeviceIDStr
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeSetDeviceIDStr
  (JNIEnv *, jclass, jstring);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeIPMac
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeIPMac
  (JNIEnv *, jclass, jstring, jstring);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeTouchPressed
 * Signature: (IFF)V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeTouchPressed
  (JNIEnv *, jclass, jint, jfloat, jfloat);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeTouchReleased
 * Signature: (IFF)V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeTouchReleased
  (JNIEnv *, jclass, jint, jfloat, jfloat);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeTouchMoved
 * Signature: ([I[F[F)V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeTouchMoved
  (JNIEnv *, jclass, jintArray, jfloatArray, jfloatArray);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeTouchCancelled
 * Signature: ([I[F[F)V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeTouchCancelled
  (JNIEnv *, jclass, jintArray, jfloatArray, jfloatArray);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeKeyDown
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_appplay_lib_AppPlayNatives_nativeKeyDown
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeInsertText
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeInsertText
  (JNIEnv *, jclass, jstring);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeDeleteBackward
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeDeleteBackward
  (JNIEnv *, jclass);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeGetContentText
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_appplay_lib_AppPlayNatives_nativeGetContentText
  (JNIEnv *, jclass);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeBluetoothOnConnected
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeBluetoothOnConnected
  (JNIEnv *, jclass);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeBluetoothOnDisConnected
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeBluetoothOnDisConnected
  (JNIEnv *, jclass);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeBluetoothOnConnectFailed
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeBluetoothOnConnectFailed
  (JNIEnv *, jclass);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeBluetoothDiscoveryNewDevice
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeBluetoothDiscoveryNewDevice
  (JNIEnv *, jclass, jstring);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeBluetoothDiscoveryFinished
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeBluetoothDiscoveryFinished
  (JNIEnv *, jclass);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeVoiceSetSDK
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeVoiceSetSDK
  (JNIEnv *, jclass, jstring);

/*
 * Class:     org_appplay_lib_AppPlayNatives
 * Method:    nativeVoiceRecognizeResults
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeVoiceRecognizeResults
  (JNIEnv *, jclass, jstring, jstring);

#ifdef __cplusplus
}
#endif
#endif

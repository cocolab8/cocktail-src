/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class ICode */

#ifndef _Included_ICode
#define _Included_ICode
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     ICode
 * Method:    Emit
 * Signature: (III)V
 */
JNIEXPORT void JNICALL Java_ICode_Emit
  (JNIEnv *, jclass, jint, jint, jint);

/*
 * Class:     ICode
 * Method:    EmitReal
 * Signature: (IIF)V
 */
JNIEXPORT void JNICALL Java_ICode_EmitReal
  (JNIEnv *, jclass, jint, jint, jfloat);

/*
 * Class:     ICode
 * Method:    Interpret
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_ICode_Interpret
  (JNIEnv *, jclass);

/*
 * Class:     ICode
 * Method:    WriteCode
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_ICode_WriteCode
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif

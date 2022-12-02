//
// Created by beich on 2020/12/18.
//

#pragma once
#include <jni.h>

#include <fake_linker.h>

namespace fakelinker {
/*
 * @param function_offset   Methods correspond to offsets in JNINativeInterface
 * @param hook_method hook  hook function address
 * @param backup_method backup function out address
 * */
FakeLinkerError HookJniNativeInterface(int function_offset, void *hook_method, void **backup_method);

int HookJniNativeInterfaces(HookJniUnit *items, int len);

int HookJavaNativeFunctions(JNIEnv *env, jclass clazz, HookRegisterNativeUnit *items, size_t len);

bool InitJniFunctionOffset(JNIEnv *env, jclass clazz, jmethodID methodId, void *native, uint32_t flags);
} // namespace fakelinker

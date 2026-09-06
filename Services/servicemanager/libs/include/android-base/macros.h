#ifndef ECALL_ANDROID_BASE_MACROS_H
#define ECALL_ANDROID_BASE_MACROS_H

#include <cutils/compiler.h>

// Branch prediction names used by newer aidl-cpp output.
#define LIKELY(exp) CC_LIKELY(exp)
#define UNLIKELY(exp) CC_UNLIKELY(exp)

#endif

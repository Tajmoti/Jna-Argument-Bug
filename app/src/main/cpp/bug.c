#include <android/log.h>
#include "bug.h"

#define TAG "JNA-BUG-NATIVE"

bool hello(UINT16 argument) {
    __android_log_print(ANDROID_LOG_WARN, TAG, "argument value as %%#010x=%#010x %%d=%d, as %%u=%u, as %%hu=%hu", argument, argument, argument, argument);
    __android_log_print(ANDROID_LOG_WARN, TAG, "CONSTANT value as %%#010x=%#010x %%d=%d, as %%u=%u, as %%hu=%hu", CONSTANT, CONSTANT, CONSTANT, CONSTANT);
    switch (argument) { // NOLINT(hicpp-multiway-paths-covered)
        case CONSTANT:
            return true;
        default:
            return false;
    }
}

bool hello_optimizations_disabled(UINT16 argument) __attribute__ ((optnone)) {
    switch (argument) { // NOLINT(hicpp-multiway-paths-covered)
        case CONSTANT:
            return true;
        default:
            return false;
    }
}

#include "../platform.hpp"

#ifdef GRAPE_PLATFORM_LINUX

// TODO: Linux platform layer.

void Platform::Time_Sleep(const uint32_t milliseconds) {
    if (milliseconds) {
    }
}

GRAPE::SystemTime Platform::Time_GetLocal() {
    return GRAPE::SystemTime{
        .hour = 0,
        .minute = 0,
        .second = 0,
        .millisecond = 0
    };
}

GRAPE::SystemDate Platform::Time_GetDate() {
    return GRAPE::SystemDate{
        .day = 0,
        .month = 0,
        .year = 0,
        .dayOfWeek = 0
    };
}

#endif
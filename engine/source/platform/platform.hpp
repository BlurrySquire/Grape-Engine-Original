#pragma once

#include "../defines.hpp"

#include <string>

namespace GRAPE {
    typedef struct {
        uint8_t hour, minute, second, millisecond;
    } SystemTime;

    typedef struct {
        uint16_t day, month, year, dayOfWeek;
    } SystemDate;
}

class Platform {
public:
    /*
    * @brief Sleeps the current thread for the specified amount of milliseconds.
    * @param const uint64_t: Number of milliseconds to sleep for.
    * @returns Nothing.
    */
    static void Time_Sleep(const uint32_t milliseconds);

    /*
    * @brief Returns the current hour, minute, second and millisecond.
    * @returns SystemTime: the current time
    */
    static GRAPE::SystemTime Time_GetLocalTime();

    /*
    * @brief Returns a struct containing the current day, month, year and day of the week. Day of the week is an int.
    * @returns SystemDate: the current date.
    */
    static GRAPE::SystemDate Time_GetDate();
};
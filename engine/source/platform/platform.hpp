#pragma once

#include "../defines.hpp"

#include <string>

class Platform {
public:
    /*
    * @brief Get the date and time [day/time/month hours:minutes:seconds]
    * @returns std::string: the current date and time.
    */
    static std::string Time_GetLocal();

    // NOTE: THE FOLLOWING FUNCTIONS ARE NOT YET IMPLEMENTED. THEY DO NOTHING.

    // Planning on switching the time functions over to multiple functions.
    static std::string Time_GetDate(bool day_first = true);
    static std::string Time_GetLocalTime(); // Replacement for 'Time_GetLocal'.
    static void Time_Sleep(int milliseconds);
};
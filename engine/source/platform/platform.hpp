#pragma once

#include "../defines.hpp"

#include <iostream>
#include <string>

namespace GRAPE {
    struct SystemTime {
        uint16_t hour, minute, second, millisecond;

        friend std::ostream& operator<<(std::ostream& os, const SystemTime& st) {
            return os << st.hour << ":" << st.minute << ":" << st.second << ":" << st.millisecond;
        }

    };

    struct SystemDate {
        uint16_t day, month, year, dayOfWeek;

        friend std::ostream& operator<<(std::ostream& os, const SystemDate& st) {
            std::string days[7] = {
                "Monday", "Tuesday", "Wednesday",
                "Thursday", "Friday", "Saturday",
                "Sunday"
            };

            return os << days[st.dayOfWeek] << " " << st.day << "." << st.month << "." << st.year;
        }
    };
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
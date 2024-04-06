#pragma once

#include "../defines.hpp"

#include <string>

class Platform {
public:
    static void Console_Write(const std::string& text, uint8_t colour, bool as_error = false);

    static std::string Time_GetLocal();
};
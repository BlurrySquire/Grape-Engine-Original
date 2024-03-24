#pragma once

#include "../defines.hpp"

#include <iostream>
#include <string>

namespace Platform {
    void Init();
    void Close();

    namespace Console {
        GRAPE_API void Write(std::string text, uint8 colour);
        GRAPE_API void WriteError(std::string text, uint8 colour);
    };
};
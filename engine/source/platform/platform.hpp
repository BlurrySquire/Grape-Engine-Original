#pragma once

#include "../defines.hpp"

#include <iostream>
#include <string>

namespace Platform {
    void Init();
    void Close();

    namespace Console {
        void Write(std::string text, uint8 colour);
        void WriteError(std::string text, uint8 colour);
    };
};
#include <grape.hpp>

int main(void) {
    // Create an application
    GRAPE::Application application(L"Grape Engine Sandbox", 1280, 720);

    // Test all the logger message types
    GRAPE_LOG_TRACE("TRACE");
    GRAPE_LOG_DEBUG("DEBUG");
    GRAPE_LOG_INFO("INFO");
    GRAPE_LOG_WARN("WARN");
    GRAPE_LOG_ERROR("ERROR");
    GRAPE_LOG_CRITICAL("CRITICAL\n");

    while (true) {
        // KEEP WINDOW OPEN
    }

    return EXIT_SUCCESS;
}
#include <grape.hpp>
#include <source/platform/platform.hpp> // TEMPORARY

int main(void) {
    // Create an application
    GRAPE::Application application("Grape Engine Sandbox", 1280, 720);

    // Test all the logger message types
    GRAPE_LOG_TRACE("TRACE");
    GRAPE_LOG_DEBUG("DEBUG");
    GRAPE_LOG_INFO("INFO");
    GRAPE_LOG_WARN("WARN");
    GRAPE_LOG_ERROR("ERROR");
    GRAPE_LOG_CRITICAL("CRITICAL\n");

    return EXIT_SUCCESS;
}
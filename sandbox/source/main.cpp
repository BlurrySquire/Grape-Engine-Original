#include <grape.hpp>
#include <source/platform/platform.hpp> // TEMPORARY

int main(void) {
    // Create a logger and give it a file name. (file extension is '.log').
    // The logger creation will be handled by the application layer.
    GRAPE::Logger logger("test");

    // Test all the logger message types
    GRAPE_LOG_TRACE("TRACE");
    GRAPE_LOG_DEBUG("DEBUG");
    GRAPE_LOG_INFO("INFO");
    GRAPE_LOG_WARN("WARN");
    GRAPE_LOG_ERROR("ERROR");
    GRAPE_LOG_CRITICAL("CRITICAL\n");

    GRAPE_LOG_INFO("Sleeping for 1000ms (1 second)\n");

    // Sleep for 1 second
    Platform::Time_Sleep(1000);

    // Print the date and time
    GRAPE::SystemDate date = Platform::Time_GetDate();
    GRAPE::SystemTime time = Platform::Time_GetLocal();

    GRAPE_LOG_INFO(date);
    GRAPE_LOG_INFO(time);

    return EXIT_SUCCESS;
}
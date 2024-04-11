#include <grape.hpp>

int main(void) {
    // Create a logger and give it a file name (default: 'grape_log.txt')
    GRAPE::Logger logger("test");
    
    // Test all the logger message types
    GRAPE_LOG_TRACE("TRACE");
    GRAPE_LOG_DEBUG("DEBUG");
    GRAPE_LOG_INFO("INFO");
    GRAPE_LOG_WARN("WARN");
    GRAPE_LOG_ERROR("ERROR");
    GRAPE_LOG_CRITICAL("CRITICAL");

    return EXIT_SUCCESS;
}
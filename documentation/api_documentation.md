# Grape Engine Docs - API
- [Return to README](https://github.com/BlurrySquire/Grape-Engine)
- [Return to Documentation](https://github.com/BlurrySquire/Grape-Engine/blob/main/documentation/documentation.md)

This area is a work in progress. Not everything will be documented at this point.

## Using the Logger
```c++
#include <grape.hpp>

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

    return EXIT_SUCCESS;
}
```

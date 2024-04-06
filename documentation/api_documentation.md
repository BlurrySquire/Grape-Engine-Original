# Grape Engine Docs - API
- [Return to README](https://github.com/BlurrySquire/Grape-Engine)
- [Return to Documentation](https://github.com/BlurrySquire/Grape-Engine/blob/main/documentation/documentation.md)

This area is a work in progress. Not everything will be documented at this point.

## Using the Logger
NOTE: Every 5 logger messages it will write them to a file. If you want to write some log messages to the log file before there is 5 messages in the backlog then you can use ``logger.WriteBacklog()``. This will write all messages in the backlog to the file. If you want to clear the messages from the backlog without writing them to the file then you can use ``logger.ClearBacklog()``. I made the ``logger.WriteBacklog()`` function a public method of the logger class so that if your application needed to crash or close then you can ensure the last few log messages are written to the file. The function is also called as part of the logger's destructor so when the application closes normally you won't lose the last few log messages.
```c++
#include <core/logger.hpp>

int main(void) {
    // Create a logger and give it a file name (default: 'grape_log.txt')
    Logger logger("test.txt");
    
    // Test all the logger message types
    logger.Fatal("Fatal test.\n");
    logger.Error("Error test.\n");
    logger.Warn("Warn test.\n");
    logger.Info("Info test.\n");
    logger.Debug("Debug test.\n");
    logger.Trace("Trace test.\n");

    return EXIT_SUCCESS;
}
```
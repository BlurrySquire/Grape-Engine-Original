#include <defines.hpp>
#include <core/logger.hpp>

int main(void)
{
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
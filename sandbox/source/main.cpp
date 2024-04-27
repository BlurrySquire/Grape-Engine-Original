#include <grape.hpp>

int main(void) {
    GRAPE::AppInfo app_info = {
        .win_title = "Grape-Engine Sandbox",
        .win_width = 1280,
        .win_height = 720,
        .resizable = false
    };

    GRAPE::Application application(app_info);

    int width, height = 0;
    application.GetWinSize(&width, &height);

    std::string title = application.GetWinTitle();

    GRAPE_LOG_INFO(
        "Window Title: \"{0}\"",
        title
    );

    GRAPE_LOG_INFO(
        "Window Size: {0}x{1}",
        width, height
    );

    application.Run();

    return EXIT_SUCCESS;
}
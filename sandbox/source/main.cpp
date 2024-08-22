#include <grape.hpp>

class Sandbox : public GRAPE::Application {
public:
    using GRAPE::Application::Application;
    using GRAPE::Application::Run;

    void Init() override {
        GRAPE_LOG_INFO("Sandbox: Initialised.");
        Run();
    }

    ~Sandbox() {

    }

    void Update() override {

    }

    void Render() override {

    }

    void OnWindowClose() override {
        GRAPE_LOG_INFO("Hello.");
        //CloseApplication();
    }
};

int main(void) {
    Sandbox sandbox("Sandbox", 800, 600);
    return EXIT_SUCCESS;
}
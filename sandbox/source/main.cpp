#include <grape.hpp>

class Sandbox : public GRAPE::Application {
public:
    using GRAPE::Application::Application;
    using GRAPE::Application::Run;

    ~Sandbox() {

    }

    void Init() override {
        GRAPE_LOG_INFO("Sandbox: Initialised.");
    }

    void Update() override {

    }

    void Render() override {

    }

    void OnWindowClose() override {
        GRAPE_LOG_INFO("Sandbox: Received 'Window Close' event.");
        CloseApplication();
    }
};

int main(void) {
    GRAPE::Init();

    Sandbox sandbox("Sandbox", 800, 600);

    sandbox.Init();
    sandbox.Run();

    return EXIT_SUCCESS;
}
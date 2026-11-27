#include "windows_app_factory.hpp"

using namespace biv;

WindowsControlSettings* WindowsAppFactory::create_control_settings(int /*map_height*/, int /*map_weight*/) {
    return new WindowsControlSettings();
}

WindowsKeyBoard* WindowsAppFactory::create_keyboard() {
    return new WindowsKeyBoard();
}

ConsoleUIFactory* WindowsAppFactory::create_ui_factory(Game* game) {
    return new ConsoleUIFactory(game);
}

std::chrono::milliseconds WindowsAppFactory::create_frame_delay() noexcept {
    return std::chrono::milliseconds{30};
}
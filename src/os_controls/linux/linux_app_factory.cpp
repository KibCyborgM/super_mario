#include <ncurses.h>

#include "linux_app_factory.hpp"

using namespace biv;

LinuxControlSettings* LinuxAppFactory::create_control_settings(int map_height, int map_weight) {
    return new LinuxControlSettings(map_height, map_weight);
}

LinuxKeyBoard* LinuxAppFactory::create_keyboard() {
    return new LinuxKeyBoard();
}

ConsoleUIFactory* LinuxAppFactory::create_ui_factory(Game* game) {
    return new ConsoleUIFactory(game);
}

std::chrono::milliseconds LinuxAppFactory::create_frame_delay() noexcept {
    return std::chrono::milliseconds{30};
}
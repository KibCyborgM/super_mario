#pragma once

#include "app_factory.hpp"
#include "windows_control_settings.hpp"
#include "windows_keyboard.hpp"
#include "console_ui_factory.hpp"

namespace biv {
    class WindowsAppFactory : public AppFactory {
    public:
        WindowsControlSettings* create_control_settings(int map_height, int map_weight) override;
        WindowsKeyBoard* create_keyboard() override;
        ConsoleUIFactory* create_ui_factory(Game* game) override;
        std::chrono::milliseconds create_frame_delay() noexcept override;
    };
}

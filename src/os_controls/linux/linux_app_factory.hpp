#pragma once

#include "app_factory.hpp"
#include "console_ui_factory.hpp"
#include "linux_control_settings.hpp"
#include "linux_keyboard.hpp"

namespace biv {
	class LinuxAppFactory : public  AppFactory{
        public:
            LinuxControlSettings* create_control_settings(const int map_height, const int map_weight) override;
            LinuxKeyBoard* create_keyboard() override;
            ConsoleUIFactory* create_ui_factory(Game* game) override;
            std::chrono::milliseconds create_frame_delay() noexcept override;
	};
}
#pragma once

#include <chrono>

#include "game.hpp"
#include "os_control_settings.hpp"
#include "keyboard.hpp"
#include "ui_factory.hpp"

namespace biv {
	class AppFactory {
        public:
            AppFactory() = default;

            virtual OSControlSettings* create_control_settings(const int map_height, const int map_weight) = 0;
            virtual KeyBoard* create_keyboard() = 0;
            virtual UIFactory* create_ui_factory(Game* game) = 0;
            virtual std::chrono::milliseconds create_frame_delay() = 0;

            virtual ~AppFactory() = default;
	};
}
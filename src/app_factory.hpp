#pragma once

#include <chrono>

#include "game.hpp"
#include "os_control_settings.hpp"
#include "keyboard.hpp"
#include "ui_factory.hpp"

namespace biv {
	class AppFactory {
        public:
            OSControlSettings* control_settings = nullptr;
	        KeyBoard* keyboard = nullptr;
            UIFactory* ui_factory = nullptr;
            std::chrono::milliseconds frame_delay{0};

		
			AppFactory() = delete;
            AppFactory(Game* game, const int map_height, const int map_weight);

            ~AppFactory();



	};
}
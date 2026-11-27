#pragma once

#include "app_factory.hpp"
#include "game.hpp"
#include "qt_control_settings.hpp"
#include "qt_keyboard.hpp"
#include "qt_ui_factory.hpp"

namespace biv {
	class QtAppFactory : public  AppFactory{
        public:
            QtControlSettings* create_control_settings(const int map_height, const int map_weight) override;
            QtKeyBoard* create_keyboard() override;
            QtUIFactory* create_ui_factory(Game* game) override;
            std::chrono::milliseconds create_frame_delay() noexcept override;
	};
}
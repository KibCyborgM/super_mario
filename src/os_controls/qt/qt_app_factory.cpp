#include "qt_app_factory.hpp"

using namespace biv;

QtControlSettings* QtAppFactory::create_control_settings(int /*map_height*/, int /*map_weight*/) {
    return new QtControlSettings();
}

QtKeyBoard* QtAppFactory::create_keyboard() {
    return new QtKeyBoard();
}

QtUIFactory* QtAppFactory::create_ui_factory(Game* game) {
    return new QtUIFactory(game);
}

std::chrono::milliseconds QtAppFactory::create_frame_delay() noexcept {
    return std::chrono::milliseconds{30};
}
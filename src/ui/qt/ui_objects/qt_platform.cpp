#include "qt_platform.hpp"

namespace biv {
    QtPlatform::QtPlatform(const Coord& top_left, int width, int height)
        : Rect(top_left, width, height),
          MovableCollisionable(top_left, width, height, 0.0f, 0.1f),
          Platform(top_left, width, height) {}

    QtSprite QtPlatform::get_sprite() const noexcept {
        return QtSprite::PLATFORM;
    }
}

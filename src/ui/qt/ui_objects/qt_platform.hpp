#pragma once
#include "platform.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace biv {
    class QtPlatform final : public Platform, public QtUIObjectRectAdapter {
        public:
            QtPlatform(const Coord& top_left, int width, int height);
            QtSprite get_sprite() const noexcept override;
    };
}

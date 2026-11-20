#pragma once

#include "qt_ui_obj_rect_adapter.hpp"
#include "enemy.hpp"

namespace biv {
	class QtEnemy final : public Enemy, public QtUIObjectRectAdapter {
		public:
			QtEnemy(const Coord& top_left, const int width, const int height);

			QtSprite get_sprite() const noexcept override;
			bool is_visible() const noexcept override;
	};
}

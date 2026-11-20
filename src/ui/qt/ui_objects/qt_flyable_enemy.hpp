#pragma once

#include "qt_ui_obj_rect_adapter.hpp"
#include "flyable_enemy.hpp"

namespace biv {
	class QtFlyableEnemy final : public FlyableEnemy, public QtUIObjectRectAdapter {
		public:
			QtFlyableEnemy(const Coord& top_left, const int width, const int height);

			QtSprite get_sprite() const noexcept override;
	};
}

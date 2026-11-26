#pragma once

#include "qt_ui_obj_rect_adapter.hpp"
#include "heal_kit.hpp"

namespace biv {
	class QtHealKit final : public HealKit, public QtUIObjectRectAdapter {
		public:
			QtHealKit(const Coord& top_left, const int width, const int height);

			QtSprite get_sprite() const noexcept override;
			bool is_visible() const noexcept override;
	};
}
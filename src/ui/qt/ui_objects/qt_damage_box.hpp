#pragma once

#include "qt_ui_obj_rect_adapter.hpp"
#include "damage_box.hpp"

namespace biv {
	class QtDamageBox final : public DamageBox, public QtUIObjectRectAdapter {
		public:
			QtDamageBox(const Coord& top_left, const int width, const int height);

			QtSprite get_sprite() const noexcept override;
			bool is_visible() const noexcept override;
	};
}
#pragma once

#include "qt_ui_obj_rect_adapter.hpp"
#include "money.hpp"

namespace biv {
	class QtMoney final : public Money, public QtUIObjectRectAdapter {
		public:
			QtMoney(const Coord& top_left, const int width, const int height);

			QtSprite get_sprite() const noexcept override;
			bool is_visible() const noexcept override;
	};
}

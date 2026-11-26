#pragma once

#include "console_ui_obj_rect_adapter.hpp"
#include "damage_box.hpp"

namespace biv {
	class ConsoleDamageBox : public DamageBox, public ConsoleUIObjectRectAdapter {
		public:
			ConsoleDamageBox(const Coord& top_left, const int width, const int height);

			char get_brush() const noexcept override;
	};
}
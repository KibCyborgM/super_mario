#pragma once

#include "qt_ui_obj_rect_adapter.hpp"
#include "full_box.hpp"

namespace biv {
	class QtFullBox final : public FullBox, public QtUIObjectRectAdapter {
		public:
			QtFullBox(
				const Coord& top_left, 
				const int width, const int height,
				UIFactory* ui_factory
			);
			
			QtSprite get_sprite() const noexcept override;
	};
}

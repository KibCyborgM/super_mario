#pragma once

#include "console_ui_obj_rect_adapter.hpp"
#include "movable_collisionable.hpp"

namespace biv {
	class ConsoleUIObjectMovColAdapter : virtual public MovableCollisionable, public ConsoleUIObjectRectAdapter  {
		public:
			ConsoleUIObjectMovColAdapter() = default;
			ConsoleUIObjectMovColAdapter(
				const Coord& top_left, const int width, const int height
			);
		

			
			virtual char get_brush() const noexcept = 0;
	};
}
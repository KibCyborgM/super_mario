#pragma once

#include "collisionable.hpp"
#include "rect_map_movable_adapter.hpp"
#include "movable.hpp"

namespace biv {
	class Platform : public Collisionable, public RectMapMovableAdapter, public Movable {
		public:
			Platform(
				const Coord& top_left, const int width, const int height
			);

            Rect get_rect() const noexcept override;
			Speed get_speed() const noexcept override;

           void process_horizontal_static_collision(Rect*) noexcept override;
           void process_mario_collision(Collisionable*) noexcept override;
		   void process_vertical_static_collision(Rect*) noexcept override;
	};
}

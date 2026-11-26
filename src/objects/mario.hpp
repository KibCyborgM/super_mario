#pragma once

#include "collisionable.hpp"
#include "movable.hpp"
#include "rect.hpp"
#include "speed.hpp"

namespace biv {
	class Mario : public Movable, public Collisionable {
		private:
			int hp = 1;
		public:
			Mario(const Coord& top_left, const int width, const int height);

			Rect get_rect() const noexcept override;
			Speed get_speed() const noexcept override;

			
			
			void move_map_left() noexcept;
			void move_map_right() noexcept;

			int get_hp() const noexcept;

			void process_horizontal_static_collision(Rect*) noexcept override;
			void process_mario_collision(Collisionable*) noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override;
			void process_vertical_platform_collision(Movable*) noexcept override;
	};
}

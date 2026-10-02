#pragma once

#include "collisionable.hpp"
#include "console_game_map.hpp"
#include "movable.hpp"
#include "rect.hpp"
#include "rect_map_movable_adapter.hpp"
#include "speed.hpp"

namespace biv {
	class FlyableEnemy : public RectMapMovableAdapter, public Movable, public Collisionable {
		protected:
			ConsoleGameMap* game_map = nullptr;

		public:
			FlyableEnemy(const Coord& top_left, const int width, const int height, const ConsoleGameMap* game_map);

			Rect get_rect() const noexcept override;
			Speed get_speed() const noexcept override;

			void process_horizontal_static_collision(Rect*) noexcept override;
			void process_mario_collision(Collisionable*) noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override;
	};
}
#pragma once

#include "movable.hpp"
#include "rect.hpp"
#include "speed.hpp"

namespace biv {
	class Collisionable {
		protected:
			bool is_active_ = true;
			bool on_platform = false;

		public:
            virtual ~Collisionable() = default;
			bool has_collision(Rect*) const noexcept;
			bool is_active() const noexcept;
			void kill() noexcept;
			virtual void take_damage(const int damage) noexcept;
			virtual void heal() noexcept;

			virtual Rect get_rect() const noexcept = 0;
			virtual Speed get_speed() const noexcept = 0;

			virtual void process_horizontal_static_collision(Rect*) noexcept = 0;
			virtual void process_mario_collision(Collisionable*) noexcept = 0;
			virtual void process_vertical_static_collision(Rect*) noexcept = 0;
			virtual void process_vertical_platform_collision(Movable*) noexcept = 0;
	};
}

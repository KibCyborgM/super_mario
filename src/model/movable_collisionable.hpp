#pragma once

#include "movable.hpp"
#include "collisionable.hpp"

namespace biv {
	class MovableCollisionable : public Movable, public Collisionable {
		public:
			MovableCollisionable(const Coord& top_left, const int width, const int height,
                                float vspeed, float hspeed
            );

            Rect get_rect() const noexcept override;
            
            float get_hspeed();
            float get_vspeed();
			
			
	};
}
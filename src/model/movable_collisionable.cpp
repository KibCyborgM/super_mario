#include "movable_collisionable.hpp"

using biv::MovableCollisionable;

MovableCollisionable::MovableCollisionable(const Coord& top_left, const int width, const int height,
                                float vspeed, float hspeed
            ) {
	this->top_left = top_left;
	this->width = width;
	this->height = height;
    this->vspeed = vspeed;
    this->hspeed = hspeed;
}

biv::Rect MovableCollisionable::get_rect() const noexcept {
	return {top_left, width, height};
}

float MovableCollisionable::get_hspeed() {
    return hspeed;
}

float MovableCollisionable::get_vspeed() {
    return vspeed;
}
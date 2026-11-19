#include "platform.hpp"

using biv::Platform;

Platform::Platform(const Coord& top_left, const int width, const int height) 
	: MovableCollisionable(top_left, width, height, 0.0f, 0.2f),
		RectMapMovableAdapter(top_left, width, height) {
	vspeed = 0;
	hspeed = 0.1;
    flyable = true;
}


biv::Rect Platform::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed Platform::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void Platform::process_horizontal_static_collision(Rect* obj) noexcept {
    hspeed = -hspeed;
	move_horizontally();
}

void Platform::process_mario_collision(Collisionable* mario) noexcept {
	// if (mario->get_speed().v > 0 && mario->get_speed().v != V_ACCELERATION) {
	// 	kill();
	
}

void Platform::process_vertical_static_collision(Rect* obj) noexcept {}

void Platform::process_vertical_platform_collision(Movable* obj) noexcept {}
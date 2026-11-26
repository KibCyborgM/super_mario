#include "heal_kit.hpp"

#include "map_movable.hpp"

using biv::HealKit;

HealKit::HealKit(const Coord& top_left, const int width, const int height) 
	: RectMapMovableAdapter(top_left, width, height) {
	vspeed = 0;
	hspeed = 0.2;
}

biv::Rect HealKit::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed HealKit::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void HealKit::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();
}

void HealKit::process_mario_collision(Collisionable* mario) noexcept {
	mario->heal();
	kill();
}

void HealKit::process_vertical_static_collision(Rect* obj) noexcept {
	// Деньги могут свалиться с корабля: Кто не поймал, тот не успел. 
	
	// Особенность модели вертикального передвижения в игре.
	if (vspeed > 0) {
		top_left.y -= vspeed;
		vspeed = 0;
	}
}

void HealKit::process_vertical_platform_collision(Movable* obj) noexcept {
	if (vspeed > 0) {
		top_left.y -= vspeed;
		vspeed = 0;
	}

    top_left.x += obj->get_hspeed();
}

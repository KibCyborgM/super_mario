#include "jumpable_enemy.hpp"

#include "map_movable.hpp"

using biv::JumpableEnemy;

JumpableEnemy::JumpableEnemy(const Coord& top_left, const int width, const int height) 
	: RectMapMovableAdapter(top_left, width, height) {
	vspeed = 0.2;
	hspeed = 0;
}

biv::Rect JumpableEnemy::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed JumpableEnemy::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void JumpableEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();
}

void JumpableEnemy::process_mario_collision(Collisionable* mario) noexcept {
	if (mario->get_speed().v > 0 && mario->get_speed().v != V_ACCELERATION) {
		kill();
	} else {
		mario->take_damage();
	}
}

void JumpableEnemy::process_vertical_static_collision(Rect* obj) noexcept {
	// Особенность модели вертикального передвижения в игре.
	if (vspeed > 0) {
		top_left.y -= vspeed;
		vspeed = 0;
		jump();
	}
}

void JumpableEnemy::process_vertical_platform_collision(Movable* obj) noexcept {
	if (vspeed > 0) {
		top_left.y -= vspeed;
		vspeed = 0;
		jump();
	}
}
#include "flyable_enemy.hpp"

#include "map_movable.hpp"

using biv::FlyableEnemy;

FlyableEnemy::FlyableEnemy(const Coord& top_left, const int width, const int height, const ConsoleGameMap* game_map) 
	: RectMapMovableAdapter(top_left, width, height) {
	vspeed = 0.2;
	hspeed = 0.2;
	flyable = true;
	game_map = game_map;
}

biv::Rect FlyableEnemy::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed FlyableEnemy::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void FlyableEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();
}

void FlyableEnemy::process_mario_collision(Collisionable* mario) noexcept {
	if (mario->get_speed().v > 0 && mario->get_speed().v != V_ACCELERATION) {
		kill();
	} else {
		mario->kill();
	}
}

void FlyableEnemy::process_vertical_static_collision(Rect* obj) noexcept {
	vspeed = -vspeed;
    move_vertically();

}

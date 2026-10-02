#include "console_flyable_enemy.hpp"

using biv::ConsoleFlyableEnemy;

ConsoleFlyableEnemy::ConsoleFlyableEnemy(const Coord& top_left, const int width, const int height, const ConsoleGameMap* game_map) 
	: FlyableEnemy(top_left, width, height, game_map) {}

char ConsoleFlyableEnemy::get_brush() const noexcept {
	return 'e';
}

#include "qt_flyable_enemy.hpp"

using biv::QtFlyableEnemy;

QtFlyableEnemy::QtFlyableEnemy(const Coord& top_left, const int width, const int height) 
	: Rect(top_left, width, height),
      FlyableEnemy(top_left, width, height) {}

biv::QtSprite QtFlyableEnemy::get_sprite() const noexcept {
	return QtSprite::FLYABLE_ENEMY;
}
